

all: payroll payget

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

clean:
	rm -rf payroll payget *.o new.bin
