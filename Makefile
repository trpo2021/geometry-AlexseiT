CFLAGS = -Wall -Wextra -Werror

program: main.o parsing.o func.o
        $(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
        $(CC) -cpp $(CFLAGS) -o $@ $<

parsing.o: parsing.cpp
        $(CC) -cpp $(CFLAGS) -o $@ $<

func.o: func.cpp
        $(CC) -cpp $(CFLAGS) -o $@ $<

