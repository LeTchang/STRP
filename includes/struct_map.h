/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:03:53 by realves           #+#    #+#             */
/*   Updated: 2014/03/28 22:20:45 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MAP_H
# define STRUCT_MAP_H

# include "game.h"

typedef struct		s_map
{
	int				w;
	int				h;
	int				*map;
	int				*back;
	char			*name;
}					t_map;

#endif /* !STRUCT_MAP_H */
