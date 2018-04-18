# VARIABILI DI COMPILAZIONE
CC:= g++
LD:= g++
CFLAGS:= -I -Wall

# COMPILAZIONE E DIPENDENZE
all:TuringMachineSimulator.out

ElaboratoII.out: main.o
	@echo Linking $@
	@$(LD) $^ -o $@
  

main.o: main.c main.h include/children_functions.c include/err_check_utils.c include/gp_utils.c include/io_utils.c include/signal_handlers.c
	@echo Compilazione $@
	@$(CC) $(CFLAGS) $< -o $@

# ELIMINAZIONE FILE
clean:
	@echo -n Rimozione della documentazione...
	@rm -rf doc/html
	@echo OK
	@echo -n Rimozione dei file generati...
	@rm -rf *.o ElaboratoII.out
	@echo OK

# CREAZIONE DELLA DOCUMENTAZIONE
doc:
	@echo Creazione documentazione...
	@doxygen
	@echo OK

.PHONY: all clean doc
