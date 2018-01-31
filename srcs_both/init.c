/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:51:25 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/23 14:27:11 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_all(t_size **size, int len, t_tabs **tabs)
{
	len = (len < 0) ? -len : len;
	*size = (t_size *)malloc(sizeof(t_size));
	*tabs = (t_tabs *)malloc(sizeof(t_tabs));
	(*tabs)->a = (int *)malloc(sizeof(int) * len);
	(*tabs)->b = (int *)malloc(sizeof(int) * len);
	ft_inttabclr((*tabs)->a, len);
	ft_inttabclr((*tabs)->b, len);
}

t_size	*init_size(t_size *size, int argc, t_tabs **tabs, char *argv[])
{
	int		len;
	int		i;
	int		plus;

	i = 0;
	len = 0;
	plus = (ft_strcmp(argv[1], "-v") == 0
			|| ft_strcmp(argv[1], "-sv") == 0) ? 1 : 0;
	if ((argc > 2 && (!plus || argc > 3)) ||
			(argc == 2 && (int)ft_strlen(argv[1]) == 1))
		len = -argc + 1 + plus;
	else
	{
		while (i < (int)ft_strlen(argv[(plus) ? 2 : 1]))
			if (argv[(plus) ? 2 : 1][i++] == ' ')
				len++;
		len++;
	}
	malloc_all(&size, len, tabs);
	size->a = -len;
	len = (len < 0) ? -len : len;
	size->b = 0;
	size->total = len;
	size->span = size->total / 4;
	return (size);
}

int		free_all(t_size **size, t_tabs **tabs, int ret)
{
	free((*tabs)->a);
	free((*tabs)->b);
	free(*tabs);
	free(*size);
	*tabs = NULL;
	*size = NULL;
	return (ret);
}
