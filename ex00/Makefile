
CXX 				= g++
CPPFLAGS 			= -Wall -Wextra -Werror -std=c++98
NAME 				= megaphone
SRC 				= megaphone.cpp
OBJ 				= $(SRC:.c=.o)


# Rule to compile and link only when necessary
$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

# Rule to compile .c files into .o files (Prevents unnecessary relinking)
%.o: %.c
	$(CXX) $(CPPFLAGS) -c $< -o $@ 


all: $(NAME) 

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean re all