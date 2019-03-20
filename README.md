## payroll random read

In this homework you will write two programs and build with a single Makefile.  Program 1 will be called **payroll** and will take two parameters: Input binary file and binary output file. The input file is called emp_recs.bin and is a 64 bit structured file that uses struct emp to read the data.  Next you will compute the data as per last homework into struct paydata and write the original record and the new record paydata to the output file in binary format (ie emprec1,paydata1, ... emprecn,paydatan).  To verify correctness, you write a second program **payget** to fetch records from the binary output file you wrote with first program using fseek().  The format of the command line will be ** payget filename record1 ... recordn **  where you can specify one or more records to read.  if the record number is negative that means read from end of file towards 1st record.  If read is past end of file or beginning of file, handle this gracefully.  **payget** only reads data and prints it - there are no calculations in this program.  The pay was computed in **payroll**. There is no sorting or linked lists required in these programs and you can probably reuse code from previous homework especially like print functions that you hopefully had put in separate file(s).

## Requirements

* Must use dynamic memory (i.e. malloc()) to store records read
* you may not modify **emp_rec.h** but must use it
* Must have valid Makefile with correct dependencies and support building of multiple targets
* Must have separate files for functions - would recommend formatted printing
* Must use pointers where appropriate (no copy of structures around)
* Must have appropriate comments
* For each employee must calculate their net bi-weekly pay from their monthly pay (remember
    that bi-weekly pay is not monthly pay divided by 2)
* print out each employees biWeekly pay gross, fed tax withheld, state tax withheld, medical withheld, and net pay
* Must use branches and pull requests in git
