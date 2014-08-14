#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year);

int main(int narg, char *argv[]) {
  int day1, month1, year1,
      day2, month2, year2,
      i, temp, sum=0,
      month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  printf("Entre com a data 1 : (DD MM YYYY) : ");
  scanf("%d %d %d", &day1, &month1, &year1);

  printf("Entre com a data 2 : (DD MM YYYY) : ");
  scanf("%d %d %d", &day2, &month2, &year2);

  temp = day1;

  for(i = month1; i < month2 + (year2 - year1) * 12; i++) {
    if(i > 12) {
      i = 1;
      year1++;
    }

    if(i == 2) {
      if(isLeapYear(year1))
        month[i - 1] = 29;
      else
        month[i - 1] = 28;
    }

    sum = sum + (month[i - 1] - temp);
    temp = 0;
  }

  sum = sum + day2 - temp + 1;

  printf("\nDiferença em dias: %i\n",sum);
}

int isLeapYear(int year) {
  if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 1;

  return 0;
}