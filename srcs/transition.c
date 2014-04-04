/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:18:16 by realves           #+#    #+#             */
/*   Updated: 2014/04/04 01:50:07 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	dinit(t_env *e, t_img *timg, char *img, int width, int lenght)
{
	if (timg->ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, timg->ptr);
	*timg = gm_init_img(e, img, width, lenght);
}

static void	trans(t_env *e, char *img, int time)
{
	gm_gene_map(e, 0, 0, 0);
	gm_draw_img(e, &(e->screen), &(e->red), e->red_posx, e->red_posy);
	gm_gene_map(e, 0, 0, 1);
	if (img != NULL)
	{
		dinit(e, &(e->trans), img, 336, 272);
		gm_draw_img(e, &(e->screen), &(e->trans), 0, 0);
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->screen.ptr, 0, 0);
	usleep(time);
}

static void	tinit(t_env *e, char *img, int width, int lenght, char *trans_img, int time)
{
	dinit(e, &(e->red), img, width, lenght);
	trans(e, trans_img, time);
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
		dinit(e, &(e->red), "./img/red/red_up_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 2)
		dinit(e, &(e->red), "./img/red/red_left_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 3)
		dinit(e, &(e->red), "./img/red/red_down_1.xpm", 16, 32);
	else
		dinit(e, &(e->red), "./img/red/red_right_1.xpm", 16, 32);
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
		dinit(e, &(e->red), "./img/red/red_up_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 2)
		dinit(e, &(e->red), "./img/red/red_left_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 3)
		dinit(e, &(e->red), "./img/red/red_down_1.xpm", 16, 32);
	else
		dinit(e, &(e->red), "./img/red/red_right_1.xpm", 16, 32);
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

static void	trans_3(t_env *e, int nb)
{
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, NULL, 10000);
	e->x = e->img_tab[nb].teleport_x;
	e->y = e->img_tab[nb].teleport_y;
	free(e->map.map);
	free(e->map.back);
	gm_init_map(e, e->img_tab[nb].teleport);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, NULL, 10000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, NULL, 30000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, NULL, 50000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, NULL, 50000);
	if (e->img_tab[nb].teleport_sens == 1)
		dinit(e, &(e->red), "./img/red/red_up_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 2)
		dinit(e, &(e->red), "./img/red/red_left_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 3)
		dinit(e, &(e->red), "./img/red/red_down_1.xpm", 16, 32);
	else
		dinit(e, &(e->red), "./img/red/red_right_1.xpm", 16, 32);
	gm_putallarrow(e, 0);
}

static void	trans_4(t_env *e, int nb)
{
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, "./img/transition/1/trans0.xpm", 15000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, "./img/transition/1/trans0.xpm", 15000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, "./img/transition/1/trans1.xpm", 15000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, "./img/transition/1/trans1.xpm", 15000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, "./img/transition/1/trans2.xpm", 10000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, "./img/transition/1/trans2.xpm", 10000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, "./img/transition/1/trans3.xpm", 10000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, "./img/transition/1/trans3.xpm", 10000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, "./img/transition/1/trans4.xpm", 5000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, "./img/transition/1/trans4.xpm", 5000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, "./img/transition/1/trans4.xpm", 5000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, "./img/transition/black.xpm", 5000);
	e->x = e->img_tab[nb].teleport_x;
	e->y = e->img_tab[nb].teleport_y;
	free(e->map.map);
	free(e->map.back);
	gm_init_map(e, e->img_tab[nb].teleport);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, "./img/transition/1/trans4.xpm", 5000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, "./img/transition/1/trans4.xpm", 5000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, "./img/transition/1/trans4.xpm", 5000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, "./img/transition/1/trans3.xpm", 5000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, "./img/transition/1/trans3.xpm", 10000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, "./img/transition/1/trans2.xpm", 10000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, "./img/transition/1/trans2.xpm", 10000);
	tinit(e, "./img/red/red_left_1.xpm", 16, 32, "./img/transition/1/trans1.xpm", 10000);
	tinit(e, "./img/red/red_up_1.xpm", 16, 32, "./img/transition/1/trans1.xpm", 15000);
	tinit(e, "./img/red/red_right_1.xpm", 16, 32, "./img/transition/1/trans0.xpm", 15000);
	tinit(e, "./img/red/red_down_1.xpm", 16, 32, "./img/transition/1/trans0.xpm", 15000);
	if (e->img_tab[nb].teleport_sens == 1)
		dinit(e, &(e->red), "./img/red/red_up_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 2)
		dinit(e, &(e->red), "./img/red/red_left_1.xpm", 16, 32);
	else if (e->img_tab[nb].teleport_sens == 3)
		dinit(e, &(e->red), "./img/red/red_down_1.xpm", 16, 32);
	else
		dinit(e, &(e->red), "./img/red/red_right_1.xpm", 16, 32);
	gm_putallarrow(e, 0);
}

void		gm_trans(t_env *e, int nb)
{
	int		n;

	n = e->img_tab[nb].teleport_trans;
	if (n == 2)
		trans_2(e, nb);
	else if (n == 3)
		trans_3(e, nb);
	else if (n == 4)
		trans_4(e, nb);
	else
		trans_1(e, nb);
}
