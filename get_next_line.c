/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:32:27 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/23 16:16:32 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*get_fd(char *buf, const int fd, t_list **list, buf)
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
}*/

static char	*ft_check_old_buff(char *str, size_t *len)
{
	char	*new;

	if (str)
	{
		new = ft_strdup(str);
		*len = ft_strlen(str);
		return (new);
	}
	*len = 0;
	new = ft_strnew(0);
	return (new);	
}

int		get_next_line(const int fd, char **line)
{
	/*static	t_list	**fdptr;
	int		number;

	number = get_fd(fd, line);
	ft_putnbr((*fdptr)->fd);*/
	static char	*str;
	char		*new;
	char		buf[BUFF_SIZE];
	int			ret;
	int			i;
	size_t		len;

	new = ft_check_old_buff(str, &len);
	dprintf(1,"old buf : %s\n", new);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		while (buf[i] && buf[i] != EOF && buf[i] != '\n' && i < BUFF_SIZE)
		{
			len++;
			i++;
		}
		dprintf(1, "buf : %s i : %d\n", buf, i);
		if (!buf[i] || buf[i] == EOF || i == BUFF_SIZE)
		{
			str = ft_strnew(len);
			ft_strlcat(ft_strcpy(str, new),buf, len + 1);
			new = str;
			dprintf(1,"evolution new : %s\n", new);
		}
		else 
			break;
	}
	str = ft_strnew(len);
	ft_strlcat(ft_strcpy(str, new),buf, len + 1);
	new = str;
	*line = new;
	dprintf(1, "new : %s\n", new);
	if (buf[i] == '\n')
		i++;
	if (i < BUFF_SIZE && buf[i + 1])
		str = ft_strdup(&buf[i]);
	else
		str = NULL;
	dprintf(1,"static : %s \n", str);

	return (0);
}
