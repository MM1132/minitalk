# Common
SRC_DIR := src
OBJ_DIR := obj
CC := cc
CFLAGS := -Wall -Wextra -Werror -I./lib/libft/include
LIBFT_DIR := lib/libft
LIBFT_DEPENDENCY := $(LIBFT_DIR)/libft.a

# Server setup
SERVER_NAME := server
SERVER_DIR := server_dir
SERVER_SRC := $(SERVER_DIR)/$(SRC_DIR)/server.c
SERVER_OBJ := $(SERVER_SRC:$(SERVER_DIR)/$(SRC_DIR)/%.c=$(SERVER_DIR)/$(OBJ_DIR)/%.o)

# Client setup
CLIENT_NAME := client
CLIENT_DIR := client_dir
CLIENT_SRC := $(CLIENT_DIR)/$(SRC_DIR)/client.c
CLIENT_OBJ := $(CLIENT_SRC:$(CLIENT_DIR)/$(SRC_DIR)/%.c=$(CLIENT_DIR)/$(OBJ_DIR)/%.o)

# Rules
all: $(SERVER_NAME) $(CLIENT_NAME)

# Server rules
$(SERVER_DIR)/$(OBJ_DIR)/%.o: $(SERVER_DIR)/$(SRC_DIR)/%.c
	@mkdir -p $(SERVER_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME): $(SERVER_OBJ) $(LIBFT_DEPENDENCY)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $(SERVER_NAME)

# Client rules
$(CLIENT_DIR)/$(OBJ_DIR)/%.o: $(CLIENT_DIR)/$(SRC_DIR)/%.c
	@mkdir -p $(CLIENT_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_NAME): $(CLIENT_OBJ) $(LIBFT_DEPENDENCY)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $(CLIENT_NAME)

# Other rules
$(LIBFT_DEPENDENCY):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(SERVER_DIR)/$(OBJ_DIR)
	rm -rf $(CLIENT_DIR)/$(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
