NAME = minitalk
LIB_NAME = l_$(NAME)
SERVER = server
CLIENT = client

LIBFT = libft
INC_FLAGS = -I ./inc

CC = cc

FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address

SRC =	send_signal.c handle_signal.c check_signal.c\
		sigaction_config.c handle_string.c get_string.c\
		send_string.c handle_signal_bonus.c is_pid_valid.c

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ) $(SERVER) $(CLIENT)

server:
	@ar rc lib_$(NAME).a $(OBJ)
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(SERVER).c -o $(SERVER) -L. -l_$(NAME)

client:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(CLIENT).c -o $(CLIENT) -L. -l_$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@make -s --directory=$(LIBFT)
	@cp $(LIBFT)/libft.a ./
	@mv $(LIBFT).a lib_$(NAME).a
	@$(CC) -c $(CCFLAGS) $(INC_FLAGS) $< -o $@

clean:
	@make clean -s --directory=$(LIBFT)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -s --directory=$(LIBFT) 
	@rm -rf lib_$(NAME).a $(SERVER) $(CLIENT) $(SERVER)_bonus $(CLIENT)_bonus $(SERVER).dSYM $(CLIENT).dSYM 

re: fclean all

bonus: $(OBJ) server_bonus client_bonus

server_bonus:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(SERVER)_bonus.c -o $(SERVER)_bonus -L. -l_$(NAME)

client_bonus:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(CLIENT)_bonus.c -o $(CLIENT)_bonus -L. -l_$(NAME)

debug: $(OBJ)
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) $(SERVER).c -o $(SERVER) -L. -l_$(NAME)
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) $(CLIENT).c -o $(CLIENT) -L. -l_$(NAME)
