/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_bonnus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 22:24:18 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/18 22:24:29 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			pbonus_tpt(t_swap **a, t_swap **b, t_op *opt)
{
	if (opt->v == 1)
	{
		ft_putstr("\n");
		ft_putstr("a : ");
		print_list(a);
		ft_putstr("\n");
		ft_putstr("b : ");
		print_list(b);
		ft_putchar('\n');
	}
	return (0);
}

int			pbonus_nb(t_op *opt)
{
	if (opt->c == 1)
	{
		ft_putchar('\n');
		ft_putstr("sa : ");
		ft_putnbr(opt->sa);
		ft_putstr(" rra : ");
		ft_putnbr(opt->rra);
		ft_putstr(" pb : ");
		ft_putnbr(opt->pb);
		ft_putstr(" ra : ");
		ft_putnbr(opt->ra);
		ft_putstr(" pa : ");
		ft_putnbr(opt->pa);
		ft_putchar('\n');
	}
	return (0);
}

int			pbonus_nbglob(t_op *opt)
{
	if (opt->b == 1)
	{
		ft_putchar('\n');
		ft_putstr("global result : ");
		ft_putnbr(opt->sa + opt->rra + opt->pb + opt->ra + opt->pa);
		ft_putchar('\n');
	}
	return (0);
}

void		put_success(char *success)
{
	ft_putstr_fd("\033[32m", 2);
	ft_putstr_fd(success, 2);
	ft_putstr_fd("\033[0m\n", 2);
	exit(-1);
}
