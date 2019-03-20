

all: payroll

payroll: payroll.o
	gcc -o payroll payroll.o

payroll.o: payroll.c emp_rec.h
	gcc -c payroll.c

clean:
	rm -rf payroll *.o new.bin
