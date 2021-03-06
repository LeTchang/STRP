/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:54:28 by realves           #+#    #+#             */
/*   Updated: 2014/04/14 14:03:12 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ENV_H
# define STRUCT_ENV_H

# include "game.h"
# include "struct_img.h"
# include "struct_map.h"
# include "struct_time.h"
# include "struct_anim.h"
# include "struct_menu.h"

# define NB_TILESET 10
# define NB_TEXTURE 1000

typedef struct			s_env
{
	t_img				screen;
	t_img				trans;
	t_img				red;
	t_img				tmp;
	t_img				tmp2;
	t_img				tileset[NB_TILESET];
	t_img				img_tab[NB_TEXTURE];
	t_map				map;
	t_time				time;
	t_menu				menu;
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_width;
	int					win_height;
	int					win_ratio;
	int					red_posx;
	int					red_posy;
	int					up_arrow;
	int					down_arrow;
	int					left_arrow;
	int					right_arrow;
	int					x;
	int					y;
	int					direction;
	int					sprint;
}						t_env;

#endif /* !STRUCT_ENV_H */
