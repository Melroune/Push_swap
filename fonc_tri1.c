/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_tri1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 22:17:31 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/18 22:17:35 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(t_swap **first)
{
	int		tmp;

	if (*first && (*first)->next)
	{
		tmp = (*first)->data;
		(*first)->data = (*first)->next->data;
		(*first)->next->data = tmp;
	}
}

void		ft_push(t_swap **first2, t_swap **first)
{
	if (*first2)
	{
		if (*first)
		{
			ft_list_push_front(first, (*first2)->data);
		}
		else
		{
			*first = ft_create_elem((*first2)->data);
		}
		ft_delone(first2);
	}
}

void		ft_rotate(t_swap **rotate)
{
	t_swap *vi;

	vi = *rotate;
	if ((*rotate) != NULL)
	{
		ft_list_push_back(rotate, vi->data);
		ft_delone(rotate);
	}
}

void		ft_rev_rotate(t_swap **revrotate)
{
	t_swap *vi;

	vi = *revrotate;
	if ((*revrotate) != NULL)
	{
		while (vi->next != NULL)
			vi = vi->next;
		ft_list_push_front(revrotate, vi->data);
		ft_delend(revrotate);
	}
}

int			is_endoflist(t_swap **list)
{
	t_swap	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
