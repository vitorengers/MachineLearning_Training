FLAGS := -Wall -std=c++11 -g -pthread 
TARGET := main

SOURCES := $(shell find -name "*.cpp")
DEPENDENCIES := $(patsubst %.cpp,%.d,$(SOURCES))

all: $(TARGET)

%.o: %.cpp $(DEPENDENCIES)
	$ g++ -c -o $@ $< $(FLAGS)

$(TARGET): $(SOURCES)
	$ g++ -o $@ $^ $(FLAGS)

mk: $(TARGET)
	$ mkdir test

run: $(TARGET)
	./$(TARGET)

clean:
	@-rm -f *.o $(TARGET)

