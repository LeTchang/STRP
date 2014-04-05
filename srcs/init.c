/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:08:03 by realves           #+#    #+#             */
/*   Updated: 2014/04/05 18:50:13 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_img	gm_init_img(t_env *env, char *path, int width, int height)
{
	t_img		img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_xpm_file_to_image(env->mlx_ptr, path, &width, &height);
	img.img = mlx_get_data_addr(img.ptr, &(img.bpp), &(img.size_line),
		   	&(img.endian));
	img.bpp /= 8;
	img.max_size = img.width * img.height * img.bpp;
	return (img);
}

void	gm_init_screen(void *mlx, int width, int height, t_img *img)
{
	img->width = width;
	img->height = height;
	img->ptr = mlx_new_image(mlx, width, height);
	img->img = mlx_get_data_addr(img->ptr, &(img->bpp), &(img->size_line), 
			&(img->endian));
	img->bpp /= 8;
	img->max_size = img->width * img->height * img->bpp;
}

void	gm_init_mlx(t_env *e)
{
	int	i;

	e->map.name = NULL;
	i = NB_TEXTURE;
	while (i >= 0)
	{
		e->img_tab[i].teleport = NULL;
		e->img_tab[i].ptr = NULL;
		i--;
	}
	i = NB_TILESET;
	while (i >= 0)
	{
		e->img_tab[i].ptr = NULL;
		i--;
	}
	e->map.fanim = NULL;
	e->time.check = 0;
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, FEN_NAME);
	gm_init_screen(e->mlx_ptr, WIDTH, HEIGHT, &(e->screen));
	mlx_do_key_autorepeatoff(e->mlx_ptr);
}
