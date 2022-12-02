NAME = out
all : $(NAME)

$(NAME) : Vector.hpp test.cpp
	c++ test.cpp -o $(NAME)

c: all
	./out

fclean:
	rm -rf $(NAME)