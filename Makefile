NAME = test

T_PATH = ./tests

FLAGS = -Wall -Wextra -Werror -std=c++98

C_HEADERS = ./containers/vector.hpp\
			./containers/stack.hpp\
			./containers/map.hpp

O_HEADERS = ./containers/_tree.hpp\
			./containers/_map_iter.hpp\
			./utility/algorithm.hpp\
			./utility/iterator.hpp\
			./utility/pair.hpp\
			./utility/type_traits.hpp

 
all : $(NAME)

$(NAME) : main.cpp $(C_HEADERS) $(O_HEADERS)
	c++ $(FLAGS)  main.cpp -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

vector:
	c++ $(FLAGS)  $(T_PATH)/vector_test.cpp -o $(NAME)

stack:
	c++ $(FLAGS)  $(T_PATH)/stack_test.cpp -o $(NAME)

map:
	c++ $(FLAGS)  $(T_PATH)/map_test.cpp -o $(NAME)