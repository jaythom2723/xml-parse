CC=gcc
LDFLAGS=
PPFLAGS=-I./include

all: tester.exe

xml.o: $(wildcard ./src/*.c)
	$(CC) $^ $(LDFLAGS) $(PPFLAGS) -c -o $@

lxmlparse.a: xml.o
	ar rcs $^ ./bin/$@

tester.exe: lxmlparse.a
	$(CC) $(wildcard ./tsrc/*.c) -lxmlparse $(PPFLAGS) -o ./bin/$@