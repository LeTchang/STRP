/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:40:03 by realves           #+#    #+#             */
/*   Updated: 2014/04/14 16:26:59 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

/*
**  Include Systeme
*/

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

/*
**  Include Local
*/

# include "struct_env.h"
# include "struct_img.h"
# include "struct_map.h"
# include "struct_time.h"
# include "struct_anim.h"

/*
**  Define
*/

# define BUFF_SIZE 4096

# define ESCAPE 65307
# define SPACE 32
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ENTER 65293

# define TRANSPA_R 255
# define TRANSPA_G 0
# define TRANSPA_B 255

# define FEN_NAME "Adventure Ballz"

/*
** Prototypes Libft
*/

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
void			ft_reverse(char *str);
void			ft_strdel(char **as);
void			ft_animadd(t_anim **fanim, t_anim *new);
void			ft_animdel(t_anim **fanim);
t_anim			*ft_animnew(int tick, int nb_img, int nb_tileset, int x, int y);

/*
** Prototypes Game
*/

void			gm_pixel_put_img(t_env *e, t_img *img, int tab[5]);
void			gm_draw_ratio(t_env *e, t_img *img, int tab[5]);
void			gm_draw_img(t_env *e, t_img *screen, t_img *img, int x, int y);
void			gm_draw_half(t_env *e, t_img *screen, t_img *img, int tab[4]);
void			gm_draw_halfline(t_env *e, int sens, int nb_px);
void			gm_trans(t_env *e, int nb);
void			gm_up(t_env *e);
void			gm_down(t_env *e);
void			gm_left(t_env *e);
void			gm_right(t_env *e);
void			gm_error(int nb, char *reason);
void			gm_init_map(t_env *e, char *path);
void			gm_gene_map(t_env *e, int pos_x, int pos_y, int under);
void			gm_exit(t_env *e, int nb);
void			gm_anim_timer(t_env *e);

/*
**	Prototypes Utilities
*/

void			gm_putallarrow(t_env *e, int nb);
void			gm_init_mlx(t_env *e);
void			gm_init_screen(void *mlx, int width, int height, t_img *img);
void			gm_draw_texture(t_env *e, t_img *tileset, t_img *img, int x, int y);
t_img			gm_init_img(t_env *env, char *path, int width, int height);
double			get_time_ms();

#endif /* !GAME_H */
