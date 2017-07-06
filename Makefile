BIN = daxpy dotproduct func memlayout heat kmeans

all: $(BIN)

CC = icc

ifeq ($(CC), icc)
	CFLAGS = -O3 -Wall -g -qopenmp -xHost
else
	CFLAGS = -O3 -Wall -g -fopenmp -march=native
endif
LIBS		= -lm


%: %.o main-%.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(BIN)
