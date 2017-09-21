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

    int x1, y1, x2, y2, aux_x, aux_y;

    while(cin >> x1 >> y1 >> x2 >> y2){
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0){
          return 0;
        }

        if (x1 == x2 && y1 == y2){
          cout << "0" << endl;
        }
        else if (x1 == x2 || y1 == y2){
          cout << "1" << endl;
        }
        else if ((x2 - x1) == - (y2 - y1) || -(x2 - x1) == -(y2 - y1) || -(x2 - x1) == (y2 - y1) || (x2 - x1) == (y2 - y1)){
          cout << "1" << endl;
        }
        else{
          cout << "2" << endl;
        }

    }

  return 0;
}
