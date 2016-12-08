/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:26:33 by meckhard          #+#    #+#             */
/*   Updated: 2016/05/21 10:26:40 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*newlist;

	new = f(lst);
	newlist = ft_lstnew(new->content, new->content_size);
	if (newlist == NULL)
		return (NULL);
	if (lst && f)
	{
		while (lst->next != NULL)
		{
			new = f(lst->next);
			newlist->next = ft_lstnew(new->content, new->content_size);
			lst = lst->next;
		}
		new = f(lst);
		newlist->next = ft_lstnew(new->content, new->content_size);
	}
	return (newlist);
}
