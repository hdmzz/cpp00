NAME	= PhoneBook
S		= srcs/
HEADERS = ./include/Contact.hpp ./include/PhoneBook.hpp

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= $SContact.cpp $SPhoneBook.cpp $Smain.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -I ./include

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./include

clean:
		rm -f $S*.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
