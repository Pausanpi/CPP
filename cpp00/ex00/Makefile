NAME = megaphone
CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) -o $@ $(OBJ)
	@echo "Compilation successful"

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Compiled objects have been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re