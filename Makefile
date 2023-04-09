PROJ=/home/prabhat/proj
BIN=$(PROJ)/src/bin
SERVER=$(PROJ)/src/server
CLIENT=$(PROJ)/src/client
CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I$(SERVER)
LFLAGS=-lpthread

CLIENT_OBJS=$(CLIENT)/client.o
SERVER_OBJS=$(SERVER)/server.o $(SERVER)/user_validation.o \
$(patsubst $(SERVER)/cmd/%.cpp, $(SERVER)/cmd/%.o, $(wildcard $(SERVER)/cmd/*.cpp)) \
$(SERVER)/utils/split_string.o

all : $(BIN)/server $(BIN)/client

$(BIN)/client : $(CLIENT_OBJS)
	$(CC) $^ -o $@ $(LFLAGS)

$(BIN)/server : $(SERVER_OBJS)
	$(CC) $^ -o $@ $(LFLAGS)

$(SERVER)/cmd/%.o : $(SERVER)/cmd/%.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

$(CLIENT)/client.o: $(CLIENT)/client.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	@echo "cleaning!"
	\rm -f $(BIN)/server $(BIN)/client
	\rm `find $(PROJ) -name '*.o'`	
