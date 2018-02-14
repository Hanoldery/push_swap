# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 14:11:45 by pgerbaud          #+#    #+#              #
#    Updated: 2018/02/14 10:54:20 by pgerbaud         ###   ########.fr        #
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
INC = ./includes ./$(LIB)/includes

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += $(foreach path, $(INC), -I$(path))

# ----------- COLORS -----------
LOG_U		:= \033[A
STOP_C		:= \x1b[0m
OK_C		:= \033[0;32m
ERROR_C		:= \x1b[31;01m
WARN_C		:= \x1b[33;01m
SILENT_C	:= \x1b[29;01m
CHARS		:= / / - - \\ \\ | |
INCR		:= 1
# -------------------------------



all: $(NAME_PUSH) $(NAME_CHECK)

re : fclean all

srcs_check/%.o: srcs_check/%.c
	@printf "$(LOG_U)$(WARN_C)[%s]$(STOP_C) Compiling : %s          \
		\n" "$(word $(INCR), $(CHARS))" "$@"
	@$(eval INCR = $(shell echo $$(($(INCR) % 8 + 1))))
	@gcc -o $@ -c $< $(CFLAGS) $(CFLAGS)

srcs_push/%.o: srcs_push/%.c
	@printf "$(LOG_U)$(WARN_C)[%s]$(STOP_C) Compiling : %s          \
		\n" "$(word $(INCR), $(CHARS))" "$@"
	@$(eval INCR = $(shell echo $$(($(INCR) % 8 + 1))))
	@gcc -o $@ -c $< $(CFLAGS) $(CFLAGS)

srcs_both/%.o: srcs_both/%.c
	@gcc -o $@ -c $< $(CFLAGS) $(CFLAGS)


$(NAME_PUSH): $(OBJS_PUSH) $(OBJS_BOTH)
	@make -C $(LIB)
	@gcc $(CLFAGS) $^ -L$(LIB) -lft -o $@
	@printf "$(LOG_U)$(OK_C)[OK]$(STOP_C) Compiling done for\
	 $(SILENT_C)%s$(STOP_C)       \n" "$@"
	@printf "\n"

$(NAME_CHECK): $(OBJS_BOTH) $(OBJS_CHECK)
	@make -C $(LIB)
	@gcc $(CLFAGS) $^ -L$(LIB) -lft -o $@
	@printf "$(LOG_U)$(OK_C)[OK]$(STOP_C) Compiling done for\
	 $(SILENT_C)%s$(STOP_C)       \n" "$@"


clean :
	@make -C $(LIB) clean
	@rm -rf $(OBJS_PUSH) $(OBJS_CHECK) $(OBJS_BOTH)

fclean : clean
	@make -C $(LIB) fclean
	@rm -rf $(NAME_PUSH) $(NAME_CHECK)
	@printf "$(LOG_U)$(ERROR_C)[RM]$(STOP_C) $(SILENT_C)%s$(STOP_C)\
		Deleted\n" "$(NAME_PUSH)"
	@printf "\n"

.PHONY : all clean fclean re
