/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 05:40:44 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/16 05:40:50 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap		*ft_create_elem(int data)
{
	t_swap	*new_elem;

	new_elem = (t_swap *)malloc(sizeof(t_swap));
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

void		ft_list_push_front(t_swap **begin_list, int data)
{
	t_swap	*new_elem;

	new_elem = ft_create_elem(data);
	if (*begin_list)
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
}

void		ft_list_push_back(t_swap **begin_list, long data)
{
	t_swap	*new_elem;
	t_swap	*tmp;

	new_elem = ft_create_elem((int)data);
	tmp = *begin_list;
	if (*begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
}

void		ft_delone(t_swap **begin)
{
	t_swap *tmp;

	tmp = *begin;
	if (tmp)
	{
		*begin = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}

void		ft_delend(t_swap **end)
{
	t_swap *tmp;
	t_swap *temp;

	tmp = *end;
	if (tmp->next == NULL)
		*end = NULL;
	else if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		temp = tmp;
		tmp = *end;
		while (tmp->next != temp)
			tmp = tmp->next;
		tmp->next = NULL;
		free(temp);
	}
}
