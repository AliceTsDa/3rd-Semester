CC=g++
CFLAGS=-I.
DEPS=creature.h
OBJ=main.o creature.o

%.o: %.cc $(DEPS)
	$(CC) -c -g3 -o $@ $< $(CFLAGS)

creature: $(OBJ)
	$(CC) -g3 -o $@ $^ $(CFLAGS)

run:
	./creature

.Phony: clean
clean:
	-rm $(OBJ)
	-rm creature