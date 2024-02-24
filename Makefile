###############################################################################
###############################################################################

NAME			=			cub3d

###############################################################################
###############################################################################

CC				=			cc
CFLAGS			=			-MMD -MP #-Wall -Werror -Wextra
MINILIB_FLAG	=
HEADERS			=			-I./include -I./libs/include
LIBS			=			./libs
LIBS_NAME		=			./libs/libs.a

###############################################################################
###############################################################################

MLX_LIB			=			./MLX42/build/libmlx42.a
MLX42_OS		:=			$(shell uname)

ifeq ($(MLX42_OS), Darwin)
	MLX = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else ifeq ($(MLX42_OS), Linux)
	MLX = -ldl -lglfw -pthread -lm
endif

###############################################################################
###############################################################################

VPATH			=	./src:./src/minimap:./src/hooks:./src/init:./src/exit:./src/raycaster:./src/render

SRC_MAIN		:=	cub3d.c
SRC_MINIMAP		:=	line.c render.c
SRC_HOOKS		:=	key_hook.c
SRC_INIT		:=	init.c
SRC_EXIT		:=	exit.c
SRC_RAYCASTER	:=	raycaster.c math_utils.c horizontal.c vertical.c
SRC_RENDER		:=	render_wall.c
SOURCE			:=	$(SRC_MAIN) $(SRC_MINIMAP) $(SRC_HOOKS) $(SRC_INIT) $(SRC_EXIT) \
					$(SRC_RAYCASTER) $(SRC_RENDER)

###############################################################################
###############################################################################

OBJ_DIR			:=	./_obj
OBJ				:=	$(addprefix $(OBJ_DIR)/, $(SOURCE:%.c=%.o))
DEP				= $(OBJ:%.o=%.d)

###############################################################################
###############################################################################

all : $(NAME)

-include $(DEP)

$(NAME): $(LIBS_NAME) $(OBJ)
	@echo $(YELLOW)Compiling [$(NAME)]...$(RESET)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJ) $(LIBS_NAME) $(MLX_LIB) $(MLX) -o $(NAME) $(EXTRA_FLAGS)
	@echo $(GREEN)Finished"  "[$(NAME)]...$(RESET)

$(OBJ_DIR)/%.o: %.c
	@echo $(YELLOW)Compiling [$@]...$(RESET)
	@if [ ! -d "${OBJ_DIR}" ]; then											\
		mkdir -p _obj;														\
	fi
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@
	@printf $(UP)$(CUT)

$(LIBS_NAME):
	@git submodule update --remote --init -q
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@$(MAKE) -C $(LIBS) -B

###############################################################################
###############################################################################

clean:
	@if [ -d "${OBJ_DIR}" ]; then							\
			$(MAKE) -C ./libs clean;						\
			echo $(RED)Cleaning"  "[$(OBJ_DIR)]...$(RESET);	\
			rm -rf ${OBJ_DIR};								\
			echo $(GREEN)Cleaned!$(RESET);					\
	fi

###############################################################################
###############################################################################

fclean: clean
		@if [ -f "$(NAME)" ]; then								\
				$(MAKE) -C ./libs fclean;						\
				echo $(RED)Cleaning"  "[$(NAME)]...$(RESET);	\
				rm -f $(NAME);									\
				echo $(GREEN)Cleaned!$(RESET);					\
		fi

re: fclean all

###############################################################################
###############################################################################

.PHONY : clean fclean all re

###############################################################################
###############################################################################
YELLOW := "\033[33m"
RED := "\033[31m"
GREEN := "\033[32m"
RESET := "\033[0m"
UP := "\033[A"
CUT := "\033[K"

