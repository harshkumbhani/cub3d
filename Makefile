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
MLX42_OS		:=			$(shell uname)

ifeq ($(MLX42_OS), Darwin)
	MLX = -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
else ifeq ($(MLX42_OS), Linux)
	MLX = -ldl -lglfw -pthread -lm
endif

###############################################################################
###############################################################################

VPATH			=	src src/input_handling src/parsing/file_parsing			\
					src/indicator_functions src/error_handling				\
					src/parsing/get_file_content src/valide_map_check		\
					src/set_up_structs src/map_manipulation					\
					src/free_structs

SRC_MAIN		:=	cub3d.c
SRC_HANDL_INPUT	:=	parse_input.c
SRC_SET_UP_STR	:=	set_up_parser_struct.c set_up_game_struct.c
SRC_FILE_PARS	:=	file_parsing.c 											\
					texture_check.c replace_newline_with_null_terminator.c	\
					color_check.c numbers_in_rgb_range_check.c				\
					detect_garbage.c map_syntax_check.c map_line_check.c
SRC_INDUCATOR	:=	is_texture.c all_indicators_got_found.c					\
					is_color_indicator.c is_map_indicator.c is_newline.c	\
					is_player.c
SRC_ERROR		:=	parser_error.c
SRC_GET_CONTENT	:=	get_file_content.c save_colors.c save_map_in_struct.c	\
					save_map_line.c save_texture_path.c
SRC_VALIDE_MAP	:=	valide_map_check.c										\
					check_for_spaces_in_map.c flood_fill_spaces.c
SRC_MAP_MANIPUL	:=	get_longest_line_in_map.c								\
					copy_map_with_two_extra_lines.c							\
					get_number_of_map_rows.c fill_map_with_aligned_lines.c	\
					add_string_at_top_and_bottom.c							\
					create_string_of_spaces.c fill_enum_map.c				\
					enum_map_allocation.c
SRC_FREE_STR	:=	free_structs.c

SOURCE			:=	$(SRC_MAIN) $(SRC_HANDL_INPUT) $(SRC_FILE_PARS)			\
					$(SRC_INDUCATOR) $(SRC_ERROR) $(SRC_GET_CONTENT)		\
					$(SRC_VALIDE_MAP) $(SRC_SET_UP_STR) $(SRC_MAP_MANIPUL)	\
					$(SRC_FREE_STR)

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
	@cd MLX42 && cmake -B build > /dev/null 2>&1 && cmake --build build -j4 > /dev/null 2>&1
	@echo $(YELLOW)Compiling [MLX42]...$(RESET)
	@echo $(GREEN)Finished"  "[libmlx42.a]...$(RESET)
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

