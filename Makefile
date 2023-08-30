NAME = minitalk
LIB_NAME = l_$(NAME)
SERVER = server
CLIENT = client

LIBFT = libft
INC_FLAGS = -I ./inc

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC_FILES = send_signal.c handle_signal.c

OBJS_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(notdir $(OBJS_FILES))
# @norminette  
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(SERVER).c -o $(SERVER) -L. -l_$(NAME)
	@$(CC) $(CCFLAGS) $(INC_FLAGS) $(CLIENT).c -o $(CLIENT) -L. -l_$(NAME)

$(notdir $(OBJS_FILES)): $(SRC_FILES)
	@make -s --directory=$(LIBFT)
	@cp $(LIBFT)/libft.a ./
	@mv $(LIBFT).a lib_$(NAME).a
	@$(CC) -c $(CCFLAGS) $(INC_FLAGS) $(SRC_FILES)
	@ar rc lib_$(NAME).a $(notdir $(OBJS_FILES))

clean:
	@make clean -s --directory=$(LIBFT)
	@rm -rf $(notdir $(OBJS_FILES))

fclean: clean
	@make fclean -s --directory=$(LIBFT) 
	@rm -rf lib_$(NAME).a $(SERVER) $(CLIENT)

re: fclean all
