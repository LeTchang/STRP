/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:54:28 by realves           #+#    #+#             */
/*   Updated: 2014/03/23 20:01:54 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ENV_H
# define STRUCT_ENV_H

# include "game.h"
# include "struct_img.h"
# include "struct_map.h"

# define NB_TEXTURE 100

typedef struct			s_env
{
	t_img				screen;
	t_img				trans;
	t_img				red;
	t_img				img_tab[NB_TEXTURE];
	t_map				map;
	void				*mlx_ptr;
	void				*win_ptr;
	int					red_posx;
	int					red_posy;
	int					up_arrow;
	int					down_arrow;
	int					left_arrow;
	int					right_arrow;
	int					x;
	int					y;
	int					sens;
	int					speed;
}						t_env;

#endif /* !STRUCT_ENV_H */
