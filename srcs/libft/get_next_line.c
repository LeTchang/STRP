/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 16:44:04 by realves           #+#    #+#             */
/*   Updated: 2014/04/02 21:37:19 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int		gnl_append_to_backup(int res, char *rbuf, char **rbak)
{
	int				blen;
	char			*new;

	if ((*rbak) == NULL)
		blen = 0;
	else
		blen = ft_strlen(*rbak);
	new = (char *)malloc(sizeof(char) * (blen + res + 1));
	if (!new)
		return (-1);
	if (*rbak != NULL)
		ft_strncpy(new, (*rbak), blen + 1);
	ft_strncpy((new + blen), rbuf, res + 1);
	if (*rbak)
		free(*rbak);
	*rbak = new;
	return (1);
}

static int		gnl_read_and_save(const int fd, char **rbak)
{
	char			*rbuf;
	int				res;
	int				go_on;

	go_on = 1;
	rbuf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!rbuf)
		return (-1);
	res = read(fd, rbuf, BUFF_SIZE);
	while (go_on && res > 0)
	{
		rbuf[res] = '\0';
		if (ft_strchr(rbuf, '\n') != NULL)
			go_on = 0;
		res = gnl_append_to_backup(res, rbuf, rbak);
		if (!res)
		{
			free(rbuf);
			return (-1);
		}
		res = (go_on ? read(fd, rbuf, BUFF_SIZE) : 1);
	}
	free(rbuf);
	return (res);
}

static int		gnl_dump_line(const int length, char **rbak)
{
	int				blen;
	char			*new;

	if ((*rbak) == NULL)
		return (0);
	blen = ft_strlen(*rbak);
	if (blen == 0)
	{
		ft_strdel(rbak);
		return (0);
	}
	if (length == -1)
	{
		ft_strdel(rbak);
		return (1);
	}
	new = (char *)malloc(sizeof(char) * (blen - length + 1));
	if (!new)
		return (-1);
	new = ft_strncpy(new, ((*rbak) + length), (blen - length));
	new[blen - length] = '\0';
	free(*rbak);
	*rbak = new;
	return (1);
}

static int		gnl_set_line(char **rbak, char **line)
{
	int				linelen;
	char			*ptrnl;

	if (!(*rbak))
		return (0);
	ptrnl = ft_strchr(*rbak, '\n');
	if (ptrnl == NULL)
	{
		*line = ft_strdup(*rbak);
		return (gnl_dump_line(-1, rbak));
	}
	linelen = ptrnl - (*rbak) + 1;
	*line = (char *)malloc(sizeof(char) * (linelen + 1));
	if (!(*line))
		return (-1);
	*line = ft_strncpy(*line, *rbak, linelen);
	*((*line) + linelen - 1) = '\0';
	return (gnl_dump_line(linelen, rbak));
}

int				get_next_line(const int fd, char **line)
{
	static char		*rbak = NULL;
	int				res;

	res = 1;
	if (rbak == NULL)
		res = gnl_read_and_save(fd, &rbak);
	else if (!(ft_strchr(rbak, '\n')))
		res = gnl_read_and_save(fd, &rbak);
	if (rbak != NULL || res >= 0)
		res = gnl_set_line(&rbak, line);
	if (res < 1)
	{
		if (rbak)
			free(rbak);
		return (res);
	}
	return (res);
}
