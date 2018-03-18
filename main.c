/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:25:54 by ygarrot           #+#    #+#             */
/*   Updated: 2018/02/24 13:00:55 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	int ret;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n",ret, line);
		ft_memdel((void**)&line);
	}
	return (0);
}
