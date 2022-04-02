##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_DIR = /src/

GRAPH_DIR = Graphical

CORE_SRC = Core$(SRC_DIR)main.cpp \
		   Core$(SRC_DIR)Core.cpp \
		   Dynamic_Library$(SRC_DIR)Dyn_Lib.cpp \
		   C_Directory$(SRC_DIR)C_Directory.cpp \
		   Score$(SRC_DIR)score.cpp \
		   Score$(SRC_DIR)utils.cpp

CXXFLAGS	+=	-I./core/include -I./include -ggdb3
CXXFLAGS	+=	-Wextra -Wall -W
CXXFLAGS	+=	-ldl

OBJ = $(CORE_SRC:.cpp=.o)

NAME = arcade

all: core graphicals games

core: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

graphicals:
	@make -C Graphical/ --no-print-directory

games:
	@make -C Games/ --no-print-directory


clean:
	rm -f $(OBJ)
	@make clean -C Graphical/ --no-print-directory
	@make clean -C Games/ --no-print-directory

fclean: clean
	rm -f $(NAME) && rm -f $(OBJ)
	@make fclean -C Graphical/ --no-print-directory
	@make fclean -C Games/ --no-print-directory

re: fclean all
