# VARIABILI DI COMPILAZIONE
CC:= g++
LD:= g++
CFLAGS:= -Iinclude -Wall -std=c++14
SFOLD := src/
OFOLD := build/
BFOLD := bin/
DFOLD := doc/

# COMPILAZIONE E DIPENDENZE
all:$(BFOLD)TuringSimulator.x

$(BFOLD)TuringSimulator.x : $(OFOLD)main.o $(OFOLD)GpUtils.o $(OFOLD)TransitionKey.o $(OFOLD)TransitionValue.o $(OFOLD)TuringMachine.o $(OFOLD)TuringMachineState.o
	@echo Linking $@
	@$(LD) $^ -o $@

main.o : $(SFOLD)main.cpp
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $^ -o $(OFOLD)$@

GpUtils.o: $(SFOLD)GpUtils.cpp
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $^ -o $(OFOLD)$@

TransitionKey.o: $(SFOLD)TransitionKey.cpp
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $^ -o $(OFOLD)$@

TransitionValue.o: $(SFOLD)TransitionValue.cpp
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $^ -o $(OFOLD)$@

TuringMachine.o: $(SFOLD)TuringMachine.cpp
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $^ -o $(OFOLD)$@

TuringMachineState.o: $(SFOLD)TuringMachineState.cpp
	@echo Compiling $@
	@$(CC) $(CFLAGS) -c $^ -o $(OFOLD)$@



# ELIMINAZIONE FILE
clean:
	@echo -n Rimozione della documentazione...
	@rm -rf doc/html
	@echo OK
	@echo -n Rimozione dei file generati...
	@rm -rf $(OFOLD)*.o $(BFOLD)TuringSimulator.x
	@echo OK

# CREAZIONE DELLA DOCUMENTAZIONE
doc:
	@echo Creazione documentazione...
	@doxygen doc/Doxyfile
	@echo OK

.PHONY: all clean doc
