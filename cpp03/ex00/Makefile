NAME = scavtrap
FLAGS = -std=c++98 -Wall -Wextra -Werror
FILES = main.cpp ClapTrap.cpp
OBJECTS = $(FILES:%.cpp=obj/%.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@ c++ $(FLAGS) -o $(NAME) $(OBJECTS)

$(OBJECTS):	obj/%.o : %.cpp
			@ mkdir -p obj
			@ c++ $(FLAGS) -c $< -o $@

clean:
			@ rm -rf $(OBJECTS) obj

fclean:		clean
			@ rm -rf $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re