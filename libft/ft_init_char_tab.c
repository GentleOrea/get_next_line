/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_char_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 11:51:23 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/03 12:44:23 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_init_double_tab(int size, int size2)
{
	char		**emptytab;

	if (!(emptytab = (char**)malloc((size + 1) * sizeof(char*))))
		return (NULL);
	while (size--)
	{
		if (!(emptytab[size] = (char*)malloc((size2 + 1) * sizeof(char))))
		{
			ft_free_dblechar_tab(emptytab);
			return (NULL);
		}
	}
	return (emptytab);
}
