#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp_rec.h"
#include "print_calculated.h"

/*
  This program reads a binary file created by payroll.c
  containing employee's raw data and calculated payment data, also
  takes integers as input, and displays employee's data which is
  corresponded with the integers input, e.g. 2 means second record from the
  beginning of the file and -2 means the second record from the end of file.
*/

int main(int argc, char* argv[]) {

    if(argc < 3){
      printf("usage: program name, file name, record number 1, record number 2, ... record number n \n");
      return -1;
    }

    FILE *fpr;
    if((fpr = fopen(argv[1], "rb")) == NULL ) {
      printf("Input file not open\n");
      return -1;
    }

    // magic number to verify that the input file was made by payroll.c
    char* magic_num = "PAYOUT@#";
    char* first_eight = (char*) malloc(8);
    fread(first_eight, 8, 1, fpr);

    if(strcmp(magic_num, first_eight)){
      printf("Invaild File\n");
      fclose(fpr);
      return -1;
    }

    empPtr q;
    pdataPtr p;
    char *endp;
    int arg_num = 2;

    while(arg_num != argc){
      int record_num = strtol(argv[arg_num], &endp, 10);
      if (*endp != '\0')
        printf("Input value must be integer\n");
      else
      {
        if((q = (empPtr) malloc(sizeof(struct emp))) == NULL || (p = (pdataPtr) malloc(sizeof(struct paydata)))== NULL){
          printf("No more memory space available \n");
          fclose(fpr);
          return -1;
        }

        //move file pointer based on the input integer
        fseek(fpr, (sizeof(struct emp) + sizeof(struct paydata))*(abs(record_num)-1)+8, SEEK_SET);
        if(record_num <= 0 && fpr != NULL){
          fseek(fpr, (sizeof(struct emp) + sizeof(struct paydata))*(record_num), SEEK_END);
        }

        if(fread(q, sizeof(struct emp), 1, fpr) && fread(p, sizeof(struct paydata), 1, fpr)){
          printf("record%d\n", record_num);
          print_emp_data(q, p);
        }
        else{
          printf("Out of range; there is no record for record%d\n", record_num);
        }
      }
    arg_num++;
  }

    fclose(fpr);

    return 0;
}
