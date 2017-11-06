SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia:$(OBJ)/pruebacronologia.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o
	$(CXX) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp $(INC)/cronologia.h
	$(CXX) -g -c -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp -I$(INC)

$(OBJ)/fechahistorica.o: $(SRC)/fechahistorica.cpp $(INC)/fechahistorica.h
	$(CXX) -g -c -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp -I$(INC)

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h
	$(CXX) -g -c -o $(OBJ)/cronologia.o  $(SRC)/cronologia.cpp -I$(INC)


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
