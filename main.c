/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:41:08 by cvermand          #+#    #+#             */
/*   Updated: 2017/11/26 23:44:20 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// A NE PAS RENDRE
#include "get_next_line.h"

int		main(int ac, char	**av)
{
	char	*str;
	int		fd;
	int		fd2;
	int 	ret;

	if (ac == 1)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if ((fd2 = open(av[2], O_RDONLY)) == -1)
		return (0);
	ret = get_next_line(fd,&str);
	dprintf(1,"res : %s, ret : %d\n",str, ret);
	ret = get_next_line(fd,&str);
	dprintf(1,"res : %s, ret : %d\n",str, ret);
	ret = get_next_line(fd,&str);
	dprintf(1,"res : %s, ret : %d\n",str, ret);
	ret = get_next_line(fd2,&str);
	dprintf(1,"res : %s, ret: %d\n",str, ret);
	ret = get_next_line(fd,&str);
	dprintf(1,"res : %s, ret : %d\n",str, ret);
	ret = get_next_line(fd,&str);
	dprintf(1,"res : %s, ret: %d\n",str, ret);
	ret = get_next_line(fd2,&str);
	dprintf(1,"res : %s, ret: %d\n",str, ret);
	ret = get_next_line(fd,&str);
	dprintf(1,"res : %s, ret: %d\n",str, ret);
	ret = get_next_line(fd2,&str);
	dprintf(1,"res : %s, ret : %d\n",str, ret);

	return (0);
}
