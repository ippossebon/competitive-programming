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

using namespace std;

int main() {

    int largura_elevador, comp_elevador, r1, r2;
    double dx, dy;

    while(cin >> largura_elevador >> comp_elevador >> r1 >> r2){
        if (largura_elevador == 0 && comp_elevador == 0 && r1 == 0 && r2 == 0){
          return 0;
        }

        dx = largura_elevador - r1 - r2;
        dy = comp_elevador - r1 - r2;

        if (dx < 0 || dy < 0){
          cout << "N" << endl;
        }
        else if (((dx * dx) + (dy * dy) >= (r1 + r2) * (r1 + r2)) && (min(largura_elevador, comp_elevador) >= 2 * max(r1, r2))){
          cout << "S" << endl;
        }
        else{
          cout << "N" << endl;
        }
    }

  return 0;
}
