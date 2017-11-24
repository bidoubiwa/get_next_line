/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:32:27 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/24 16:29:13 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_info	*get_fd(const int fd, t_info **info)
{
	if(!(*info = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	(*info)->str = *str;
	(*info)->i = 0;
	(*info)->len = 0;
	(*info)->ret = 0;
	/*while ((*list))
	{
		if ((*list)->content_size == fd)
			return ((*list)->content);
	}
	tmp = ft_lstnew(fd, 0);
	last = ft_lstlast(t_list *list);
	last->next = tmp;*/
	return (*info);
}


static char	*ft_check_old_buff(char *str, size_t *len, t_info *inf, char **line)
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
			{
				new = ft_strsub(str,0, i);
				if (str[i + 1] == '\0')
					tmp = ft_strnew(0);
				else
					tmp = ft_strsub(str, i + 1, ft_strlen(str) - i - 1);
				free(str);
				str = tmp;
				inf->ret = 1;
				*line = str;
				return (new);
			}
			i++;
		}
		new = ft_strdup(str);
		*len = ft_strlen(str);
		free(str);
		str = NULL;
		return (new);
	}
	*len = 0;
	new = ft_strnew(0);
	return (new);	
}

int		get_next_line(const int fd, char **line)
{

	//t_list	**file;
	t_list		*i;
	static char	*str;
	char		*new;
	char		buf[BUFF_SIZE];
	int			ret;
	int			i;
	size_t		len;

	if (fd == -1)
		return (0);
	i = get_fd(fd, list, &i);
	new = ft_check_old_buff(str, &len, i, line);
	if (ret)
	{
		str = *line;
		*line = new;
		return (1);
	}
	while ((i->ret = read(fd, buf, BUFF_SIZE)))
	{
		i->i = 0;
		while (buf[i->i] && buf[i->i] != EOF && buf[i->i] != '\n' && i->i < i->ret)
		{
			i->len++;
			i->i++;
		}
		if (!buf[i] || buf[i] == EOF || i == BUFF_SIZE)
		{
			str = ft_strnew(i->len);
			ft_strlcat(ft_strcpy(i->str, new), buf, i->len + 1);
			new = str;
		}
		else
			break ;
	}
	str = ft_strnew(i->len);
	ft_strlcat(ft_strcpy(str, new), buf, i->len + 1);
	new = str;
	if (buf[i->i] == '\n')
		i->i++;
	if (i->i < BUFF_SIZE && buf[i->i + 1])
		str = ft_strsub(&buf[i->i], 0, i->ret - i->i);
	else
		str = NULL;
	*line = new;
	return (0);
}
