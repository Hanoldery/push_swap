/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:33:13 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/01/31 17:57:51 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef int *(*t_ope)(int *a, int *b, int size);

typedef struct	s_tabs {
	int		*a;
	int		*b;
	int		display;
}				t_tabs;

typedef struct	s_size {
	int		a;
	int		b;
	int		total;
	int		span;
}				t_size;

typedef struct	s_lst {
	int				*tab;
	int				sorted;
	int				size;
	int				seperated;
	int				inside_lst;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

int				get_tab(t_tabs *tabs, t_size *size, char *argv[], int ac);

char			*get_operation(int *count);
int				val_operation(char *rslt);
int				cal_operation(t_tabs *tabs, char *ope, t_size *size);
int				check_sorted(int *tab, t_size *size, int check_b);
int				check_tab_sorted(int *tab, int size, int reverse);
t_size			*init_size(t_size *size, int ac, t_tabs **tabs, char *av[]);
int				free_all(t_size **size, t_tabs **tabs, int ret);

char			*move_add(t_tabs *tabs, t_size *size, char *add);
int				refactor_list(t_tabs *tabs, t_size *size);
int				neer_way_out(int *tab, int size);
char			*check_opti(t_tabs *tabs, t_size *size, char *ope);
int				in_range(int *tabs, t_size *size, int sizet, int nbr);
int				neer_in_range(t_size *size, int sizet, int *tab);

int				get_algo_sml(t_tabs *tabs, t_size *size);
void			get_algo_lng(t_tabs *tabs, t_size *size);
void			get_algo_lng_rebase(t_tabs *tabs, t_size *size);
int				get_lowest(int *tab, int size);
int				get_max(int *tab, int size);
int				get_next_prev(int *tab, int size, int current, int way);
int				get_pos(int *tab, int size, int nbr);
int				get_len_to_top(int *tab, int size, int nbr);

void			push(int tabsrc[], int tabdst[], int *sizesrc, int *sizedst);
void			swap(int tab[], int size);
void			swap_both(int taba[], int tabb[], t_size *size);
void			rotate(int tab[], int size, int reverse);
void			rotate_both(int taba[], int tabb[], t_size *size, int reverse);

#endif
