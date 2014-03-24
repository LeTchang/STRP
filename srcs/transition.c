/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:18:16 by realves           #+#    #+#             */
/*   Updated: 2014/03/24 21:19:40 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	trans(t_env *e, char *img, int time)
{
	gm_gene_map(e, 0, 0);
	gm_draw_img(&(e->screen), &(e->red), e->red_posx, e->red_posy);
	e->trans = gm_init_img(e, img, 336, 272);
	gm_draw_img(&(e->screen), &(e->trans), 0, 0);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(time);
}

static void	trans_1(t_env *e, int nb)
{
	trans(e, "./img/transition/1/trans0.xpm", 20000);
	trans(e, "./img/transition/1/trans1.xpm", 20000);
	trans(e, "./img/transition/1/trans2.xpm", 20000);
	trans(e, "./img/transition/1/trans3.xpm", 20000);
	trans(e, "./img/transition/1/trans4.xpm", 20000);
	trans(e, "./img/transition/black.xpm", 10000);
	e->x = e->img_tab[nb].teleport_x;
	e->y = e->img_tab[nb].teleport_y;
	if (e->img_tab[nb].teleport_sens == 1)
		e->red = gm_init_img(e, "./img/red/red_down_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 2)
		e->red = gm_init_img(e, "./img/red/red_left_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 3)
		e->red = gm_init_img(e, "./img/red/red_up_1.xpm", 16, 32);
	else
		e->red = gm_init_img(e, "./img/red/red_right_1.xpm", 16, 32);
	free(e->map.map);
	free(e->map.back);
	gm_init_map(e, e->img_tab[nb].teleport);
	trans(e, "./img/transition/1/trans4.xpm", 20000);
	trans(e, "./img/transition/1/trans3.xpm", 20000);
	trans(e, "./img/transition/1/trans2.xpm", 20000);
	trans(e, "./img/transition/1/trans1.xpm", 20000);
	trans(e, "./img/transition/1/trans0.xpm", 20000);
	gm_putallarrow(e, 0);
}

static void	trans_2(t_env *e, int nb)
{
	trans(e, "./img/transition/2/trans0.xpm", 20000);
	trans(e, "./img/transition/2/trans1.xpm", 20000);
	trans(e, "./img/transition/2/trans2.xpm", 20000);
	trans(e, "./img/transition/2/trans3.xpm", 20000);
	trans(e, "./img/transition/2/trans4.xpm", 20000);
	trans(e, "./img/transition/black.xpm", 10000);
	e->x = e->img_tab[nb].teleport_x;
	e->y = e->img_tab[nb].teleport_y;
	if (e->img_tab[nb].teleport_sens == 1)
		e->red = gm_init_img(e, "./img/red/red_down_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 2)
		e->red = gm_init_img(e, "./img/red/red_left_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 3)
		e->red = gm_init_img(e, "./img/red/red_up_1.xpm", 16, 32);
	else
		e->red = gm_init_img(e, "./img/red/red_right_1.xpm", 16, 32);
	free(e->map.map);
	free(e->map.back);
	gm_init_map(e, e->img_tab[nb].teleport);
	trans(e, "./img/transition/2/trans4.xpm", 20000);
	trans(e, "./img/transition/2/trans3.xpm", 20000);
	trans(e, "./img/transition/2/trans2.xpm", 20000);
	trans(e, "./img/transition/2/trans1.xpm", 20000);
	trans(e, "./img/transition/2/trans0.xpm", 20000);
	gm_putallarrow(e, 0);
}

void		gm_trans(t_env *e, int nb)
{
	int		n;

	n = e->img_tab[nb].teleport_trans;
	if (n == 2)
		trans_2(e, nb);
	else
		trans_1(e, nb);
}
