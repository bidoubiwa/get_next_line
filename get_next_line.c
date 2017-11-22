/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:32:27 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/22 23:11:09 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 32

char	*get_fd(char *buf, const int fd, t_list **list, buf)
{
	t_fd 	*tmp;
	t_fd	*last;

	if (list == NULL)
	{
		list = ft_lstnew(buf, fd);
		return (list->);
	}
	while ((*list))
	{
		if ((*list)->content_size == fd)
			return ((*list)->content);
	}
	tmp = ft_lstnew(fd, 0);
	last = ft_lstlast(t_list *list);
	last->next = tmp;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	**fdptr;
	int		number;

	number = get_fd(fd, line);
	ft_putnbr((*fdptr)->fd);
	static int x;
	
	

		
	return (0);
}
