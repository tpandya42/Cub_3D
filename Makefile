
# ************************************** #
#                CONFIG                  #
# ************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- LIBRARIES --
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_CONFIGURED = $(MLX_DIR)/Makefile.configured # Add a flag to check if MLX was configured

# MiniLibX flags for Linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

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
\
src/init/init.c \
src/init/init_utils.c \
src/init/init_wall.c \
\
src/dummy/dummy.c \
\
src/movement/move.c \
src/movement/rotation.c \
\
src/player/player.c \
src/player/player_setup.c \
\
src/raycast/raycast.c \
src/raycast/raycast_utils.c \
\
src/render/render.c \
src/render/render_utils.c \
src/render/render_wall.c \
\
src/minimap/minimap.c \
src/minimap/minimap_utils.c \
\
src/utils/cleanup.c \
src/utils/error.c \
\
src/window/window.c

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

# Link object files and libft to create the executable and the graphic library
$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $@

# Rule to build libft if it doesn't exist
$(LIBFT_LIB): $(LIBFT_DIR)/Makefile
	$(MAKE)	-C $(LIBFT_DIR)

# Rule to build MiniLibX
$(MLX_LIB): $(MLX_CONFIGURED)
	$(MAKE) -C $(MLX_DIR) all

# Configure MiniLibX if not already configured
$(MLX_CONFIGURED): ./minilibx-linux/configure
	chmod +x $(MLX_DIR)/configure
	cd $(MLX_DIR) && ./configure
	touch $@

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
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -f $(MLX_CONFIGURED) # Clean the flag file

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	rm -f $(MLX_CONFIGURED)

re: fclean all

.PHONY: all clean fclean re
