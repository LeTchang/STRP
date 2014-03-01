/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:06:07 by realves           #+#    #+#             */
/*   Updated: 2014/02/28 14:47:59 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void			gm_pixel_put_img(t_img *img, int tab[5])
{
	if (tab[1] * img->size_line + img->bpp * tab[0] <= img->max_size 
			&& tab[1] * img->size_line + img->bpp * tab[0] >= 0)
	{
		img->img[tab[1] * img->size_line + img->bpp * tab[0]] = tab[4];
		img->img[tab[1] * img->size_line + img->bpp * tab[0] + 1] = tab[3];
		img->img[tab[1] * img->size_line + img->bpp * tab[0] + 2] = tab[2];
	}
}

void			gm_draw_ratio(t_img *img, int tab[5])
{
	int		l;
	int		k;
	int		i;
	int		j;

	i = tab[0] * RATIO - RATIO;
	j = tab[1] * RATIO - RATIO;
	l = 0;
	while (l < RATIO)
	{
		k = 0;
		while (k < RATIO)
		{
			tab[0] = i + l;
			tab[1] = j + k;
			gm_pixel_put_img(img, tab);
			k++;
		}
		l++;
	}
}

static int	test_transpa(int red, int green, int blue)
{
	if ((red == TRANSPA_R && green == TRANSPA_G && blue == TRANSPA_B)
			|| (red == -1 && green == 0 && blue == -1))
		return (1);
	return (0);
}

void		gm_draw_img(t_img *screen, t_img *img, int x, int y)
{
	int		t[5];
	int		i;
	int		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			t[0] = x + j;
			t[1] = y + i;
			t[2] = img->img[i * img->size_line + 4 * j + 2];
			t[3] = img->img[i * img->size_line + 4 * j + 1];
			t[4] = img->img[i * img->size_line + 4 * j];
			if (!test_transpa(t[2], t[3], t[4]))
				gm_draw_ratio(screen, t);
			j++;
		}
		i++;
	}
}
