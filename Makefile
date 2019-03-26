
# This is a Makefile for two programs, payroll and payget.
# make will autimatically implement the programs and test cases
all: payroll payget test

test:
	./payroll emp_recs.bin test.bin
	./payget test.bin 1 2 3 4 5 6 7 8 9 10 11
	./payget test.bin -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11
	./payget test.bin 0 12 28 -34 10 -1 9 2938 -7
	./payget test.bin 1 www sxa @ -100 10 -5 9 8 -0

payroll: payroll.o
	gcc -o payroll payroll.o

payget: payget.o print_calculated.o
	gcc -o payget payget.o print_calculated.o

payroll.o: payroll.c emp_rec.h
	gcc -c payroll.c

payget.o: payget.c emp_rec.h print_calculated.h
	gcc -c payget.c

print_calculated.o: print_calculated.c print_calculated.h emp_rec.h
	gcc -c print_calculated.c

#change name of emp_recs.bin temporary to remove all binary files created by payroll
clean:
	mv emp_recs.bin emp_recs.bin.keep
	rm -rf payroll payget *.o *.bin
	mv emp_recs.bin.keep emp_recs.bin
