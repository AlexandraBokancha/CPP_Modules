NAME = materia

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS =  main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
		MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)


%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re