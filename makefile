OPT = -g -Wall -Wextra -pthread
OBJ = main.o event.o manager.o resource.o system.o

p2: $(OBJ)
	gcc $(OPT) -o p2 $(OBJ)
	
main.o: mainV1.c defs.h
	gcc $(OPT) -c mainV1.c
	
manager.o: managerV1.c defs.h
	gcc $(OPT) -c managerV1.c

resource.o: resourceV1.c defs.h
	gcc $(OPT) -c resourceV1.c

system.o: systemV1.c defs.h
	gcc $(OPT) -c systemV1.c
event.o: eventV1.c defs.h
	gcc $(OPT) -c eventV1.c
		
clean: 
	rm -f $(OBJ) p2


	
