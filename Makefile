

all: payroll payget

payroll: payroll.o
	gcc -o payroll payroll.o

payget: payget.o
	gcc -o payget payget.o

payroll.o: payroll.c emp_rec.h
	gcc -c payroll.c

payget.o: payget.c emp_rec.h
	gcc -c payget.c

clean:
	rm -rf payroll payget *.o new.bin
