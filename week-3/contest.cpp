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

    long int n, s;

    cin >> n;
    cin.ignore();

    for (int j = 1; j <= n; j++){
      string team_out, judge_out;

      getline(cin, team_out);
      getline(cin, judge_out);

      if (team_out.compare(judge_out) == 0){
        cout << "Case " << j << ": Yes" << endl;
      }
      else{
        team_out.erase(remove(team_out.begin(), team_out.end(), ' '), team_out.end());
        if (team_out == judge_out){
          cout << "Case " << j << ": " << "Output Format Error" << endl;
        }
        else{
          cout << "Case " << j << ": " << "Wrong Answer" << endl;

        }
      }
    }

  return 0;
}
