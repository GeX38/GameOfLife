CPPC=g++
CPPFLAGS=-Wall -Wextra -std=c++11
SOURCES=Main.cpp Life.cpp
OBJ=$(SOURCES:.cpp=.o)
TARGET=app
LDF= -lglut -lGL -lGLEW -lGLU

all:$(TARGET)
	
$(TARGET): $(OBJ) 
	$(CPPC) $(OBJ) -o $@ $(LDF)

.cpp.o:
	$(CPPC) $(CPPFLAGS) -c $< -o $@
	
clean:
	rm -rf $(TARGET) *.o