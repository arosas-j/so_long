/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.comr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:14:04 by arosas-j          #+#    #+#             */
/*   Updated: 2023/05/29 19:25:43 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = (*f)(lst->content);
	newnode->next = NULL;
	if (lst->next)
	{
		newnode->next = ft_lstmap(lst->next, (*f), (*del));
		if (!newnode->next)
		{
			(*del)(newnode->content);
			free(newnode);
			newnode = NULL;
		}
	}
	return (newnode);
}
