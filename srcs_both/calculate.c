/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:54:12 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/23 13:09:14 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_tab_sorted(int *tab, int size, int reverse)
{
	int		i;

	i = -1;
	if (size == 0)
		return (0);
	if (reverse)
	{
		while (++i < size - 1)
			if (tab[i] <= tab[i + 1] && !(tab[i] == get_lowest(tab, size)
						&& tab[i + 1] == get_max(tab, size)))
				return ((i > 0) ? -i : -1);
	}
	else
	{
		while (++i < size - 1)
			if (tab[i] >= tab[i + 1] && !(tab[i] == get_max(tab, size)
						&& tab[i + 1] == get_lowest(tab, size)))
				return ((i > 0) ? -i : -1);
	}
	return (1);
}

int		check_sorted(int *taba, t_size *size, int check_b)
{
	int		i;

	i = -1;
	if ((size->b > 0 && check_b) || size->a == 0)
		return (0);
	while (++i < size->a - 1)
		if (taba[i] >= taba[i + 1])
			return (0);
	return (1);
}

void	lch_operation(char *ope, int *taba, int *tabb, t_size *size)
{
	if (ft_strcmp(ope, "pa") == 10)
		push(tabb, taba, &size->b, &size->a);
	if (ft_strcmp(ope, "pb") == 10)
		push(taba, tabb, &size->a, &size->b);
	if (ft_strcmp(ope, "sa") == 10)
		swap(taba, size->a);
	if (ft_strcmp(ope, "sb") == 10)
		swap(tabb, size->b);
	if (ft_strcmp(ope, "ss") == 10)
		swap_both(taba, tabb, size);
	if (ft_strcmp(ope, "ra") == 10)
		rotate(taba, size->a, 0);
	if (ft_strcmp(ope, "rb") == 10)
		rotate(tabb, size->b, 0);
	if (ft_strcmp(ope, "rr") == 10)
		rotate_both(taba, tabb, size, 0);
	if (ft_strcmp(ope, "rra") == 10)
		rotate(taba, size->a, 1);
	if (ft_strcmp(ope, "rrb") == 10)
		rotate(tabb, size->b, 1);
	if (ft_strcmp(ope, "rrr") == 10)
		rotate_both(taba, tabb, size, 1);
}

int		cal_operation(t_tabs *tabs, char *ope, t_size *size)
{
	int		i;

	i = 0;
	while (*(ope + i))
	{
		lch_operation(ope + i, tabs->a, tabs->b, size);
		if (tabs->display == 1)
		{
			ft_putstr("TABLEAU A\n");
			ft_inttabdisplay(tabs->a, size->a);
			ft_putstr("\n");
			ft_putstr("TABLEAU B\n");
			ft_inttabdisplay(tabs->b, size->b);
			ft_putstr("\n");
		}
		while (*(ope + i) != '\n' && *(ope + i))
			i++;
		if (*(ope + i))
			i++;
	}
	return (check_sorted(tabs->a, size, 1));
}
