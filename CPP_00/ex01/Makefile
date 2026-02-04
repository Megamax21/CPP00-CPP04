NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g

SRCS = main.cpp \
		contact.cpp \
		contact_setters.cpp\
		contact_getters.cpp\
		phonebook.cpp \
		phonebook_1.cpp \
		phonebook_2.cpp \
		

HEADERS = contact.hpp \
			phonebook.hpp

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
