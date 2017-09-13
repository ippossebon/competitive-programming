#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {

  long long int n, x, diff;
  bool jolly;

    while(cin >> n){
      jolly = true;
      vector<int> numbers;
      vector<bool> read(n, false);

      for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.push_back(x);
      }

      for (int k = 1; k < n; k++){
        diff = abs(numbers[k] - numbers[k-1]);

        if (diff>=n || read[diff]){
          jolly = false;
          break;
        }
        else{
          read[diff]=true;
        }
      }

      if (jolly) cout << "Jolly" << endl;
      else cout << "Not jolly" << endl;
    }

  return 0;
}
