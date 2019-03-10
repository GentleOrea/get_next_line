/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:48:02 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/07 16:03:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		next_nl(char *str, int len)
{
	int		i;
	static	int	last = 0;

	i = 0;
	if (len == -1)
		return (last);
	if (!str)
		return (0);
	while (i < len && str[i] != '\n')
		i++;
	last = i;
	return (i);
}

static t_gnl	*get_fd(t_gnl *list, int fd)
{
	if (list->fd == fd)
	{
		!list->buf ? list->buf = ft_strnew(1) : 0;
		return (list->buf ? list : NULL);
	}
	while (list->next && list->next->fd != fd)
		list = list->next;
	if (list->next)
		return (list->next);
	if (!(list->next = (t_gnl*)ft_memalloc(sizeof(t_gnl)))
			|| !(list->next->buf = ft_strnew(1)))
		return (NULL);
	list->next->fd = fd;
	list->next->len = 1;
	return (list->next);
}

static char		*initline(t_gnl *lst)
{
	int		i;
	size_t	len;
	char	*temp;

	i = next_nl(lst->buf, lst->len);
	if (!(temp = ft_strnew(i)))
		return (NULL);
	ft_memcpy(temp, lst->buf, i);
	len = lst->len - i;
	ft_printf("i %d %d\n", i, lst->len);
	ft_printf("len + 1 %d %d\n", len + 1, lst->len);
	ft_memcpy(lst->buf, &lst->buf[i + 1], len);
	lst->len -= i;
	lst->buf = ft_realloc(lst->buf, len, lst->len + 1);
	/* ft_printf("temp %d %d\n", i, lst->len); */
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	gl;
	t_gnl			*lst;
	int				ret;
	int				i;

	gl.fd = -1;
	lst = NULL;
	if (!gl.buf && !(gl.buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (BUFF_SIZE < 1 || !line || fd < 0 || (i = 0)
			|| !(lst = get_fd(&gl, fd)) || !lst->buf)
		return (lst && !lst->buf ? 0 : -1);
	if (ft_memchr(lst->buf, '\n', lst->len) && (*line = initline(lst)))
		return (next_nl(0,-1));
	while (!i && (ret = read(fd, gl.buf, BUFF_SIZE)) > 0)
	{
		/* ft_printf("%d %d\n", lst->len + ret + 1, lst->len); */
		lst->buf = ft_realloc(lst->buf, (lst->len + ret + 1), lst->len);
		ft_memcpy(&lst->buf[lst->len], gl.buf, ret);
		lst->len += ret + 1;
		i = next_nl(gl.buf, ret) < ret;
	}
	if (lst->len <= 0 && (ret < 0 || !*lst->buf))
		return (ret < 0 ? -1 : 0);
	return ((*line = initline(lst)) ? next_nl(0, -1) : -1);
}
