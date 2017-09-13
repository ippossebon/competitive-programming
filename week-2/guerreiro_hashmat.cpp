#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {

  long long int hashmat_soldiers, oponent_soldiers, diff, max;
    while(cin >> hashmat_soldiers >> oponent_soldiers){
      diff = abs(hashmat_soldiers - oponent_soldiers);
      cout << diff << "\n";
    }

  return 0;
}
