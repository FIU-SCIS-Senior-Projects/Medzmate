OBJS = MedzmateProcess.o SchedulerProcess.o Serializer.o MedzmateConfiguration.o DispenserConfiguration.o Parser.o Lexer.o
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

all: MedzmateProcess

MedzmateProcess : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o MedzmateProcess

MedzmateProcess.o : SchedulerProcess.h MedzmateProcess.cpp
	$(CC) $(CFLAGS) MedzmateProcess.cpp

SchedulerProcess.o : SchedulerProcess.h SchedulerProcess.cpp Serializer.h
	$(CC) $(CFLAGS) SchedulerProcess.cpp

Serializer.o : Serializer.h Serializer.cpp MedzmateConfiguration.h Parser.h
	$(CC) $(CFLAGS) Serializer.cpp

MedzmateConfiguration.o : MedzmateConfiguration.h MedzmateConfiguration.cpp DispenserConfiguration.h
	$(CC) $(CFLAGS) MedzmateConfiguration.cpp

DispenserConfiguration.o : DispenserConfiguration.h DispenserConfiguration.cpp
	$(CC) $(CFLAGS) DispenserConfiguration.cpp

Parser.o : Parser.h Parser.cpp Lexer.h
	$(CC) $(CFLAGS) Parser.cpp

Lexer.o : Lexer.h Lexer.cpp
	$(CC) $(CFLAGS) Lexer.cpp

clean:
	rm -f MedzmateProcess *.o *~ core
    
