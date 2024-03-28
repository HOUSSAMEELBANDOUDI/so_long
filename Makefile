NAME = s_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
RM = rm -rf

SRC = $(SRC_DIR)commands/push.c $(SRC_DIR)commands/rev_rotate.c \
      $(SRC_DIR)commands/rotate.c $(SRC_DIR)commands/swap.c \
      $(SRC_DIR)push_swap/from_b_to_a.c $(SRC_DIR)push_swap/sort_stack.c \
      $(SRC_DIR)push_swap/sort_three.c $(SRC_DIR)push_swap/sort_utils.c \
      $(SRC_DIR)push_swap/ft_split.c $(SRC_DIR)push_swap/add_stack.c \
      $(SRC_DIR)push_swap/free_error.c $(SRC_DIR)push_swap/push_swap.c \
      $(SRC_DIR)push_swap/stack_utils.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking objects into $@"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

srcs/%.o: srcs/%.c $(INC_DIR)push_swap.h
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@$(RM) $(OBJ) 

fclean: clean
	@echo "Cleaning executables"
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus