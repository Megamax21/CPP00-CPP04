NAME = Polymorphism

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \

HEADERS = Animal.hpp \
		Dog.hpp \
		Cat.hpp \

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
