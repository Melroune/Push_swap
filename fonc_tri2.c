/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_tri2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 22:19:47 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/18 22:19:50 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			checkmin(t_swap **list)
{
	int		smal;
	t_swap	*tmp;
	int		i;

	tmp = *list;
	i = 1;
	smal = tmp->data;
	while (tmp)
	{
		if (tmp->data < smal)
		{
			smal = tmp->data;
		}
		tmp = tmp->next;
	}
	tmp = *list;
	while (tmp)
	{
		if (tmp->data == smal)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int			checkorder(t_swap **list)
{
	t_swap	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		print_list(t_swap **list)
{
	t_swap *temp;
	t_swap *temp2;

	temp = *list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		ft_putnbr(temp->data);
		if (temp != *list)
			ft_putchar(' ');
		temp2 = temp;
		while (temp != *list)
		{
			temp = *list;
			while (temp->next != temp2)
				temp = temp->next;
			ft_putnbr(temp->data);
			if (temp != *list)
				ft_putchar(' ');
			temp2 = temp;
		}
	}
}

int			er_doublon(t_swap **list)
{
	t_swap *tmp;
	t_swap *doublon;

	tmp = *list;
	if (tmp)
	{
		while (tmp)
		{
			doublon = tmp->next;
			while (doublon)
			{
				if (tmp->data == doublon->data)
					return (1);
				doublon = doublon->next;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

void		put_error(char *error)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(-1);
}
