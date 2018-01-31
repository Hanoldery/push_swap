/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:30:30 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/22 14:00:55 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(int tabsrc[], int tabdst[], int *sizesrc, int *sizedst)
{
	int		i;

	i = *sizedst + 1;
	if (*sizesrc < 1)
		return ;
	while (--i > 0)
		tabdst[i] = tabdst[i - 1];
	tabdst[0] = tabsrc[0];
	i = -1;
	while (++i < *sizesrc)
		tabsrc[i] = tabsrc[i + 1];
	(*sizedst)++;
	(*sizesrc)--;
}

void		swap(int tab[], int size)
{
	int		tmp;

	tmp = 0;
	if (size < 2)
		return ;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void		rotate(int tab[], int size, int reverse)
{
	int		i;
	int		tmp;

	if (size < 2)
		return ;
	tmp = (reverse) ? tab[size - 1] : tab[0];
	i = (reverse) ? size : -1;
	if (reverse)
		while (--i > 0)
			tab[i] = tab[i - 1];
	else
		while (++i < size - 1)
			tab[i] = tab[i + 1];
	if (reverse)
		tab[0] = tmp;
	else
		tab[size - 1] = tmp;
}

void		swap_both(int taba[], int tabb[], t_size *size)
{
	swap(taba, size->a);
	swap(tabb, size->b);
}

void		rotate_both(int taba[], int tabb[], t_size *size, int reverse)
{
	rotate(taba, size->a, reverse);
	rotate(tabb, size->b, reverse);
}
