NAME = checker

NAME2 = push_swap

CHECKER_NAME = checker.c

PUSH_SWAP_NAME = push_swap.c

COMMUN_NAME = operation_fc.c \
				checker_ps.c \
				operate.c \
				error_gest.c \
				print_stack.c \
				operation_fc1.c


INC_PATH = ./includes/
CHECKER_PATH = ./srcs/checker/
PUSH_SWAP_PATH = ./srcs/push_swap/
COMMUN_PATH = ./srcs/commun/
OBJ_PUSH_SWAP_PATH = ./obj_push_swap/
OBJ_CHECKER_PATH = ./obj_checker/
OBJ_COMMUN_PATH = ./obj_commun/
LIB_PATH = ./libft/
LIB_NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ_NAME_CHECKER = $(CHECKER_NAME:.c=.o)
OBJ_NAME_PUSH_SWAP = $(PUSH_SWAP_NAME:.c=.o)
OBJ_NAME_COMMUN = $(COMMUN_NAME:.c=.o)
OBJ_CHECKER = $(addprefix $(OBJ_CHECKER_PATH),$(OBJ_NAME_CHECKER))
OBJ_PUSH_SWAP = $(addprefix $(OBJ_PUSH_SWAP_PATH),$(OBJ_NAME_PUSH_SWAP))
OBJ_COMMUN = $(addprefix $(OBJ_COMMUN_PATH),$(OBJ_NAME_COMMUN))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))
INC = $(addprefix -I,$(INC_PATH))

all:$(NAME)

$(NAME): $(OBJ_CHECKER) $(OBJ_COMMUN) $(NAME2) libf
	$(CC) $(CFLAGS) $(OBJ_CHECKER) $(OBJ_COMMUN) $(LIB) $(INC) -o $@

$(OBJ_CHECKER_PATH)%.o:$(CHECKER_PATH)%.c
	@mkdir -p $(OBJ_CHECKER_PATH)
	$(CC) -c $< -o $@

$(NAME2): $(OBJ_PUSH_SWAP) $(OBJ_COMMUN) libf
		$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) $(OBJ_COMMUN) $(LIB) $(INC) -o $@

$(OBJ_PUSH_SWAP_PATH)%.o:$(PUSH_SWAP_PATH)%.c
	@mkdir -p $(OBJ_PUSH_SWAP_PATH)
	$(CC) -c $< -o $@

$(OBJ_COMMUN_PATH)%.o:$(COMMUN_PATH)%.c
	@mkdir -p $(OBJ_COMMUN_PATH)
	$(CC) -c $< -o $@

libf:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) fclean
	rm -rf $(OBJ_COMMUN_PATH)
	rm -rf $(OBJ_CHECKER_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
