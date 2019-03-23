#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"


/*
  This program reads a structured binary file of employee records
  and will create a new file of employee in wich employee's bi-weekly total pay,
  net pay, amount of taxes and medical insruarence are written as well as
  employee's raw data read from input flie.
*/
int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("usage: program name, binary file name, binary file name \n");
    return -1;
  }

  FILE *fpr;
  if((fpr = fopen(argv[1], "rb")) == NULL ) {
    printf("Input file not open\n");
    return -1;
  }

  FILE *fpw;
  if((fpw = fopen(argv[2], "wb")) == NULL ) {
    printf("Output file not open\n");
    return -1;
  }

  //magic number to check a format of file when it is read afterward.
  char magic_num[8] = "PAYOUT@#";
  fwrite(&magic_num, 8, 1, fpw);

  empPtr q;
  q = (empPtr) malloc(sizeof(struct emp));
  if(q == NULL){
    printf("No more memory space available \n");
    return -1;
  }

  pdataPtr p;

  //while not EOF
  while(fread(q, sizeof(struct emp), 1, fpr)){

    p = (pdataPtr) malloc(sizeof(struct paydata));
    if(p == NULL){
      printf("No more memory space available \n");
      return -1;
    }

    //calculated each data
    p->biWeeklySalary = q->monthly_salary *12/26;
    p->fedTaxDeducted = p->biWeeklySalary * q->fed_tax_percent /100;
    p->stateTaxDeducted = p->biWeeklySalary * q->state_tax_percent /100;
    p->medicalDeducted = q->total_medical * 12/26;
    p->netPay = p->biWeeklySalary - p->fedTaxDeducted - p->stateTaxDeducted - p->medicalDeducted;

    fwrite(q, sizeof(struct emp), 1, fpw);
    fwrite(p, sizeof(struct paydata), 1, fpw);

    q = (empPtr) malloc(sizeof(struct emp));
    if(q == NULL){
      printf("No more memory space available \n");
      return -1;
    }
}
  //deallocate extra memory
  free(q);
  fclose(fpw);
  fclose(fpr);

  return 0;
}
