/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dlbint_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:05:02 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/03 12:45:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_dlbint_tab(int **tab, int size, int size2)
{
	int		temp;
	int		temp2;

	temp = 0;
	if (!tab)
		return ;
	while (temp < size)
	{
		temp2 = 0;
		while (temp2 < size2)
			ft_putnbr(tab[temp][temp2]);
		temp++;
	}
}
