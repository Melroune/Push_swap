/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sawp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 21:09:18 by akerkeb           #+#    #+#             */
/*   Updated: 2015/01/24 21:09:21 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_swap
{
	int				data;
	struct s_swap	*next;
}					t_swap;

typedef struct		s_op
{
	int				v;
	int				c;
	int				b;
	int				sa;
	int				rra;
	int				pb;
	int				ra;
	int				pa;
	int				end;
}					t_op;

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
int					ft_strequ(char const *s1, char const *s2);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
t_swap				*ft_create_elem(int data);
void				ft_list_push_front(t_swap **begin_list, int data);
void				ft_list_push_back(t_swap **begin_list, long data);
void				ft_delone(t_swap **begin);
void				ft_delend(t_swap **end);
void				ft_swap(t_swap **first);
void				ft_push(t_swap **first2, t_swap **first);
void				ft_rotate(t_swap **rotate);
void				ft_rev_rotate(t_swap **revrotate);
int					checkmin(t_swap **list);
int					checkorder(t_swap **list);
int					is_endoflist(t_swap **list);
void				print_list(t_swap **list);
int					er_doublon(t_swap **list);
void				put_error(char *error);
void				algotri(t_swap **a, t_swap **b, t_op *o);
void				algotri1(t_swap **a, t_swap **b, int smal, t_op *opt);
int					pbonus_tpt(t_swap **a, t_swap **b, t_op *opt);
int					pbonus_nb(t_op *opt);
void				init_opt(t_op *opt);
int					fill_options(int ac, char **av, t_op *options);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
void				put_success(char *success);
int					is_3(t_swap **a, t_swap **b, t_op *opt);
int					is_2_last(t_swap **a, t_swap **b, t_op *opt);
int					pbonus_nbglob(t_op *opt);

#endif
