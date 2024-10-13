NAME = weapon

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = 	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

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