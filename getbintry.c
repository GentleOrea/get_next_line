/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:48:02 by ygarrot           #+#    #+#             */
/*   Updated: 2018/02/24 13:01:59 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		chachr(char *str, size_t max_len)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (i < max_len && str[i] != '\n')
		i++;
	return (i);
}

static t_gnl *get_fd(t_gnl *list, int fd)
{
	if (list->fd == fd)
	{
		!list->buf ? list->buf = ft_strnew(1) : 0;
		list->len = 0;
		return (list->buf ? list : NULL);
	}
	while (list->next && list->next->fd != fd)
		list = list->next;
	if (list->next)
		return (list->next);
	if (!(list->next = (t_gnl*)malloc(sizeof(t_gnl)))
		|| !(list->next->buf = ft_strnew(1)))
		return (NULL);
	list->next->fd = fd;
	list->next->len = 0;
	return ((list->next->next = NULL)  ? list->next : list->next);
}


static char		*initline(t_gnl *lst)
{
	size_t	i;
	size_t	i2;
	char	*temp;

	printf("\n%zu\n",lst->len);
	i = chachr(lst->buf, lst->len);
	lst->len -= (i + 1);
	if (!(temp = ft_strnew(i)))
		return (NULL);
	ft_strncat(temp, lst->buf, i);
	i2 = 0;
	while (i2 < lst->len)
	{
		lst->buf[i2] = lst->buf[(i + 1) + i2];
		printf("(%d)", (int)((i+1) + i2));
		i2++;
	}
	printf("%d\n",(int)i2);
	lst->buf[i2] = '\0';
	lst->buf = ft_realloc(lst->buf, lst->len);
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	gl;
	t_gnl			*lst;
	int				ret;
	int				i;

	lst = NULL;
	gl.fd = -1;
	if (!(gl.buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (BUFF_SIZE < 1 || !line || fd < 0 || (i = 0) 
		|| !(lst = get_fd(&gl, fd)) || !lst->buf)
		return (lst && !lst->buf ? 0 : -1);
	while (!i && (ret = read(fd, gl.buf, BUFF_SIZE)) > 0)
	{
		i = chachr(gl.buf, ret) < ret;
		lst->len += ret;
		lst->buf = ft_realloc(lst->buf, lst->len);
		ft_strncat(lst->buf, gl.buf, ret);
	}
	if (ret < 0)
		return (-1);
	if (lst->len < 1 || !*lst->buf)
		return (0);
	return ((*line = initline(lst)) ? 1 : -1);
}
