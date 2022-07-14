#ifndef MLX_WINDOW_H_
# define MLX_WINDOW_H_


# include <mlx.h>
# include <stdlib.h>

# include "structure.h"

// for window constants
# define WIDTH  1920
# define HEIGHT 1080
# define TITLE  "miniRT"

// for event constants
// https://harm-smits.github.io/42docs/libs/minilibx/events.html
# define X11_KEYPRESS       2
# define X11_DESTROYNOTIFY  17
# define KEYPRESS_MASK      (1L<<0)
# define NOEVENT_MASK       (0L)
# define ESC_KEY            53

t_bool  init_window(t_window *window);

#endif