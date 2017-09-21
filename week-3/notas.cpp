#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


int main() {

    int n, valor;
    int notas_100 = 0, notas_50 = 0, notas_20 = 0, notas_10 = 0, notas_5 = 0, notas_2 = 0, notas_1 = 0;
    cin >> n;

    valor = n;
    while(valor != 0){
      if (valor - 100 >= 0){
        valor = valor - 100;
        notas_100++;
      }
      else if (valor - 50 >= 0){
        valor = valor - 50;
        notas_50++;
      }
      else if (valor - 20 >= 0){
        valor = valor - 20;
        notas_20++;
      }
      else if (valor - 10 >= 0){
        valor = valor - 10;
        notas_10++;
      }
      else if (valor - 5 >= 0){
        valor = valor - 5;
        notas_5++;
      }
      else if (valor - 2 >= 0){
        valor = valor - 2;
        notas_2++;
      }
      else if (valor - 1 >= 0){
        valor = valor - 1;
        notas_1++;
      }
    }
    // Saida
    cout << n << endl;
    printf("%d nota(s) de R$ 100,00\n", notas_100);
    printf("%d nota(s) de R$ 50,00\n", notas_50);
    printf("%d nota(s) de R$ 20,00\n", notas_20);
    printf("%d nota(s) de R$ 10,00\n", notas_10);
    printf("%d nota(s) de R$ 5,00\n", notas_5);
    printf("%d nota(s) de R$ 2,00\n", notas_2);
    printf("%d nota(s) de R$ 1,00\n", notas_1);

  return 0;
}
