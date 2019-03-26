#include <stdio.h>
#include "emp_rec.h"
#include "print_calculated.h"

/*
  This function takes two parameters. One is a pointer to "struct emp" and the other
  is a pointer to "struct paydata". Then it will print employee's name and payment
  data.

*/
void print_emp_data(empPtr q, pdataPtr p){
  printf("==================================================================================\n");
  printf("Lname    Fname      address              city           state   zipcode   id\n");
  printf("----------------------------------------------------------------------------------\n");
  printf("%-8s %-10s %-20s %-15s %-6s %-8s %5ld \n",q->last_name, q->first_name, q->addr,
  q->city, q->state, q->zipcode, q->emp_id);
  printf("==================================================================================\n");
  printf("bi-weekly pay  federal tax  state tax  insurance     net pay \n");
  printf("----------------------------------------------------------------------------------\n");
  printf("%7.2f %14.2f %12.2f %11.2f %12.2f \n",
  p->biWeeklySalary, p->fedTaxDeducted, p->stateTaxDeducted, p->medicalDeducted, p->netPay);
  printf("==================================================================================\n\n");
}
