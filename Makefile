CC=g++ -g
EXE_FILE=main
all: $(EXE_FILE)

zoo.o: zoo.hpp zoo.cpp
	$(CC) -c zoo.cpp

animal.o: animal.hpp animal.cpp
	$(CC) -c animal.cpp

monkey.o: monkey.hpp monkey.cpp
	$(CC) -c monkey.cpp

seaotter.o: seaotter.hpp seaotter.cpp
	$(CC) -c seaotter.cpp

sloth.o: sloth.hpp sloth.cpp
	$(CC) -c sloth.cpp


$(EXE_FILE): zoo.o zoo.hpp  animal.o animal.hpp monkey.o monkey.hpp seaotter.o seaotter.hpp sloth.o sloth.hpp main.cpp
	$(CC) zoo.o animal.o monkey.o seaotter.o sloth.o main.cpp -o $(EXE_FILE)

