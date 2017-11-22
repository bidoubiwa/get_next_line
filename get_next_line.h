/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:33:09 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/22 22:24:48 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

typedef struct 	s_fd
{
	size_t			fd;
	int				line;
	struct s_fd		next;
}				t_fd;	

int		get_next_line(const int fd, char **line);
#endif
