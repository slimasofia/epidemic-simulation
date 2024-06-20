CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = epidemic-simulation

SOURCES = $(wildcard ./src/*.cpp)

OBJECTS = $(patsubst ./src/%.cpp, ./obj/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

./obj/%.o: ./src/%.cpp
	@mkdir -p ./obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f ./obj/*.o $(TARGET)
	rmdir obj

.PHONY: all clean
