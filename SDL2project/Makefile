# TARGET
TARGET = testProgram
# COMPILER
COMPILER = g++
CFLAGS = -c
# PROJECT FILES
LIB_CPP = $(wildcard ./lib/*.cpp)
SRC_CPP = $(wildcard ./src/*.cpp)
LIB_OBJ = $(subst .cpp,.o,$(LIB_CPP))
SRC_OBJ = $(subst .cpp,.o,$(SRC_CPP))
# INCLUDED FILE DIRECTORIES
IFLAGS = $(INCLUDE_DIR)
INCLUDE_DIR = -Iinclude -I/usr/local/include -Wno-deprecated-declarations -I/usr/local/Cellar/sdl2/2.0.8/include/SDL2
# LINKED FILE DIRECTORIES
LFLAGS = -framework OpenGL -L/usr/local/Cellar/sdl2/2.0.8/lib/ -lSDL2 
.PHONY:all
all:$(TARGET)

$(TARGET): $(LIB_OBJ) $(SRC_OBJ)
	$(COMPILER) $(LFLAGS) $(LIB_OBJ) $(SRC_OBJ) -o $(TARGET)

%.o:%.cpp
	$(COMPILER) $(IFLAGS) $(CFLAGS) $< -o $@

$(LIB_OBJ): $(LIB_CPP)
$(SRC_OBJ): $(SRC_CPP)

.PHONY:clean
clean:
	rm -f ./*.o ./src/*.o ./lib/*.o ./$(TARGET)
.PHONY:run
run:
	./$(TARGET)
