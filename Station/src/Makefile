CFLAGS          += -W -Wall -Wextra -Werror

CC              =       g++
BINARY          =       Exec

SRCMAIN         =       main.cpp

OBJMAIN         =       $(SRCMAIN:.c=.o)

$(BINARY):      $(OBJMAIN)
	$(CC) -o $@ $^ $(CFLAGS)

all:            $(BINARY)

clean:
	@echo Cleaning temp files
	@rm -f $(OBJMAIN) $(OBJMAIN:.o=.gcno)

fclean:         clean
	@echo Removing executable
	@rm -f $(BINARY)

re:             fclean all

.PHONY:         all clean fclean re