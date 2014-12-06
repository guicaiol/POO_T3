SRC		= src
OBJ		= obj
BIN		= bin
CC		= g++
FLAGS	= -std=c++11 -Wall -lm -pthread
TARGET	= $(BIN)/trab3

OBJECTS = \
	$(OBJ)/knight.o \
	$(OBJ)/thief.o \
	$(OBJ)/wizard.o \
	$(OBJ)/character.o \
	$(OBJ)/inventory.o \
	$(OBJ)/game.o \
	$(OBJ)/armor.o \
	$(OBJ)/healthpotion.o \
	$(OBJ)/manapotion.o \
	$(OBJ)/potion.o \
	$(OBJ)/weapon.o \
	$(OBJ)/item.o \
	$(OBJ)/team.o \
	$(OBJ)/thread.o \
	$(OBJ)/main.o \
	$(OBJ)/position.o \
	$(OBJ)/field.o \
	$(OBJ)/timer.o \
	$(OBJ)/outputhandler.o
	
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(TARGET)
	
$(OBJ)/knight.o:
	$(CC) $(FLAGS) -c $(SRC)/character/characters/knight.cpp -o $@
	
$(OBJ)/thief.o:
	$(CC) $(FLAGS) -c $(SRC)/character/characters/thief.cpp -o $@
	
$(OBJ)/wizard.o:
	$(CC) $(FLAGS) -c $(SRC)/character/characters/wizard.cpp -o $@
	
$(OBJ)/character.o:
	$(CC) $(FLAGS) -c $(SRC)/character/character.cpp -o $@
	
$(OBJ)/inventory.o:
	$(CC) $(FLAGS) -c $(SRC)/character/inventory.cpp -o $@
	
$(OBJ)/game.o:
	$(CC) $(FLAGS) -c $(SRC)/game/game.cpp -o $@
	
$(OBJ)/armor.o:
	$(CC) $(FLAGS) -c $(SRC)/item/armor/armor.cpp -o $@
	
$(OBJ)/healthpotion.o:
	$(CC) $(FLAGS) -c $(SRC)/item/potion/potions/healthpotion.cpp -o $@
	
$(OBJ)/manapotion.o:
	$(CC) $(FLAGS) -c $(SRC)/item/potion/potions/manapotion.cpp -o $@
	
$(OBJ)/potion.o:
	$(CC) $(FLAGS) -c $(SRC)/item/potion/potion.cpp -o $@
	
$(OBJ)/weapon.o:
	$(CC) $(FLAGS) -c $(SRC)/item/weapon/weapon.cpp -o $@
	
$(OBJ)/item.o:
	$(CC) $(FLAGS) -c $(SRC)/item/item.cpp -o $@
	
$(OBJ)/team.o:
	$(CC) $(FLAGS) -c $(SRC)/team/team.cpp -o $@
	
$(OBJ)/thread.o:
	$(CC) $(FLAGS) -c $(SRC)/utils/thread.cpp -o $@
	
$(OBJ)/main.o:
	$(CC) $(FLAGS) -c $(SRC)/main.cpp -o $@
	
$(OBJ)/position.o:
	$(CC) $(FLAGS) -c $(SRC)/utils/position.cpp -o $@
	
$(OBJ)/field.o:
	$(CC) $(FLAGS) -c $(SRC)/game/field.cpp -o $@
	
$(OBJ)/timer.o:
	$(CC) $(FLAGS) -c $(SRC)/utils/timer.cpp -o $@
	
$(OBJ)/outputhandler.o:
	$(CC) $(FLAGS) -c $(SRC)/utils/outputhandler.cpp -o $@

clean:
	rm -f $(OBJ)/* $(TARGET)
		
run:
	./$(TARGET)
	
valgrind:
	valgrind ./$(TARGET)

