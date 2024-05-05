CC:=gcc

all: build run

build: list.c main.c
	@${CC} -c list.c
	@${CC} -c main.c
	@${CC} -o gls main.o list.o

run: gls
	@./gls

clean:
	@rm main.o list.o gls
