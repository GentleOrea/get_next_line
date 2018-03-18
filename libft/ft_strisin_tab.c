/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisin_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:16:11 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/01 12:35:07 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisin_tab(char *tofind, char **tab)
{
	size_t		i;

	i = 0;
	while (tab[i] && !ft_strisin(tofind, tab[i]))
		i++;
	return (tab[i] ? 0 : 1);
}
