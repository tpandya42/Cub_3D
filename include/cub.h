#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdbool.h>
#include "../libft/libft.h"//do we need this? -> Tanmay?
#include "../minilibx-linux/mlx.h"//do we need this? -> Tanmay?
#include <X11/X.h>//do we need this? -> Tanmay?
#include <X11/keysym.h>//do we need this? -> Tanmay?

// Own headers
# include "struct.h"
# include "init.h"
# include "window.h"
# include "raycast.h"
# include "util.h"

//Bonus headers
# include "minimap_bonus.h"

//Debug headers
# include "debug.h"

#endif
