##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all:
	@make -C Pacman/ --no-print-directory
	@make -C Snake/ --no-print-directory

clean:
	@make clean -C Pacman/ --no-print-directory
	@make clean -C Snake/ --no-print-directory

fclean:	clean
	@make fclean -C Pacman/ --no-print-directory
	@make fclean -C Snake/ --no-print-directory

re: fclean all

.PHONNY: all clean fclean re