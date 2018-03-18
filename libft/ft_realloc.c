/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:08:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/31 12:12:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *buf;

	buf = NULL;
	if (!size && ptr)
	{
		ft_memdel((void**)&ptr);
		return (NULL);
	}
	else if (!ptr)
		return (ptr = (unsigned char*)malloc(size * sizeof(unsigned char)));
	else
	{
		buf = ft_strdup(ptr);
		ft_memdel((void**)&ptr);
		if (!buf || !(ptr = (char*)malloc(size * sizeof(unsigned char))))
		{
			ft_memdel((void**)&buf);
			return (NULL);
		}
		ft_strcpy(ptr, buf);
		ft_memdel((void**)&buf);
	}
	return (ptr);
}
