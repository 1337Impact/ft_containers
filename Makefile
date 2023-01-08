NAME = out
all : $(NAME)

$(NAME) : Vector.hpp test.cpp
	c++ -Wall -Wextra -Werror -std=c++98 test.cpp -o $(NAME)

c: all
	./out

fclean:
	rm -rf $(NAME)

test:
	c++ -Wall -Wextra -Werror -std=c++98 vector_test.cpp -o test

map:
	c++ -Wall -Wextra -Werror -std=c++98 map_test.cpp -o test
	./test