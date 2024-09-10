# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:26:50 by clouaint          #+#    #+#              #
#    Updated: 2024/08/12 16:29:57 by clouaint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= pipex

SRCS 	= srcs/pipex.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -I./includes

LIBFT = libft.a
LIBPATH = libft

%.o: %.c
					@echo "\033[34mCompiling $<..."
					$(CC) $(CFLAGS) -c $< -o $@

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make -s re -C $(LIBPATH)
					@echo "\n"
					$(CC) $(CFLAGS) ${OBJS} $(LIBPATH)/$(LIBFT) -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					make -s clean -C ./libft
					rm -f ${OBJS}

fclean: 	clean
					make -s fclean -C ./libft
					rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

#################### TEST ####################

tclean:
	@rm -f result_shell* result_pipex* infile out*

init:
	$(file > infile,Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.)
	$(file >> infile,Lorem ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.)
	$(file >> infile,Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.)
	$(file >> infile,Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.)
	@echo "\n\033[1;30m----------- INFILE CREATED -----------"

test : init
		@echo "\n\033[1;31m----------- ERROR TEST: no input -----------\033[0;33m"
		./pipex infile
		./pipex infile "grep hello"
		./pipex infile "grep hello" "wc"
		./pipex infile "grep hello" outfile
		@echo "\n\033[1;35m----------- FIRST TEST -----------\033[0;33m"
		< infile grep Lorem | wc -w > result_shell01
		@echo "Test shell :" && cat result_shell01
		./pipex infile "grep Lorem" "wc -w" result_pipex01
		@echo "Test pipex : " && cat result_pipex01
		@echo "\n\033[1;36m----------- SECOND TEST -----------\033[0;33m"
		< infile ls -l | wc -w > result_shell02
		@echo "Test shell :" && cat result_shell02
		./pipex infile "ls -l" "wc -w" result_pipex02
		@echo "Test pipex : " && cat result_pipex02
		@echo "\n\033[1;34m----------- THIRD TEST -----------\033[0;33m"
		< infile ls -l | grep infile > result_shell03
		@echo "Test shell :" && cat result_shell03
		./pipex infile "ls -l" "grep infile" result_pipex03
		@echo "Test pipex : " && cat result_pipex03
		@echo "\n\033[1;37m----------- ERROR TEST: infile incorrect -----------\033[0;33m"
		< infil grep hello | wc > result_shell04
		@echo "Test shell :" && cat result_shell04
		./pipex infil "grep hello" "wc" result_pipex04
		@echo "Test pipex : " && cat result_pipex04
		@echo "\n\033[1;38m----------- ERROR TEST: cmd incorrect -----------\033[0;33m"
		< infile gre hello | wc > result_shell05
		@echo "Test shell :" && cat result_shell05
		./pipex infile "gre hello" "wc" result_pipex05
		@echo "Test pipex : " && cat result_pipex05
		@echo "\n\033[1;32m----------- ERROR TEST: infile protected -----------\033[0;33m"
		chmod 000 infile
		< infile grep Lorem | wc -w > result_shell06
		@echo "Test shell :" && cat result_shell06
		./pipex infile "grep Lorem" "wc -w" result_pipex06
		@echo "Test pipex : " && cat result_pipex06
		chmod 644 infile


tbonus : init
		@echo "\033[1;35m----------- FIRST TEST -----------\033[0;33m"
		< infile grep Lorem | grep ipsum | wc -w > result_shell07
		@echo "\033[33mTest shell :" && cat result_shell07
		./pipex infile "grep Lorem" "grep ipsum" "wc -w" result_pipex07
		@echo "Test pipex : " && cat result_pipex07
		@echo "\n\033[1;36m----------- SECOND TEST -----------\033[0;33m"
		< infile ls -l | grep total | cat -e > result_shell08
		@echo "\033[33mTest shell :" && cat result_shell08
		./pipex infile "ls -l" "grep total" "cat -e" result_pipex08
		@echo "Test pipex : " && cat result_pipex08
		@echo "\n\033[1;34m----------- THIRD TEST -----------\033[0;33m"
		< infile ls -l | grep clouaint | grep infile > result_shell09
		@echo "\033[33mTest shell :" && cat result_shell09
		./pipex infile "ls -l" "grep clouaint" "grep infile" result_pipex09
		@echo "Test pipex : " && cat result_pipex09

.PHONY: all clean fclean re re_bonus bonus party