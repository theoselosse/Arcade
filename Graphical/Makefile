##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all:
	@make -C SDL/ --no-print-directory
	@make -C SFML/ --no-print-directory
	@make -C ncurses/ --no-print-directory

clean:
	@make clean -C SDL/ --no-print-directory
	@make clean -C SFML/ --no-print-directory
	@make clean -C ncurses/ --no-print-directory

fclean:	clean
	@make fclean -C SDL/ --no-print-directory
	@make fclean -C SFML/ --no-print-directory
	@make fclean -C ncurses/ --no-print-directory

re: fclean all

.PHONNY: all clean fclean re