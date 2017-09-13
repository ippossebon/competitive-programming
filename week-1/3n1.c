#include <stdio.h>
#include <stdlib.h>

void calculate(int n, int *count);

int main(int argc, char const *argv[]) {

  int i, j, x;

  while (scanf("%d %d", &i, &j)==2) {

    int max_count = 0;
    int count = 0;
    int begin = i, end = j;

    if (i > j){
      begin = j;
      end = i;
    }

    for (x = begin; x <= end; x++){
      count = 0;
      calculate(x, &count);

      if (count > max_count){
        max_count = count;
      }
    }

    printf("%d %d %d\n", i, j, max_count);
  }
  return 0;
}

void calculate(int n, int *count){
    if (n == 1) {
      (*count)++;
      return;
    }
    if (n % 2 == 1){
      n = 3 * n + 1;
      (*count)++;
      calculate(n, count);
    }
    else{
      n = n/2;
      (*count)++;
      calculate(n, count);
    }
}
