#include <stdio.h>
#include <stdlib.h>

// 20 work days every month
const int WORKING_DAY_NBR=20;
// BASE to calculate the ratio
const int BASE=10000;

// DEBUG
const int MIN=12992;
const int DIFF=(15593-12992);

void display(int x) {
  int i = 0;
  int nbr = 100 * (x-MIN)/DIFF;
  for (i=0; i<nbr; i++) {
    printf("-");
  }
  printf(">%d\n", x);
  return;
}

// Best result store 
static int result[6];

int monthlyincome(int n1, int n2, int n3, int days) {
  return days?BASE + ((n1 + n2 + n3) * days/(3*WORKING_DAY_NBR)):0;
}

void evaluate(int n1, int n2, int n3, int n4, int a, int b, int c, int cet) {
  int tmp = n1 + n2 + n3 + n4;
  int nbr = a?1:0;
  nbr += b?1:0;
  nbr += c?1:0;
  //printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%.6f\n", result[0], result[1], result[2], result[3], ((float) result[4])/(BASE * result[5]));
  if (tmp  >= result[4]) {
    result[0] = a;
    result[1] = b;
    result[2] = c;
    result[3] = (cet-a-b-c);
    result[4] = tmp;
    result[5] = nbr;
    //printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%.6f\n", result[0], result[1], result[2], result[3], ((float) result[4])/(BASE * result[5]));
  }
}

int calculate(int cet, int duration) {
  int a=0, b=0, c=0;
  int n1=0, n2=0, n3=0, n4=0, n5=0;
  int tmp=0, dure=0;
  
  printf("1st Mon\t|\t2nd Mon\t|\t3rd Mon\t|\t4th Mon\t|\tRatio\n");
  for (a=5; a<=cet; a++) {
    dure = duration - 1;
    n1=monthlyincome(BASE, BASE, BASE, a);
    if (((cet-a) < 5) || (dure <= 1)) {
      evaluate(n1, 0, 0, monthlyincome(BASE, BASE, n1, cet-a), a, cet-a, 0, cet);
      continue;
    }
    for (b=5; b<=(cet-a) && dure>1; b++) {
      dure = duration -2;
      n2=monthlyincome(BASE, BASE, n1, b); 
      if (((cet-a-b) < 5) || (dure <= 1)) {
        evaluate(n1, n2, 0, monthlyincome(BASE, n1, n2, cet-a-b), a, b, cet-a-b, cet);
        continue;
      }
      for (c=5; c<=(cet-a-b) && dure>1; c++) {
        n3=monthlyincome(BASE, n1, n2, c); 
        evaluate(n1, n2, n3, monthlyincome(n1, n2, n3, (cet-a-b-c)), a, b, c, cet);
      }
    } 
  }
  printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%.6f\n", result[0], result[1], result[2], result[3], ((float) result[4])/(BASE * result[5]));
  return 0;
}

int main(int argc, char **argv){

  if (argc == 2) {
    printf("Starting to processing on %s days for a period of 4 month\n", argv[1]);
    calculate(atoi(argv[1]), 4);
  } else 
  if (argc >= 3) {
    printf("Starting to processing on %s days for a period of 3 month\n", argv[1], 3);
    calculate(atoi(argv[1]), atoi(argv[2])==3?3:4);
  } else {
    printf("Please input the number of days in your CET as 2nd argument !!!\n");
  }


  return 0;
}
