FLAGS := -Wall -std=c++2a -g -pthread 
TARGET := main

SOURCES := $(shell find -name "*.cpp")
DEPENDENCIES := $(patsubst %.cpp,%.d,$(SOURCES))

all: $(TARGET)

%.o: %.cpp $(DEPENDENCIES)
	$ g++-9 -c -o $@ $< $(FLAGS)

$(TARGET): $(SOURCES)
	$ g++-9 -o $@ $^ $(FLAGS)

mk: $(TARGET)
	$ mkdir test

run: $(TARGET)
	./$(TARGET)

clean:
	@-rm -f *.o $(TARGET)

