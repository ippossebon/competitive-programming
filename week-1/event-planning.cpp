#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {

  int participants, budget, hotels, weeks;
  int min_cost, price_person_weekend, num_beds;

  while(cin >> participants && cin >> budget && cin >> hotels && cin >> weeks){
    min_cost = 999999;

    for (int i = 0; i < hotels; i++){
        // Lê os dados de cada hotel
        cin >> price_person_weekend; // lê o valor por pessoa

        for (int j = 0; j < weeks; j++){
          cin >> num_beds; // lê o número de camas disponível em cada final de semana

          if (num_beds >= participants){
            // Podemos considerar
            min_cost = min(min_cost, price_person_weekend * participants);

            string new_case;
					  getline(cin, new_case);
					  break;
          }
        }
    }

    if (min_cost <= budget){
      cout << min_cost << endl;
    }
    else{
      cout << "stay home" << endl;
    }
  }

  return 0;
}
