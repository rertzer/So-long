/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bermap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:26:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:10:39 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_load_bermap(t_sldata *sldata, t_list **lst, int fd, char *msg)
{
	get_next_line(-1 * fd);
	close(fd);
	ft_lstclear(lst, free);
	error_exit(sldata, msg);
}

void	load_bermap(t_sldata *sldata, int fd)
{
	int		i;
	t_list	*lst;
	t_list	*elem;

	lst = load_tmp_bermap(sldata, fd);
	sldata->bermap.map = malloc(sizeof(char *) * (sldata->bermap.size_y));
	if (NULL == sldata->bermap.map)
		error_load_bermap(sldata, &lst, fd, MALL);
	elem = lst;
	i = 0;
	while (elem)
	{
		sldata->bermap.map[i] = (char *)(elem->content);
		elem = elem->next;
		i++;
	}
	ft_lstclear(&lst, NULL);
}

t_list	*load_tmp_bermap(t_sldata *sldata, int fd)
{
	char	*line;
	t_list	*lst;
	t_list	*elem;

	line = get_next_line(fd);
	lst = NULL;
	if (NULL == line)
		error_load_bermap(sldata, &lst, fd, GNL_N);
	sldata->bermap.size_y = 0;
	sldata->bermap.size_x = ft_strlen(line) - 1;
	while (line)
	{
		if (line[sldata->bermap.size_x] == '\n')
			line[sldata->bermap.size_x] = '\0';
		elem = ft_lstnew(line);
		if (NULL == elem)
			error_load_bermap(sldata, &lst, fd, L_MAL);
		ft_lstadd_back(&lst, elem);
		if (line && (ft_strlen(line) != sldata->bermap.size_x))
			error_load_bermap(sldata, &lst, fd, LINE_S);
		line = get_next_line(fd);
		sldata->bermap.size_y += 1;
	}
	return (lst);
}
