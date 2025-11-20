
# ************************************** #
#                CONFIG                  #
# ************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- LIBRARIES --
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
# (minilibx removed for parsing-only workflow)

# Uncomment these lines for macOS:
# MLX_FLAGS   = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Debug flags
DEBUG_FLAGS = -g -DDEBUG_MODE=1

# Bonus flags
BONUS_FLAGS = -DBONUS_MODE=1 #check if works


# ************************************** #
#               SOURCES                  #
# ************************************** #
SRC = src/main.c \
	$(wildcard src/parsing/*.c) \
	$(wildcard src/init/*.c) \
	$(wildcard src/utils/*.c)

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#BONUS_SRC   = raycast/minimap_bonus.c render/hud_bonus.c #include here
#BONUS_OBJ   = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

# --- Include paths
INCLUDES    = -I include -I $(LIBFT_DIR)

# ************************************** #
#                 RULES                  #
# ************************************** #
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $@

# Rule to build libft if it doesn't exist
$(LIBFT_LIB): $(LIBFT_DIR)/Makefile
	$(MAKE)	-C $(LIBFT_DIR)

# (minilibx removed for parsing-only workflow)

#The obj dir will be created if it doesn't exist
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ************************************** #
#              BONUS MODE                #
# ************************************** #

#bonus:
#	$(MAKE) CFLAGS="$(CFLAGS) $(BONUS_FLAGS)" NAME="$(NAME)_bonus" all #CHECK AND TEST THIS

# ************************************** #
#              DEBUG MODE                #
# ************************************** #

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

# For macOS users (uncomment below)
# MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# ************************************** #
#              CLEAN-UP                  #
# ************************************** #

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)


fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)


re: fclean all

.PHONY: all clean fclean re