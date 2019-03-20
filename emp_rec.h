#ifndef _EMP_REC_H_
#define _EMP_REC_H_

typedef struct emp *empPtr;
typedef struct paydata *pdataPtr;

struct emp {
  char last_name[25];
  char first_name[20];
  char addr[80];
  char city[40];
  char state[3];
  char zipcode[10];
  long emp_id;
  float monthly_salary;
  float fed_tax_percent;
  float state_tax_percent;
  float total_medical;
  char status;
};

struct paydata {
  float biWeeklySalary;
  float fedTaxDeducted;
  float stateTaxDeducted;
  float medicalDeducted;
  float netPay;
};

#endif
