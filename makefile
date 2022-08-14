# Set CFLAGS to activate all warnings and enable debugger
CFLAGS = -Wall -g

# Default rule is to build the executable called main
all: main

# Rule for building the executable
main: main.o data_client.o url_builder.o
	g++ $(CFLAGS) main.o data_client.o url_builder.o -o main -lcurl -ljsoncpp

# Rules for building each object file
main.o: main.cpp main.h
	g++ $(CFLAGS) -c main.cpp

data_client.o: data_client/data_client.cpp data_client/data_client.h
	g++ $(CFLAGS) -c data_client/data_client.cpp

url_builder.o: data_client/url_builder.cpp data_client/url_builder.h
	g++ $(CFLAGS) -c data_client/url_builder.cpp

# Give command "make clean" to remove object files,
#  executable, and documentation.
clean:
	rm *.o
	rm main
