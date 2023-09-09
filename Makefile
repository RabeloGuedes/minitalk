NAME = minitalk
LIB_NAME = l_$(NAME)
SERVER = server
CLIENT = client

LIBFT = libft
INC_FLAGS = -I ./inc

CC = cc

FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address

SRC_FILES = send_signal.c handle_signal.c check_signal.c sigaction_config.c handle_string.c get_string.c\
			send_string.c handle_signal_bonus.c

OBJS_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_FILES) $(SERVER) $(CLIENT)

server:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(SERVER).c -o $(SERVER) -L. -l_$(NAME)

client:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(CLIENT).c -o $(CLIENT) -L. -l_$(NAME)

$(OBJS_FILES): $(SRC_FILES)
	@make -s --directory=$(LIBFT)
	@cp $(LIBFT)/libft.a ./
	@mv $(LIBFT).a lib_$(NAME).a
	@$(CC) -c $(CCFLAGS) $(INC_FLAGS) $(SRC_FILES)
	@ar rc lib_$(NAME).a $(OBJS_FILES)

clean:
	@make clean -s --directory=$(LIBFT)
	@rm -rf $(OBJS_FILES)

fclean: clean
	@make fclean -s --directory=$(LIBFT) 
	@rm -rf lib_$(NAME).a $(SERVER) $(CLIENT) $(SERVER)_bonus $(CLIENT)_bonus $(SERVER).dSYM $(CLIENT).dSYM 

re: fclean all

bonus: $(OBJS_FILES) server_bonus client_bonus

server_bonus:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(SERVER)_bonus.c -o $(SERVER)_bonus -L. -l_$(NAME)

client_bonus:
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(CLIENT)_bonus.c -o $(CLIENT)_bonus -L. -l_$(NAME)

debug: $(OBJS_FILES)
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) $(SERVER).c -o $(SERVER) -L. -l_$(NAME)
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) $(CLIENT).c -o $(CLIENT) -L. -l_$(NAME)
