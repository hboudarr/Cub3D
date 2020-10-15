#include "cub3d.h"

void	ft_define_ptr(t_read *args, t_img *ptr)
{
	ptr->file_size = args->resol[0] * args->resol[1] * 4 + 54;
	ptr->reserved1 = 0;
	ptr->reserved2 = 0;
	ptr->offset_bits = 54;
	ptr->size_header = 40;
	ptr->width = args->resol[0];
	ptr->height = args->resol[1];
	ptr->planes = 1;
	ptr->bbp = 32;
	ptr->compression = 0;
	ptr->image_size = 0;
	ptr->ppm_x = 0;
	ptr->ppm_y = 0;
	ptr->clr_total = 0;
	ptr->clr_important = 0;
}

void	ft_tab_in_img(t_read *args, int fd)
{
	int				i;
	int				x;
	int				y;
	unsigned int	*tab;

	tab = malloc(sizeof(int) * (args->resol[1] * args->resol[0]));
	if (tab == NULL)
		ft_error(1);
	y = args->resol[1] - 1;
	i = 0;
	while (i < (args->resol[0] * args->resol[1]))
	{
		x = -1;
		while (++x < args->resol[0])
			tab[i++] = *(unsigned int *)(args->addr + y * args->line_length + x * args->bits_per_pixel / 8);
		y--;
	}
	/* if */ (write(fd, tab, args->resol[0] * args->resol[1] * 4));
	{
		//free(tab);
		// ft_exit15(param);
	}
	// free(tab);
}

void	ft_create_img(t_read *args)
{
	int		fd;
	t_img	ptr;

	ft_define_ptr(args, &ptr);
	fd = open("cub3d_img.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd == -1)
		ft_error(1);
	if (write(fd, "BM", 2) == -1 || write(fd, &ptr, 52) == -1)
		ft_error(1);
	ft_tab_in_img(args, fd);
	close(fd);
	// ft_exit16(param);
}