/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sawp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 18:35:51 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/05 06:19:20 by ikerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		algotri(t_swap **a, t_swap **b, t_op *opt)
{
	int		smal;
	int		i;

	i = 0;
	while (checkorder(a) != 0)
	{
		smal = checkmin(a);
		if (i != 0 && opt->v != 1)
			ft_putchar(' ');
		algotri1(a, b, smal, opt);
		pbonus_tpt(a, b, opt);
		i++;
	}
}

void		algotri1(t_swap **a, t_swap **b, int smal, t_op *opt)
{
	if (smal == 2)
	{
		ft_putstr("sa");
		ft_swap(a);
		opt->sa++;
	}
	else if (smal == is_endoflist(a))
	{
		ft_putstr("rra");
		ft_rev_rotate(a);
		opt->rra++;
	}
	else if (smal == 1)
	{
		ft_putstr("pb");
		ft_push(a, b);
		opt->pb++;
	}
	else
	{
		ft_putstr("ra");
		ft_rotate(a);
		opt->ra++;
	}
}

void		pilea(t_swap **a, char **av, int i)
{
	while (av[i] != NULL)
	{
		if (ft_strequ(av[i], ft_itoa(ft_atoi(av[i]))))
			ft_list_push_back(a, ft_atoi(av[i]));
		else if (ft_atoi(av[i]) == 0)
			ft_list_push_back(a, ft_atoi(av[i]));
		else
			put_error("Error : Overflow");
		i++;
	}
}

int			algotri2(t_swap **a, t_swap **b, t_op *opt)
{
	if ((*b))
	{
		while ((*b))
		{
			if (opt->v != 1)
				ft_putstr(" pa");
			else
				ft_putstr("pa");
			ft_push(b, a);
			pbonus_tpt(a, b, opt);
			opt->pa++;
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_swap	*a;
	t_swap	*b;
	t_op	opt;

	if (ac == 1)
		put_error("Error");
	a = NULL;
	b = NULL;
	init_opt(&opt);
	pilea(&a, av, fill_options(ac, av, &opt));
	if (er_doublon(&a) != 0)
		put_error("Error : Duplicate number");
	if (checkorder(&a) == 0)
		put_success("success :everything its ok");
	if (av[3])
		is_3(&a, &b, &opt);
	if (ac != 3)
		is_2_last(&a, &b, &opt);
	algotri(&a, &b, &opt);
	algotri2(&a, &b, &opt);
	pbonus_nb(&opt);
	pbonus_nbglob(&opt);
	return (0);
}
