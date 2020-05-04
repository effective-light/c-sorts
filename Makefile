FLAGS = -Wextra -g

main: main.o cmp.o sort.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c
	gcc ${FLAGS} -c $<

clean:
	rm -f *.o main
