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

    long int n, s;

    while(cin >> n){
      for (int j = 1; j <= n; j++){
        vector<int> salarios;

        for (int i = 0; i < 3; i++){
          cin >> s;
          salarios.push_back(s);
        }

        sort(salarios.begin(), salarios.end());
        cout << "Case " << j << ": " << salarios[1] << endl;
      }

    }

  return 0;
}
