/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:10:24 by realves           #+#    #+#             */
/*   Updated: 2014/03/29 00:51:42 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	draw_texture(t_img *tileset, t_img *img, int x, int y)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		tab[5];

	l = 0;
	j = y * 16;
	while (j < (y + 1) * 16)
	{
		k = 0;
		i = x * 16;
		while (i < (x + 1) * 16)
		{
			tab[0] = k;
			tab[1] = l;
			tab[2] = tileset->img[j * tileset->size_line + 4 * i + 2];
			tab[3] = tileset->img[j * tileset->size_line + 4 * i + 1];
			tab[4] = tileset->img[j * tileset->size_line + 4 * i];
			gm_pixel_put_img(img, tab);
			i++;
			k++;
		}
		j++;
		l++;
	}
}

static void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
}

static void	init_texture(t_env *e, char *line)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	printf("%s\n", split[0]);
	gm_init_screen(e->mlx_ptr, 16, 16, &(e->img_tab[ft_atoi(split[0])]));
	draw_texture(&(e->tileset[ft_atoi(split[1])]),
			&(e->img_tab[ft_atoi(split[0])]), ft_atoi(split[2]),
			ft_atoi(split[3]));
	e->img_tab[ft_atoi(split[0])].solid = ft_atoi(split[4]);
	e->img_tab[ft_atoi(split[0])].sens = ft_atoi(split[5]);
	e->img_tab[ft_atoi(split[0])].under = ft_atoi(split[6]);
	if (split[7][0] != '0')
	{
		e->img_tab[ft_atoi(split[0])].teleport = split[8];
		e->img_tab[ft_atoi(split[0])].teleport_x = ft_atoi(split[9]);
		e->img_tab[ft_atoi(split[0])].teleport_y = ft_atoi(split[10]);
		e->img_tab[ft_atoi(split[0])].teleport_sens = ft_atoi(split[11]);
		e->img_tab[ft_atoi(split[0])].teleport_trans = ft_atoi(split[12]);
	}
	else
		e->img_tab[ft_atoi(split[0])].teleport = NULL;
	free(split);
}

static void	init_tileset(t_env *e, char *line)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	e->tileset[ft_atoi(split[0])] = gm_init_img(e, split[1],
			ft_atoi(split[2]), ft_atoi(split[3]));
	free(split);
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
	free_split(spli);
	free(spli);
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
	free_split(split);
	free(split);
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
	free_split(split);
	free(split);
}

void		gm_init_map(t_env *e, char *path)
{
	int			line_nb;
	int			fd;
	int			check;
	char		*line;

	check = 0;
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
		{
			if (line[0] == '-')
				check = 1;
			else if (check == 0)
				init_tileset(e, line);
			else
				init_texture(e, line);
		}
		line_nb++;
		free(line);
	}
	close(fd);
}
