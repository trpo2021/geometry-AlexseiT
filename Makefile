CFLAGS = -Wall -Wextra -Werror

program: main.o parsing.o func.o
	$(CXX) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) -cpp $(CFLAGS) -o $@ $<

parsing.o: parsing.cpp
	$(CXX) -cpp $(CFLAGS) -o $@ $<

func.o: func.cpp
	$(CXX) -cpp $(CFLAGS) -o $@ $<

