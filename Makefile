FLAGS = -Wextra -g

main: main.o cmp.o sort.o heap.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm -f *.o main
