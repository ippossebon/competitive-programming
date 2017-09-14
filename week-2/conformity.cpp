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

    int n, course_code, aux;

    typedef map<vector<int>, int> MapType; // torna o código mais legível
    MapType courses_map;


    while(cin >> n && n != 0){

      int popularity_count[n] = {0};
      aux = 0;

      for (int i = 0; i < n; i++){
         vector<int> courses;

         /* Preenche o vetor que guarda cada uma das disciplinas e ordena-o */
         for (int j = 0; j < 5; j++){
             cin >> course_code;
             courses.push_back(course_code);
         }
         sort(courses.begin(), courses.end());


         /* Cria um iterador do tipo do mapa que estamos utilizando. Com esse iterador,
         itera sobre cada um dos pares (conjunto_disciplinas, count) do mapa.
         iterator.first retorna o conjunto de disciplinas
         iterator.second retorna o contador desse conjunto

         Procura a combinação de cursos mais popular.

         100 101 102 103 488
         100 200 300 101 102
         103 102 101 488 100

         100, 101, 102, 103, 488
         100, 101, 102, 200, 300
         100, 101, 102, 103, 488
         */

         // Verifica se a combinação de cursos existe no mapa
         MapType::iterator it = courses_map.find(courses);
         if (it != courses_map.end()){
           // Combinação existe, portanto, contabiliza
           popularity_count[it->second]++;
         }
         else{
            // Se essa combinação ainda não existe, insere no mapa
             courses_map.insert({courses, aux});
             popularity_count[aux]++;
             aux++;
         }

         int most_pop = *max_element(popularity_count, popularity_count + n);
         int frosh_count = 0;

         for (int k = 0; k < n; k++){
           if (popularity_count[k] == most_pop){
             frosh_count += most_pop;
           }
         }

         cout << frosh_count << endl;
    }

  return 0;
}
