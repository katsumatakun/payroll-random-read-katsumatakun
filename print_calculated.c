#include <stdio.h>
#include "emp_rec.h"
#include "print_calculated.h"

/*
  This function takes two parameters. One is a pointer to "struct emp" and the other
  is a pointer to "struct paydata". Then it will print employee's name and payment
  data.

*/
void print_emp_data(empPtr q, pdataPtr p){
  printf("%-10s %-14s %6.2f %13.2f %10.2f %11.2f %12.2f \n",q->last_name, q->first_name,
  p->biWeeklySalary, p->fedTaxDeducted, p->stateTaxDeducted, p->medicalDeducted, p->netPay);
}
