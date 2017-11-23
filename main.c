/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:41:08 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/23 16:00:21 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// A NE PAS RENDRE
#include "get_next_line.h"

int		main(int ac, char	**av)
{
	char	**str;
	char	*s;
	int		fd;

	str = &s;
	s = ft_strnew(100);
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	get_next_line(fd,str);
	dprintf(1,"res : %s \n",*str);
	get_next_line(fd,str);
	dprintf(1,"res : %s \n",*str);
	get_next_line(fd,str);
	dprintf(1,"res : %s \n",*str);

	return (0);
}
