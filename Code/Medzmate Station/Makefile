OBJS = MedzmateProcess.o SchedulerProcess.o Serializer.o MedzmateConfiguration.o DispenserConfiguration.o Parser.o Lexer.o AlertsManager.o PatientInformation.o
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

all: MedzmateProcess LexerTests ParserTests
	
LexerTests: LexerTests.o Lexer.o
	$(CC) $(LFLAGS) LexerTests.o Lexer.o -o LexerTests
	
LexerTests.o: LexerTests.cpp Lexer.h
	$(CC) $(CFLAGS) LexerTests.cpp
	
ParserTests: ParserTests.o Parser.o Lexer.o
	$(CC) $(LFLAGS) ParserTests.o Parser.o Lexer.o -o ParserTests
	
ParserTests.o: ParserTests.cpp Parser.h
	$(CC) $(CFLAGS) ParserTests.cpp

MedzmateProcess : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o MedzmateProcess

MedzmateProcess.o : SchedulerProcess.h Serializer.h DispenserConfiguration.h PatientInformation.h MedzmateConfiguration.h MedzmateProcess.cpp
	$(CC) $(CFLAGS) MedzmateProcess.cpp

SchedulerProcess.o : SchedulerProcess.h SchedulerProcess.cpp MedzmateConfiguration.h DispenserConfiguration.h AlertsManager.h
	$(CC) $(CFLAGS) SchedulerProcess.cpp
	
AlertsManager.o : AlertsManager.h AlertsManager.cpp
	$(CC) $(CFLAGS) AlertsManager.cpp

Serializer.o : Serializer.h Serializer.cpp MedzmateConfiguration.h DispenserConfiguration.h PatientInformation.h Parser.h
	$(CC) $(CFLAGS) Serializer.cpp

MedzmateConfiguration.o : MedzmateConfiguration.h MedzmateConfiguration.cpp DispenserConfiguration.h
	$(CC) $(CFLAGS) MedzmateConfiguration.cpp

DispenserConfiguration.o : DispenserConfiguration.h DispenserConfiguration.cpp
	$(CC) $(CFLAGS) DispenserConfiguration.cpp

PatientInformation.o : PatientInformation.h PatientInformation.cpp
	$(CC) $(CFLAGS) PatientInformation.cpp

Parser.o : Parser.h Parser.cpp Lexer.h
	$(CC) $(CFLAGS) Parser.cpp

Lexer.o : Lexer.h Lexer.cpp
	$(CC) $(CFLAGS) Lexer.cpp

clean:
	rm -f MedzmateProcess LexerTests ParserTests *.o *~ core
    
