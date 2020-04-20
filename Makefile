FLAGS = -Wextra

main: main.o sort.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm -f *.o main
