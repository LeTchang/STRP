/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/04 01:52:47 by realves           #+#    #+#             */
/*   Updated: 2014/04/17 19:45:17 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	gm_exit(t_env *e, int nb)
{
	int	i;

	i = NB_TEXTURE;
	while (i >= 0)
	{
		if (e->img_tab[i].teleport != NULL)
			free(e->img_tab[i].teleport);
		i--;
	}
	i = NB_TILESET;
	while (i >= 0)
	{
		if (e->tileset[i].ptr != NULL)
			mlx_destroy_image(e->mlx_ptr, e->tileset[i].ptr);
		i--;
	}
	free(e->map.name);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	_exit(nb);
}
