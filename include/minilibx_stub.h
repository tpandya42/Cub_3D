/* Minimal prototypes for the minilibx stubs used during parsing-only build */
#ifndef MINILIBX_STUB_H
# define MINILIBX_STUB_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
void	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
void	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
void	mlx_destroy_display(void *mlx_ptr);
void	mlx_loop(void *mlx_ptr);
int	mlx_hook(void *win_ptr, int x_event, int x_mask, void *fun, void *param);
int	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

#endif
