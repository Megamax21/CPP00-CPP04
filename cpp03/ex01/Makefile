NAME = claptrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \

HEADERS = ClapTrap.hpp \
		ScavTrap.hpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
