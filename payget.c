#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
#include "print_calculated.h"


int main(int argc, char* argv[]) {

    FILE *fpr;
    if((fpr = fopen(argv[1], "rb")) == NULL ) {
      printf("Input file not open\n");
      return -1;
    }
    empPtr q;
    pdataPtr p;
    char *endp;
    int arg_num = 2;
    while(arg_num != argc){
    int record_num = strtol(argv[arg_num], &endp, 10);
    printf("%d\n", record_num);
    if (*endp == '\0'){
      fseek(fpr, (sizeof(struct emp) + sizeof(struct paydata))*(abs(record_num)-1), SEEK_SET);
      if(record_num <= 0 && fpr != NULL){
        fseek(fpr, (sizeof(struct emp) + sizeof(struct paydata))*(record_num), SEEK_END);
      }
      if((q = (empPtr) malloc(sizeof(struct emp))) == NULL || (p = (pdataPtr) malloc(sizeof(struct paydata)))== NULL){
        printf("No more memory space available \n");
        return -1;
      }
      if(fread(q, sizeof(struct emp), 1, fpr) && fread(p, sizeof(struct paydata), 1, fpr)){
        print_emp_data(q, p);
      }
      else{
        printf("There is no record for record%d\n", record_num);
      }
    }
    else{
      printf("Input value must be integer\n");
    }
    arg_num++;
  }

    fclose(fpr);

    return 0;
}
