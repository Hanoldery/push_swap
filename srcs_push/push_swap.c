/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:37:09 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/22 19:18:25 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_tabs	*tabs;
	t_size	*size;

	size = NULL;
	if (argc < 2)
		return (ft_putstr_fdret("Error\n", 2, 0));
	size = init_size(size, argc, &tabs, argv);
	tabs->display = 0;
	if (!get_tab(tabs, size, argv, argc))
		return (free_all(&size, &tabs, ft_putstr_fdret("Error\n", 2, 0)));
	if (check_sorted(tabs->a, size, 0))
		return (free_all(&size, &tabs, ft_putstr_fdret("\n", 1, 1)));
	refactor_list(tabs, size);
	if (size->a < 22)
		get_algo_sml(tabs, size);
	else
		get_algo_lng(tabs, size);
	return (free_all(&size, &tabs, 1));
}
