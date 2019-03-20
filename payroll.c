#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"

/*
  This program reads a structured binary file of eployee records
  that is unsorted and first print out all of the data for
  each employee and then print out employee's bi-weekly net pay
  and total payment in descending alphabetical order.
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

  //Allocate space for the first record while checking if there
  //is memory space.
  empPtr q;
  q = (empPtr) malloc(sizeof(struct emp));
  if(q == NULL){
    printf("No more memory space available \n");
    return -1;
  }
  pdataPtr p;

  while(fread(q, sizeof(struct emp), 1, fpr)){

    p = (pdataPtr) malloc(sizeof(struct paydata));
    if(p == NULL){
      printf("No more memory space available \n");
      return -1;
    }
    printf("%s\n",q->first_name );
    p->biWeeklySalary = q->monthly_salary *12/26;
    p->fedTaxDeducted = p->biWeeklySalary * q->fed_tax_percent /100;
    p->stateTaxDeducted = p->biWeeklySalary * q->state_tax_percent /100;
    p->medicalDeducted = p->biWeeklySalary * q->total_medical * 12/26;
    p->netPay = p->biWeeklySalary - p->fedTaxDeducted - p->stateTaxDeducted - p->medicalDeducted;

    fwrite(q, sizeof(struct emp), 1, fpw);
    fwrite(p, sizeof(struct paydata), 1, fpw);

    q = (empPtr) malloc(sizeof(struct emp));
    if(q == NULL){
      printf("No more memory space available \n");
      return -1;
    }
}
  free(q);
  fclose(fpw);
  fclose(fpr);

  return 0;
}
