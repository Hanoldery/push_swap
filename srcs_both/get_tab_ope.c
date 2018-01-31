/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:31:58 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/29 17:37:13 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_tab_from_first_arg(t_tabs *tabs, t_size *size, char *argv[])
{
	int			i;
	intmax_t	tmp;
	int			dsp;

	tmp = 0;
	i = 0;
	dsp = (tabs->display != 0) ? 2 : 1;
	while (++i < size->a + 1)
	{
		if (ft_strisnumber(argv[dsp]) < 1)
			return (0);
		tmp = ft_atoimax(argv[dsp]);
		if (tmp > (intmax_t)INT_MAX || tmp < (intmax_t)INT_MIN ||
					get_pos(tabs->a, i - 1, tmp) != -1)
			return (0);
		while (*argv[dsp] && *argv[dsp] != ' ')
			argv[dsp]++;
		if (*(argv[dsp] + 1))
			argv[dsp]++;
		tabs->a[i - 1] = tmp;
	}
	return (1);
}

int			get_tab_from_args(t_tabs *tabs, t_size *size, char *argv[], int ac)
{
	int			i;
	int			j;
	int			dsp;

	i = 0;
	j = -1;
	dsp = (tabs->display != 0) ? 2 : 1;
	(void)size;
	while (dsp < ac)
	{
		if (!ft_isnumber(argv[dsp]))
			return (0);
		if (ft_atoimax(argv[dsp]) > (intmax_t)INT_MAX ||
					ft_atoimax(argv[dsp]) < (intmax_t)INT_MIN ||
					get_pos(tabs->a, i, ft_atoimax(argv[dsp])) != -1)
			return (0);
		tabs->a[i] = ft_atoimax(argv[dsp]);
		while (*argv[dsp] && *argv[dsp] != ' ')
			argv[dsp]++;
		argv[dsp] = (*argv[dsp]) ? argv[dsp] + 1 : argv[dsp];
		dsp++;
		i++;
		j = -1;
	}
	return (1);
}

int			get_tab(t_tabs *tabs, t_size *size, char *argv[], int ac)
{
	int		i;

	i = 0;
	if (size->a > 0)
		i = (get_tab_from_args(tabs, size, argv, ac)) ? 1 : 0;
	else
	{
		size->a = -size->a;
		i = (get_tab_from_first_arg(tabs, size, argv)) ? 1 : 0;
	}
	return (i);
}

int			val_operation(char *rslt)
{
	int		i;

	i = 0;
	while (rslt[i])
	{
		if ((rslt[i] == 's' || rslt[i] == 'p') &&
				(rslt[i + 1] == 'a' || rslt[i + 1] == 'b' ||
				(rslt[i + 1] == 's' && rslt[i] == 's')))
			i += 2;
		else if (rslt[i] == 'r' &&
				(rslt[i + 1] == 'a' || rslt[i + 1] == 'b' ||
				rslt[i + 1] == 'r'))
		{
			i += (rslt[i] == 'r' && rslt[i + 1] == 'r' &&
					rslt[i + 2] && rslt[i + 2] != '\n') ? 3 : 2;
			if (!(rslt[i - 2] == 'r' &&
						(rslt[i - 1] == 'a' || rslt[i - 1] == 'b' ||
						rslt[i - 1] == 'r')))
				return (0);
		}
		if (rslt[i] != '\n')
			return (0);
		i = (rslt[i] == '\n') ? i + 1 : i;
	}
	return (1);
}

char		*get_operation(int *count)
{
	char	buff[500];
	char	*rslt;
	int		r;
	int		max;

	r = 0;
	rslt = NULL;
	max = 0;
	while ((r = read(0, buff, 500)) > 0)
	{
		buff[r] = '\0';
		rslt = ft_strjoinfreefirst(rslt, buff);
	}
	if ((int)ft_strlen(rslt) == 0)
		return ((char *)0);
	if (r < 0 || !val_operation(rslt))
		return ((char *)-1);
	r = 0;
	max = (int)ft_strlen(rslt);
	while (r++ < max)
		if (*(rslt + r) == '\n')
			(*count)++;
	return (rslt);
}
