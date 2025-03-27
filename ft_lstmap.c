/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornil <acornil@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:28:19 by acornil           #+#    #+#             */
/*   Updated: 2022/01/26 11:31:40 by acornil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*firstelem;

	firstelem = NULL;
	while (lst)
	{
		res = ft_lstnew((*f)(lst->content));
		if (!res)
		{
			ft_lstclear(&firstelem, del);
			return (NULL);
		}
		ft_lstadd_back(&firstelem, res);
		lst = lst->next;
	}
	return (firstelem);
}
