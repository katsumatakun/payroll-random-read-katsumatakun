#include <stdio.h>
#include "emp_rec.h"
#include "print_calculated.h"

void print_emp_data(empPtr q, pdataPtr p){
printf("%-10s %-14s %6.2f %13.2f %10.2f %11.2f %12.2f \n",q->last_name, p->first_name,
p->biWeeklySalary, p->fedTaxDeducted, p->stateTaxDeducted, p->medicalDeducted, p->netPay);
}
