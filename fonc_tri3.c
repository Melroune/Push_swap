/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_tri3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 00:05:56 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/25 00:06:31 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_3(t_swap **a, t_swap **b, t_op *opt)
{
	t_swap	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->data < tmp->next->data)
				i = 1;
			tmp = tmp->next;
		}
		if (i != 1)
		{
			ft_putstr("ra ");
			ft_rotate(a);
			if (opt->v == 1)
				pbonus_tpt(a, b, opt);
			opt->ra++;
		}
	}
	return (0);
}

int			is_2_fln(t_swap **a, t_swap **b, t_op *opt)
{
	ft_putstr("rra ");
	ft_rev_rotate(a);
	if (opt->v == 1)
		pbonus_tpt(a, b, opt);
	ft_putstr("rra ");
	ft_rev_rotate(a);
	if (opt->v == 1)
		pbonus_tpt(a, b, opt);
	opt->rra = 2;
	ft_putstr("sa ");
	ft_swap(a);
	if (opt->v == 1)
		pbonus_tpt(a, b, opt);
	opt->sa = 1;
	ft_putstr("ra ");
	ft_rotate(a);
	if (opt->v == 1)
		pbonus_tpt(a, b, opt);
	ft_putstr("ra");
	ft_rotate(a);
	opt->ra = 2;
	if (opt->v == 1)
		pbonus_tpt(a, b, opt);
	return (0);
}

int			is_2_last(t_swap **a, t_swap **b, t_op *opt)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = *a;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp2 = tmp;
		tmp = *a;
		while (tmp->next != tmp2)
		{
			if (tmp->data > tmp->next->data)
				return (2);
			tmp = tmp->next;
		}
		if (tmp->data > tmp2->data)
		{
			is_2_fln(a, b, opt);
			return (1);
		}
	}
	return (0);
}
