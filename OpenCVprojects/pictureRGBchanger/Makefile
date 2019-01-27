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
INCLUDE_DIR = -I/usr/local/Cellar/opencv/4.0.1/include/opencv4/ -Iinclude -I/usr/local/include -Wno-deprecated-declarations -I/usr/local/Cellar/sdl2/2.0.9/include/SDL2
IFLAGS = $(INCLUDE_DIR)
# LINKED FILE DIRECTORIES
LIBS = $(subst .a,,$(subst /usr/local/Cellar/opencv/4.0.1/lib/lib,-l,$(wildcard /usr/local/Cellar/opencv/4.0.1/lib/*.a)))

LFLAGS =-framework OpenGL -L/usr/local/Cellar/sdl2/2.0.9/lib/ -lSDL2 -L/usr/local/Cellar/opencv/4.0.1/lib/
.PHONY:libs
libs:
	echo "$(LIBS)"

.PHONY:all
all:$(TARGET)

$(TARGET):$(LIB_OBJ) $(SRC_OBJ)
	$(COMPILER) -std=c++11 $(LFLAGS) $(LIBS)$(LIB_OBJ) $(SRC_OBJ) -o $(TARGET)

%.o:%.cpp
	$(COMPILER) -std=c++11 $(IFLAGS) $(CFLAGS) $< -o $@

$(LIB_OBJ):$(LIB_CPP)
$(SRC_OBJ):$(SRC_CPP)

.PHONY:clean
clean:
	rm -f ./*.o ./src/*.o ./lib/*.o ./$(TARGET)
.PHONY:run
run:
	./$(TARGET)
.PHONY:do
do:
	make clean all run

