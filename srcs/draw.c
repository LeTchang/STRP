/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:06:07 by realves           #+#    #+#             */
/*   Updated: 2014/04/06 18:10:00 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void			gm_pixel_put_img(t_env *e, t_img *img, int tab[5])
{
	if (tab[0] < e->win_width && tab[1] < e->win_height && tab[0] >= 0 && tab[1] >= 0)
	{
		img->img[tab[1] * img->size_line + img->bpp * tab[0]] = tab[4];
		img->img[tab[1] * img->size_line + img->bpp * tab[0] + 1] = tab[3];
		img->img[tab[1] * img->size_line + img->bpp * tab[0] + 2] = tab[2];
	}
}

void			gm_draw_ratio(t_env *e, t_img *img, int tab[5])
{
	int		l;
	int		k;
	int		i;
	int		j;

	i = tab[0] * e->win_ratio - e->win_ratio;
	j = tab[1] * e->win_ratio - e->win_ratio;
	l = 0;
	while (l < e->win_ratio)
	{
		k = 0;
		while (k < e->win_ratio)
		{
			tab[0] = i + l;
			tab[1] = j + k;
			gm_pixel_put_img(e, img, tab);
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

void		gm_draw_img(t_env *e, t_img *screen, t_img *img, int x, int y)
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
				gm_draw_ratio(e, screen, t);
			j++;
		}
		i++;
	}
}

void		gm_draw_half(t_env *e, t_img *screen, t_img *img, int tab[4])
{
	int		t[5];
	int		val[5];

	val[1] = 0;
	val[2] = 0;
	if (tab[2] == 1)
	{
		val[3] = img->width;
		val[4] = tab[3];
	}
	else if (tab[2] == 2)
	{
		val[3] = tab[3];
		val[4] = img->height;
	}
	else if (tab[2] == 3)
	{
		val[1] = 16 - tab[3];
		val[3] = img->width;
		val[4] = img->height;
	}
	else
	{
		val[2] = 16 - tab[3];
		val[3] = img->width;
		val[4] = img->height;
	}
	while (val[1] < val[4])
	{
		val[0] = val[2];
		while (val[0] < val[3])
		{
			t[0] = tab[0] + val[0];
			t[1] = tab[1] + val[1];
			t[2] = img->img[val[1] * img->size_line + 4 * val[0] + 2];
			t[3] = img->img[val[1] * img->size_line + 4 * val[0] + 1];
			t[4] = img->img[val[1] * img->size_line + 4 * val[0]];
			if (!test_transpa(t[2], t[3], t[4]))
				gm_draw_ratio(e, screen, t);
			val[0]++;
		}
		val[1]++;
	}
}
