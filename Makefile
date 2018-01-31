# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 14:11:45 by pgerbaud          #+#    #+#              #
#    Updated: 2018/01/19 19:51:07 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap
SRCS_PUSH = push_swap \
			get_algo \
			algo_utils
OBJS_PUSH = $(foreach push, $(SRCS_PUSH),srcs_push/$(push).o)

NAME_CHECK = checker
SRCS_CHECK = checker
OBJS_CHECK = $(foreach check, $(SRCS_CHECK),srcs_check/$(check).o)

SRCS_BOTH =  calculate \
			 get_tab_ope \
			 operation \
			 get_data \
			 init
OBJS_BOTH = $(foreach both, $(SRCS_BOTH),srcs_both/$(both).o)

LIB = libft
INCLUDE = includes $(LIB)/includes

CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(foreach path, $(INCLUDE), -I$(path))



all: $(NAME_PUSH) $(NAME_CHECK)

re : fclean all

srcs_check/%.o: srcs_check/%.c
	gcc  -o $@ -c $< $(CFLAGS)

srcs_push/%.o: srcs_push/%.c
	gcc  -o $@ -c $< $(CFLAGS)

srcs_both/%.o: srcs_both/%.c
	gcc  -o $@ -c $< $(CFLAGS)

$(NAME_PUSH): $(OBJS_PUSH) $(OBJS_BOTH)
	make -C libft/
	gcc $(CFLAGS) $^ -L$(LIB) -lft -o $@

$(NAME_CHECK): $(OBJS_CHECK) $(OBJS_BOTH)
	make -C libft/
	gcc $(CFLAGS) $^ -L$(LIB) -lft -o $@

clean :
	make -C libft/ clean
	rm -rf $(OBJS_PUSH) $(OBJS_CHECK) $(OBJS_BOTH)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME_PUSH) $(NAME_CHECK) $(OBJS_BOTH)

.PHONY : all clean fclean re
