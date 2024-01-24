###############################################################################
###############################################################################

NAME			=			cub3d

###############################################################################
###############################################################################

CC				=			cc
CFLAGS			=			-Wall -Werror -Wextra -fsanitize=address -g
HEADERS			=			-I./include -I./libs/include
LIBS			=			./libs
LIBS_NAME		=			./libs/libs.a

###############################################################################
###############################################################################

MLX_LIB			=			./MLX42/build/libmlx42.a
MLX42_OS		:=			$(shell uname)OS := $(shell uname)
ifeq ($(MLX42_OS), Darwin)
	MLX = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else ifeq ($(MLX42_OS), Linux)
	MLX = -ldl -lglfw -pthread -lm
endif

###############################################################################
###############################################################################

VPATH			=	src src/parsing/input_parsing							\
					src/parsing/file_parsing								\
					src/parsing/indicator_functions

SRC_MAIN		:=	cub3d.c
SRC_INPUT_PARS	:=	get_input.c pars_input.c
SRC_FILE_PARS	:=	file_parsing.c 											\
					texture_check.c replace_newline_with_null_terminator.c	\
					color_check.c numbers_in_rgb_range_check.c				\
					detect_garbage.c map_check.c map_line_check.c
SRC_INDUCATOR	:=	is_texture.c all_indicators_got_found.c					\
					is_color_indicator.c is_map_indicator.c is_newline.c
SOURCE			:=	$(SRC_MAIN) $(SRC_INPUT_PARS) $(SRC_FILE_PARS)			\
					$(SRC_INDUCATOR)


###############################################################################
###############################################################################

OBJ_DIR			:=	./_obj
OBJ				:=	$(addprefix $(OBJ_DIR)/, $(SOURCE:%.c=%.o))

###############################################################################
###############################################################################

all : $(NAME)

$(NAME): $(LIBS_NAME) $(OBJ)
	@echo $(YELLOW)Compiling [$(NAME)]...$(RESET)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS_NAME) $(MLX_LIB) $(MLX) -o $(NAME) $(EXTRA_FLAGS)
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

