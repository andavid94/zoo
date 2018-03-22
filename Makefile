output: main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o inputValidation.o
	g++ main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o inputValidation.o -o output

main.o: main.cpp
	g++ -c main.cpp

Zoo.o: Zoo.cpp
	g++ -c Zoo.cpp

Animal.o: Animal.cpp
	g++ -c Animal.cpp

Tiger.o: Tiger.cpp
	g++ -c Tiger.cpp

Penguin.o: Penguin.cpp
	g++ -c Penguin.cpp

Turtle.o: Turtle.cpp
	g++ -c Turtle.cpp

inputValidation.o: inputValidation.cpp
	g++ -c inputValidation.cpp

clean:
	rm *.o output
