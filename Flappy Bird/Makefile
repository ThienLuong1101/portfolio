
# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXECUTABLE = export LD_LIBRARY_PATH=SFML-2.6.0/lib && ./sfml-app



$(EXECUTABLE): $(OBJ)
	g++ -c bird.cpp -ISFML-2.6.0/include
	g++ bird.o -o sfml-app -LSFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=SFML-2.6.0/lib && ./sfml-app

.cpp.o:
	g++ -c bird.cpp -ISFML-2.6.0/include

clean:
	rm -f $(OBJ) $(EXECUTABLE)
