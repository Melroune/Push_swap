/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 23:53:08 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/25 12:23:03 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_option(char c)
{
	ft_putstr_fd("push_swap: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: push_swap [-bcv] [numbers ...]\n", 2);
}

int		check_options(char c, t_op *options)
{
	if (c == 'v')
		options->v = 1;
	else if (c == 'c')
		options->c = 1;
	else if (c == 'b')
		options->b = 1;
	else if (c == '-' && options->end == 0)
		options->end = 1;
	else if (c == '-' && options->end == 0)
		options->end = 1;
	else
	{
		print_error_option(c);
		return (0);
	}
	return (1);
}

void	init_opt(t_op *opt)
{
	opt->v = 0;
	opt->c = 0;
	opt->sa = 0;
	opt->rra = 0;
	opt->pb = 0;
	opt->ra = 0;
	opt->pa = 0;
	opt->end = 0;
}

int		go_option(char *str, t_op *options)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && options->end == 1)
		{
			print_error_option('-');
			exit(-1);
		}
		if (check_options(str[i], options) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		fill_options(int ac, char **av, t_op *options)
{
	int i;
	int ret;

	i = 1;
	while (i < ac && options->end == 0)
	{
		if (!ft_strncmp(av[i], "-", 1) && ft_strlen(av[i]) > 1)
		{
			if ((ret = go_option(av[i], options)) == 0)
				return (0);
		}
		else
			return (i);
		i++;
	}
	return (i);
}
