# Makefile for HW 2 f2022, ecs36b

CC = g++ -std=c++14

CFLAGS = -g -I/usr/include/jsoncpp

CFLAGS = -g

LDFLAGS = -fopenmp -ljsoncpp -L~/vcpkg/installed/arm64-osx/lib -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h
INC_CL	=	Person.h Thing.h Location.h Time.h Record.h
OBJ	=	Location.o Time.o Thing.o Person.o Record.o

# rules.
all: 	LittleRedRidingHood hw5Home hw5Forest hw5GrandmasHouse#hw5server 

hw5client.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5server.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client 

Person.o:		Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp $(LDFLAGS)

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp $(LDFLAGS) 

Location.o:	Location.cpp Location.h
	$(CC) -c $(CFLAGS) Location.cpp $(LDFLAGS) 

Time.o:	Time.cpp Time.h
	$(CC) -c $(CFLAGS) Time.cpp $(LDFLAGS) 

Record.o:	Record.cpp $(INC_CL)
	$(CC) -c $(CFLAGS) Record.cpp $(LDFLAGS) 

ecs36b_JSON.o:		ecs36b_JSON.cpp ecs36b_Common.h ecs36b_Exception.h 
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp $(LDFLAGS) 

LittleRedRidingHood.o:	LittleRedRidingHood.cpp ecs36b_Common.h ecs36b_Exception.h $(INC_CL)  
	$(CC) -c $(CFLAGS) LittleRedRidingHood.cpp $(LDFLAGS) 

hw5client.o:		hw5client.cpp hw5client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5client.cpp

hw5server.o:		hw5server.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5server.cpp

hw5Home.o:		hw5Home.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5Home.cpp

hw5Forest.o:		hw5Forest.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5Forest.cpp

hw5GrandmasHouse.o:		hw5GrandmasHouse.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5GrandmasHouse.cpp

hw5client:	hw5client.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5client hw5client.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5server:	hw5server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5server hw5server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5Home:	hw5Home.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5Home hw5Home.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5Forest:	hw5Forest.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5Forest hw5Forest.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5GrandmasHouse:	hw5GrandmasHouse.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5GrandmasHouse hw5GrandmasHouse.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

LittleRedRidingHood:		LittleRedRidingHood.o ecs36b_JSON.o $(OBJ)
	$(CC) -o LittleRedRidingHood LittleRedRidingHood.o ecs36b_JSON.o $(OBJ) $(LDFLAGS) 

clean:
	rm -f *.o *~ core hw5client.h hw5server.h hw5client hw5server hw5Home hw5Forest hw5GrandmasHouse LittleRedRidingHood