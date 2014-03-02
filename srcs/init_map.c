/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:10:24 by realves           #+#    #+#             */
/*   Updated: 2014/03/02 21:48:18 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	init_texture(t_env *e, char *line)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	e->img_tab[ft_atoi(split[0])] = gm_init_img(e, split[1], 16, 16);
	e->img_tab[ft_atoi(split[0])].solid = ft_atoi(split[2]);
	e->img_tab[ft_atoi(split[0])].sens = ft_atoi(split[3]);
	if (split[4][0] != '0')
	{
		e->img_tab[ft_atoi(split[0])].teleport = split[5];
		e->img_tab[ft_atoi(split[0])].teleport_x = ft_atoi(split[6]);
		e->img_tab[ft_atoi(split[0])].teleport_y = ft_atoi(split[7]);
	}
	else
		e->img_tab[ft_atoi(split[0])].teleport = NULL;
}

static void	init_back(t_env *e, char *line, int line_nb)
{
	int			j;
	char		**spli;

	j = 0;
	spli = ft_strsplit(line, ' ');
	while (j < e->map.w)
	{
		e->map.back[j + e->map.w * (line_nb - e->map.h - 5)] = ft_atoi(spli[j]);
		j++;
	}
}

static void	init_map(t_env *e, char *line, int line_nb)
{
	int			j;
	char		**split;

	j = 0;
	split = ft_strsplit(line, ' ');
	while (j < e->map.w)
	{
		e->map.map[j + e->map.w * (line_nb - 4)] = ft_atoi(split[j]);
		j++;
	}
}

static void	init_define(t_env *e, char *line, int line_nb)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (line_nb == 0)
		e->map.w = ft_atoi(split[1]);
	else if (line_nb == 1)
		e->map.h = ft_atoi(split[1]);
	else if (line_nb == 2)
		e->map.name = split[1];
}

void		gm_init_map(t_env *e, char *path)
{
	int			line_nb;
	int			fd;
	char		*line;

	line_nb = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		gm_error(4, "Error in map initialisation.");
	while (get_next_line(fd, &line))
	{
		if (line_nb < 3)
			init_define(e, line, line_nb);
		else if (line_nb == 3)
		{
			e->map.map = malloc(sizeof(e->map.map) * e->map.h * e->map.w);
			if (e->map.map == NULL)
				gm_error(3, "Error in a malloc tentative.");
		}
		else if (line_nb >= 4 && line_nb <= e->map.h + 3)
			init_map(e, line, line_nb);
		else if (line_nb == e->map.h + 4)
		{
			e->map.back = malloc(sizeof(e->map.back) * e->map.h * e->map.w);
			if (e->map.back == NULL)
				gm_error(3, "Error in a malloc tentative.");
		}
		else if (line_nb >= e->map.h + 5 && line_nb <= e->map.h * 2 + 4)
			init_back(e, line, line_nb);
		else if (line_nb >= e->map.h * 2 + 6)
			init_texture(e, line);
		line_nb++;
	}
}
