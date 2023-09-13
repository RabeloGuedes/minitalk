NAME = minitalk
SERVER = $(SRC_DIR)/server
CLIENT = $(SRC_DIR)/client
B_SERVER = $(SRC_DIR)/server_bonus
B_CLIENT = $(SRC_DIR)/client_bonus


LIBFT_DIR = libft
LIBFT = $(LIBFT)/libft.a
INC_FLAGS = -I ./inc

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address,undefined

SRC_DIR = src

SRC =	$(SRC_DIR)/send_signal.c $(SRC_DIR)/handle_signal.c $(SRC_DIR)/check_signal.c\
		$(SRC_DIR)/sigaction_config.c $(SRC_DIR)/handle_string.c $(SRC_DIR)/get_string.c\
		$(SRC_DIR)/send_string.c $(SRC_DIR)/handle_signal_bonus.c $(SRC_DIR)/is_pid_valid.c\

all: $(NAME)

$(NAME): $(LIBFT_DIR)
	@make --no-print-directory -C $(LIBFT_DIR)

server: all $(SRC) $(SERVER)
	@$(CC) $(FLAGS) $(INC_FLAGS) $(^) $(SERVER).c -o $(SERVER) $(LIBFT)

client: all $(SRC) $(CLIENT)
	@$(CC) $(FLAGS) $(INC_FLAGS) $(^) $(CLIENT).c -o $(CLIENT) $(LIBFT)

clean:
	@make clean --no-print-directory -C $(LIBFT_DIR)

fclean: clean
	@make fclean --no-print-directory -C $(LIBFT_DIR) 
	@rm -rf lib_$(NAME).a $(SERVER) $(CLIENT) $(SERVER)_bonus $(CLIENT)_bonus

re: fclean all

bonus: $(LIBFT_DIR)
	@make --no-print-directory -C $(LIBFT_DIR)

server_bonus: bonus $(B_SERVER)
	@$(CC) $(FLAGS) $(INC_FLAGS) $(^) $(B_SERVER).c -o $(B_SERVER) $(LIBFT)

client_bonus: bonus $(B_CLIENT)
	@$(CC) $(FLAGS) $(INC_FLAGS) $(^) $(B_CLIENT).c -o $(B_CLIENT) $(LIBFT)
