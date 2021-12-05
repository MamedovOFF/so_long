NAME			= so_long

SRCS			= so_long.c $(SRC_GNL) ./src/map_read.c ./src/key_hook.c ./src/render.c ./src/img_fill.c \
				./src/map_check.c ./bonus/itoa.c

SRCS_B			=  	./bonus/so_long_bonus.c $(SRC_GNL) ./src/map_read.c ./src/key_hook.c ./bonus/render_bonus.c ./src/img_fill.c \
                    ./bonus/map_check_bonus.c ./bonus/itoa.c

HEADER			= so_long.h

GNL = get_next_line.c get_next_line_utils.c

SRC_GNL = $(addprefix gnl/, $(GNL))

OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc


MLX 			= libmlx.dylib -framework OpenGL -framework AppKit

RM				= @rm -f

FLAGS			= -Wall -Wextra -Werror

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJ) $(HEADER)
				$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC)  -Wall -Wextra -Werror -I${HEADER} -c $< -o $@

bonus:
				make OBJ="$(OBJ_B)" all

clean:
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)