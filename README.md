# fdf
7PA0|0Hb4NK
MACos gcc -I minilibx_macos -I . main.c inits.c draw_isometric.c rotate.c -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
Linux Run mlx_install and  gcc -I . main.c draw_isometric.c rotate.c inits.c -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lm
