#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

    int n, magnitude, count;
    int samples[1005];
    bool up, down;

    while(cin >> n && n != 0){
        count = 0;
        down = false;
        up = false;

        for (int i = 0; i < n; i++){
            cin >> magnitude;
            samples[i] = magnitude;
        }

        if (samples[n-1] < samples[0]){
            up = true;
        }
        else {
            down = true;
        }

        samples[n] = samples[0];

        for (int j = 1; j <= n; j++) {
            if (samples[j-1] < samples[j] && down) {
                down = false;
                up = true;
                count++;
            }
            else if (samples[j-1] > samples[j] && up) {
                down = true;
                up = false;
                count++;
            }
        }
        cout << count << endl;
    }

  return 0;
}
