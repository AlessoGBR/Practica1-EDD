CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -g

SRC_DIR = .
OBJETOS_DIR = OBJETOS
UTILIDADES_DIR = UTILIDADES
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.cpp \
       $(OBJETOS_DIR)/Jugador.cpp \
       $(OBJETOS_DIR)/Tablero.cpp \
       $(OBJETOS_DIR)/Ficha.cpp \
       $(OBJETOS_DIR)/ListaEnlazada.cpp \
       $(OBJETOS_DIR)/Pila.cpp \
       $(OBJETOS_DIR)/Cola.cpp \
       $(UTILIDADES_DIR)/Juego.cpp \
       $(UTILIDADES_DIR)/Utilidades.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = $(BIN_DIR)/Practical-EDD

all: $(BIN_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(OBJS) $(TARGET)

