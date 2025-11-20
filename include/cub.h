#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdbool.h>
#include "../libft/libft.h"//do we need this? -> Tanmay? YES for utils

#include <X11/X.h>//do we need this? -> Tanmay?	 YES for keycodes
#include <X11/keysym.h>//do we need this? -> Tanmay?  YES for keycodes

// Own headers
# include "struct.h"
# include "init.h"
# include "window.h"
//# include "raycast.h"
# include "utils.h"
# include "parsing.h"

//Bonus headers
//# include "minimap_bonus.h"

//Debug headers
//# include "debug.h"

#endif
