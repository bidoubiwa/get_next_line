/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:01:33 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/27 00:01:55 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

// Fonction qui decoupe buffer avec le premier \n
//
// Fonction qui read
//
// fonction qui initialise la structure
//
// fonction qui rempi liste chainee et renvoie string

static	char	*ft_read(t_fd *current, int fd, char **line, int *state)
{
	char	buf[BUFF_SIZE];
	int		ret;
	int		len;
	char	*tmp;
	char	*str_tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] =  '\0';	
		if ((tmp = ft_strchr(buf,'\n')))
		{
			if (!(*line = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(tmp))))
				return (NULL);
			if (!(*line = ft_strjoin(current->str, *line)))
				return (NULL);
//			dprintf(1,"current line after line merge : %s\n", *line);
			str_tmp = current->str;
			if (!(current->str = ft_strsub(tmp, 1, ft_strlen(tmp) - 1)))
				return (NULL);
			ft_strdel(&str_tmp);
			*state = 1; 
			return (*line);
		}
		else if (ret < BUFF_SIZE)
		{
			if(!(*line = ft_strjoin(current->str, buf)))
				return (NULL);
			ft_strdel(&current->str);
			*state = 0;
			return (*line);
		}
		if(!(current->str = ft_strjoin(current->str, buf)))
			return (NULL);
	}
	if (!(*line = ft_strdup(current->str)))
		return (NULL);
	*state = 0;
	return (*line);
}

static	int		ft_read_buff(t_fd *current, int fd, char **line)
{
	char	*origin;
	char	*tmp;
	int		ret;

	ret = 0;
	origin = current->str;
	if ((tmp = ft_strchr(origin, '\n')))
	{
		if (!(*line = ft_strsub(origin, 0, tmp - origin)))
			return (-1);
		if (!(current->str =  ft_strsub(tmp, 1, ft_strlen(tmp) - 1)))
			return (-1);
		ft_strdel(&origin);
	}
	else
	{
		if(!(*line = ft_read(current,fd, line, &ret)) || ret < 0 )
			return (-1);
	//	dprintf(1,"current line dans ft_read_buff : %s\n", *line);
		return (ret);
	}
	return (ret);
}

static	t_fd	*ft_fill_struct(const int fd, t_fd *tmp, char *str)
{
	tmp->str = str;
	tmp->fd = fd;
	return (tmp);
}

static	int		ft_get_fd_struct(const int fd, t_fd **begin, t_fd **current)
{
	t_fd	*previous;
	t_fd	*tmp;

	tmp = *begin;
	if (!tmp)
	{
		if (!(tmp = ft_memalloc(sizeof(t_fd))))
			return (-1);
		(*current) = ft_fill_struct(fd, tmp, ft_strnew(0));
		*begin = tmp;
		return (1);
	}
	while (*current)
	{
		if ((*current)->fd == fd)
			return (1);
		previous = (*current);
		*current = (*current)->next;
	}
	if (!(tmp = ft_memalloc(sizeof(t_fd))))
		return (-1);
	*current = ft_fill_struct(fd, tmp, ft_strnew(0));
	previous->next = *current;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*list;
	t_fd			*current;
	int				state;
	char			test[1];			
	
	*line = NULL;
	current = list;
	if (fd < 0 || (ft_get_fd_struct(fd, &list, &current)) < 0)
		return (-1);
	if (!current->str)
	{
		if(!(current->str = ft_strnew(0)))
			return (-1);
	}
	state = ft_read_buff(current, fd, line);	
//	dprintf(1, "line :  %s\n", *line);
	//dprintf(1, "current :  %s\n", current->str);
	return (state);
}
