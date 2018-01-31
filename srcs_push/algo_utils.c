/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:34:55 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/22 14:26:21 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*move_add(t_tabs *tabs, t_size *size, char *add)
{
	ft_putstr(add);
	cal_operation(tabs, add, size);
	return (add);
}

int		refactor_list(t_tabs *tabs, t_size *size)
{
	int		min;
	int		max;
	int		new_tab[size->a];
	int		i;

	i = -1;
	min = tabs->a[0];
	max = tabs->a[0];
	while (++i < size->a)
		if (tabs->a[i] < min)
			min = tabs->a[i];
	i = -1;
	while (++i < size->a)
		if (tabs->a[i] > max)
			max = tabs->a[i];
	i = 1;
	min--;
	while (++min <= max)
		if (!(ft_inttabfind(tabs->a, size->a, min) == -1))
			new_tab[ft_inttabfind(tabs->a, size->a, min)] = i++;
	i++;
	while (--i >= 0)
		tabs->a[i] = new_tab[i];
	return (1);
}

char	*check_opti(t_tabs *tabs, t_size *size, char *ope)
{
	if (ft_strcmp(ope, "rb") == 10 && in_range(tabs->a, size, tabs->a[0], -1)
			& in_range(tabs->a, size, tabs->a[1], -1))
		return ("rr\n");
	else if (ft_strcmp(ope, "sb") == 10 &&
			in_range(tabs->a, size, tabs->a[0], -1) &&
			in_range(tabs->a, size, tabs->a[1], -1) && tabs->a[0] > tabs->b[1])
		return ("ss\n");
	return (ope);
}

int		in_range(int *tabs, t_size *size, int sizet, int nbr)
{
	int		i;

	if (sizet == -1)
		sizet = size->a;
	i = -1;
	if (nbr == -1)
	{
		while (++i < sizet)
			if (tabs[i] < size->total / 2 + size->span &&
					tabs[i] > size->total / 2 - size->span)
				return (1);
	}
	else
	{
		while (++i < sizet)
			if (nbr < size->total / 2 + size->span &&
					nbr > size->total / 2 - size->span)
				return (1);
	}
	return (0);
}

int		neer_in_range(t_size *size, int sizet, int *tab)
{
	int		span;

	span = 0;
	while (span <= sizet / 2)
	{
		if (in_range(tab, size, sizet, tab[span]))
			return (1);
		if (in_range(tab, size, sizet, tab[sizet - span]))
			return (-1);
		span++;
	}
	return (0);
}
