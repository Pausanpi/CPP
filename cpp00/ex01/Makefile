NAME = phonebook
FILES = PhoneBook.cpp Contact.cpp main.cpp
OBJECTS = $(FILES:%.cpp=obj/%.o)

FLAGS = -std=c++98 -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@ c++ $(FLAGS) -o $(NAME) $(OBJECTS)
			@echo "Compilation successful"

$(OBJECTS):	obj/%.o : %.cpp
			@ mkdir -p obj
			@ c++ $(FLAGS) -c $< -o $@

clean:
			@ rm -rf $(OBJECTS) obj
			@echo "Compiled objects have been removed"

fclean:		clean
			@ rm -rf $(NAME)
			@echo "Cleaned"

re: 		fclean all

.PHONY: 	all clean fclean re