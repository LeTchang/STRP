/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:03:53 by realves           #+#    #+#             */
/*   Updated: 2014/04/04 22:40:37 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MAP_H
# define STRUCT_MAP_H

# include "game.h"
# include "struct_anim.h"

typedef struct		s_map
{
	int				w;
	int				h;
	int				*map;
	int				*back;
	char			*name;
	t_anim			*fanim;
}					t_map;

#endif /* !STRUCT_MAP_H */
