/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:12:40 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/29 18:02:12 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_next_prev(int *tab, int size, int current, int way)
{
	int		i;

	i = -1;
	if (way)
	{
		while (++current <= get_max(tab, size) && (i = -1))
			while (i < size - 1)
				if (tab[++i] == current)
					return (tab[i]);
	}
	else
	{
		while (--current >= get_lowest(tab, size) && (i = -1))
			while (i < size - 1)
				if (tab[++i] == current)
					return (tab[i]);
	}
	return (0);
}

int		get_lowest(int *tab, int size)
{
	int		i;
	int		min;

	min = tab[0];
	i = 0;
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int		get_max(int *tab, int size)
{
	int		i;
	int		max;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int		get_pos(int *tab, int size, int nbr)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

int		get_len_to_top(int *tab, int size, int nbr)
{
	if (get_pos(tab, size, nbr) > size / 2)
		return (size - get_pos(tab, size, nbr));
	else
		return (get_pos(tab, size, nbr));
}
