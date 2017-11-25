SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/usocolas $(BIN)/usopilas_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o

$(OBJ)/usocolas.o: $(SRC)/usocolas.cpp $(INC)/cola.h
	$(CXX) -g -c -o $(OBJ)/usocolas.o $(SRC)/usocolas.cpp -I$(INC)

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o

$(OBJ)/usopilas_max.o: $(INC)/pila_max.h $(SRC)/usopilas_max.cpp
	$(CXX) -g -c -o $(OBJ)/usopilas_max.o $(SRC)/usopilas_max.cpp -I$(INC) -I$(SRC)




mrproper : clean
	-rm $(BIN)/* doc/html/*
