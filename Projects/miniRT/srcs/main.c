#include "../mlx/mlx.h"

int main(void)
{
    void    *mlx_p;
    void    *win_p;

    mlx_p = mlx_init();
    win_p = mlx_new_window(mlx_p, 500, 500, "mlx test");
    mlx_loop(mlx_p);

    return (0);
}