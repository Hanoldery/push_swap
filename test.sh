# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 13:14:14 by pgerbaud          #+#    #+#              #
#    Updated: 2018/01/29 19:24:40 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re;
./checker 1 0 0 2;

echo "\nERROR CHECKER\n";
./checker 1 1 2 3;
./checker 0 o 5;
./checker a
./checker 052o2 5;
./checker 6446864645454545 o 5;
./checker -sv 0 0;
./checker -sv 5 2 4 2p5;
echo "pa\npa\0" | ./checker 1 2 3;
echo "pa\npa\0" | ./checker 1 8 3;
#echo "Enter bad param :\n";
#./checker 5 4 3 2 1;
#echo "Enter bad param :\n";
#./checker 5 4 3 2 1;
#echo "Enter bad param (with space at the end):\n";
#./checker 5 4 3 2 1;

echo "\nNOTHING OR KO\n";
./checker
echo "->nothing\n";
./checker -v;
./checker -sv;
ARG="pa\npa\n" | ./checker 1 2 3;
ARG="pa\npa\n" | ./checker 1 8 3;
./push_swap 1 -2

echo "\nERROR PUSH\n";
./push_swap
./push_swap -sv
./push_swap -v
./push_swap -v  1 2 3
./push_swap -v  1 5 3
./push_swap a
./push_swap a 12
./push_swap "a"
./push_swap "a 12"

echo "\nSHOULD BE OK\n";
ARG="9 8 7 4 5 6 3 2 1 0 25 48" ; ./push_swap $ARG | ./checker $ARG;

ARG=`ruby -e "puts (0..16).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG;

ARG=`ruby -e "puts (0..19).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG;
ARG=`ruby -e "puts (0..49).to_a.shuffle.join(' ')"`; ./push_swap  $ARG | ./checker $ARG;


ARG="5 1"; ./push_swap $ARG | ./checker $ARG
ARG="5 1"; ./push_swap $ARG | ./checker $ARG
ARG="5 1"; ./push_swap $ARG | ./checker $ARG
ARG="5 1"; ./push_swap $ARG | ./checker $ARG
ARG="5 1"; ./push_swap $ARG | ./checker $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker $ARG
ARG="1 4 5 2 3"; ./push_swap $ARG | ./checker $ARG
ARG="3 2 5 4 1"; ./push_swap $ARG | ./checker $ARG
ARG="2 5 4 3 1"; ./push_swap $ARG | ./checker $ARG
ARG="3 5 2 4 1"; ./push_swap $ARG | ./checker $ARG
ARG="4 3 2 1 5"; ./push_swap $ARG | ./checker $ARG
ARG="4 5 2 3 1"; ./push_swap $ARG | ./checker $ARG
ARG="5 1 3 2 4"; ./push_swap $ARG | ./checker $ARG
ARG="0 1 4 2 3"; ./push_swap $ARG | ./checker $ARG
ARG="5 1 3 4 2"; ./push_swap $ARG | ./checker $ARG
