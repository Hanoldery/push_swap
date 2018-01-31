/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:37:00 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/23 14:27:54 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calculate_and_display(t_tabs *tabs, t_size *size, char *ope, int count)
{
	ope = get_operation(&count);
	if (ope == (char *)0 || ope == (char *)-1)
	{
		if (ope == (char *)-1)
			return (ft_putstr_fdret("Error\n", 2, 0));
		if (check_sorted(tabs->a, size, 1))
			return (ft_putstr_fdret("OK\n", 1, 1));
		else
			return (ft_putstr_fdret("KO\n", 1, 1));
	}
	if (tabs->display)
		ft_putstr(ope);
	if (cal_operation(tabs, ope, size))
	{
		if (tabs->display != 0)
		{
			ft_putstr("Nombre de coups :\n");
			ft_putnbr(count);
			ft_putstr("\n");
		}
		return (ft_putstr_fdret("OK\n", 1, 1));
	}
	if (tabs->display)
		ft_inttabdisplay(tabs->a, size->a);
	return (ft_putstr_fdret("KO\n", 1, 1));
}

int		main(int argc, char *argv[])
{
	t_tabs		*tabs;
	char		*ope;
	t_size		*size;
	int			count;

	count = 0;
	size = NULL;
	ope = NULL;
	tabs = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2 && (ft_strcmp(argv[1], "-v") == 0
					|| ft_strcmp(argv[1], "-sv") == 0))
		return (1);
	size = init_size(size, argc, &tabs, argv);
	if (ft_strcmp(argv[1], "-v") == 0)
		tabs->display = 1;
	else if (ft_strcmp(argv[1], "-sv") == 0)
		tabs->display = -1;
	else
		tabs->display = 0;
	if (argc < 2 || !get_tab(tabs, size, argv, argc))
		return (free_all(&size, &tabs, ft_putstr_fdret("Error\n", 2, 0)));
	return (free_all(&size, &tabs,
				calculate_and_display(tabs, size, ope, count)));
}
