/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:35:23 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/29 19:46:11 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_algo_three(t_tabs *tabs, t_size *size)
{
	if (size->a == 2)
		move_add(tabs, size, "ra\n");
	else if (tabs->a[0] < tabs->a[1] && tabs->a[1] > tabs->a[2]
			&& get_lowest(tabs->a, size->a) == tabs->a[0])
		move_add(tabs, size, "rra\nsa\n");
	else if (tabs->a[0] > tabs->a[1] && tabs->a[1] < tabs->a[2]
			&& get_max(tabs->a, size->a) == tabs->a[2])
		move_add(tabs, size, "sa\n");
	else if (tabs->a[0] < tabs->a[1] && tabs->a[1] > tabs->a[2])
		move_add(tabs, size, (get_next_prev(tabs->a, size->a, tabs->a[0], 1) ==
					tabs->a[1]) ? "rra\n" : "rra\nsa\n");
	else if (tabs->a[0] > tabs->a[1] && tabs->a[1] > tabs->a[2])
		move_add(tabs, size, "ra\nsa\n");
	else if (tabs->a[0] > tabs->a[1] && tabs->a[1] < tabs->a[2])
		move_add(tabs, size, "ra\n");
	if (check_tab_sorted(tabs->a, size->a, 0) > 0 &&
			get_max(tabs->a, size->a) != tabs->a[1])
		return ;
}

int			get_algo_sml(t_tabs *tabs, t_size *size)
{
	int		i;
	int		min;

	i = 0;
	min = 1;
	while (min <= get_max(tabs->a, size->a) - 3)
	{
		while (get_len_to_top(tabs->a, size->a, min) > 0)
			move_add(tabs, size, (get_pos(tabs->a, size->a, min) >
						size->a / 2) ? "rra\n" : "ra\n");
		if (check_sorted(tabs->a, size, 0) > 0)
			break ;
		if (tabs->a[0] != get_max(tabs->a, size->a))
			move_add(tabs, size, "pb\n");
		min++;
	}
	get_algo_three(tabs, size);
	while (size->b > 0)
		move_add(tabs, size, "pa\n");
	return (1);
}

void		pre_sort_lng(t_tabs *tabs, t_size *size)
{
	while (in_range(tabs->a, size, -1, -1) && size->a > 3)
	{
		if (in_range(tabs->a, size, -1, tabs->a[0])
				&& tabs->a[0] != get_max(tabs->a, size->a))
		{
			size->span = size->total / 7;
			move_add(tabs, size, (in_range(tabs->a, size, -1, tabs->a[0])) ?
					"pb\nrb\n" : "pb\n");
			size->span = size->total / 4;
		}
		else
			move_add(tabs, size, "ra\n");
	}
	size->span = size->total / 3;
	while (in_range(tabs->a, size, -1, -1) && size->a > 3)
	{
		if (in_range(tabs->a, size, -1, tabs->a[0])
				&& tabs->a[0] != get_max(tabs->a, size->a))
			move_add(tabs, size, "pb\n");
		else
			move_add(tabs, size, "ra\n");
	}
	while (size->a > 0)
		move_add(tabs, size, "pb\n");
	size->span = (size->total / 200 > 1) ? size->total / 50 : 7;
}

void		get_algo_lng(t_tabs *t, t_size *s)
{
	pre_sort_lng(t, s);
	while (s->b > 0)
	{
		while (in_range(t->b, s, s->b, -1))
		{
			if (in_range(t->b, s, s->b, t->b[0]))
			{
				if (get_next_prev(t->a, s->a, t->b[0], 0))
					while (get_next_prev(t->a, s->a, t->b[0], 0)
							!= t->a[s->a - 1] && s->a > 1)
						move_add(t, s, (get_pos(t->a, s->a, get_next_prev(t->a,
							s->a, t->b[0], 0)) > s->a / 2) ? "rra\n" : "ra\n");
				if (get_next_prev(t->a, s->a, t->b[0], 1))
					while (get_next_prev(t->a, s->a, t->b[0], 1)
						!= t->a[0] && s->a > 1)
						move_add(t, s, (get_pos(t->a, s->a, get_next_prev(t->a,
							s->a, t->b[0], 1)) > s->a / 2) ? "rra\n" : "ra\n");
				move_add(t, s, "pa\n");
			}
			move_add(t, s, (neer_in_range(s, s->b, t->b) > 0) ?
					"rb\n" : "rrb\n");
		}
		s->span += (s->total / 50 > 1) ? s->total / 50 : s->total / 20;
	}
	get_algo_lng_rebase(t, s);
}

void		get_algo_lng_rebase(t_tabs *tabs, t_size *size)
{
	while (tabs->a[0] != get_lowest(tabs->a, size->a))
	{
		move_add(tabs, size, (get_pos(tabs->a, size->a,
			get_lowest(tabs->a, size->a)) < size->a / 2) ?
			"ra\n" : "rra\n");
	}
}
