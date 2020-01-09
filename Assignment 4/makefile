
CFLAGS=-Wall -O2 -ansi

fib: main_fib.o fib.o bmp.o timing.o
	$(CXX) -o fib $?

runall:
	./fib 7 10 10 10 100 100 fib7.bmp
	./fib 9 10 10 10 100 150 fib9.bmp
	./fib 14 50 10 10 500 500 fib14.bmp
	./fib 17 50 100 10 1100 1000 fib17.bmp
	./fib 20 100 50 10 2000 2500 fib20.bmp
	./fib 25 10 10 5 5000 5000 fib25.bmp
	./fib 26 10 10 5 5000 7000 fib26.bmp
	./fib 30 10 10 5 29000 12000 fib30.bmp
	./fib 33 50 50 2 12000 28000 fib33.bmp
	./fib 34 10 10 2 28000 28000 fib34.bmp


clean:
	@rm -rf fib *.o *bmp *~
