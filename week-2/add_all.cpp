#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

long long int n, x, custo_parcial = 0, total = 0, n1, n2, aux = 0;

    cin >> n;

    while(n != 0){
      priority_queue<int, vector<int>, greater<int> > numbers;
      total = 0;
      custo_parcial = 0;

      for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.push(x);
      }

      if (n == 1){
        n1 = numbers.top();
        numbers.pop();

        total = 0;
      }

      while (numbers.size() > 1){
        // if (aux == 2){
        //   exit(0);
        // }

        n1 = numbers.top();
        numbers.pop();

        // cout << "n1 = " << n1 << endl;

        n2 = numbers.top();
        numbers.pop();

        // cout << "n2 = " << n2 << endl;

        custo_parcial = n1 + n2;
        total += custo_parcial;

        // cout << "total = " << total << endl;
        // cout << "parcial = " << custo_parcial << endl;

        numbers.push(custo_parcial);

        // cout << "Depois de fazer total+custo_parcial, total = " << total << " custo_parcial = " << temp << endl;
      }

      cout << total << "\n";
      cin >> n;

    }

  return 0;
}
