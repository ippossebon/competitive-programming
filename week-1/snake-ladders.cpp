#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int num_test_cases;
  int num_players, num_snakes, num_rolls;

  cin >> num_test_cases;

  for (int i = 0; i < num_test_cases; i++){
      //printf("*************************************\n");
      cin >> num_players;
      cin >> num_snakes;
      cin >> num_rolls;

      //printf("Caso de teste: num_players = %d, num_snakes = %d, num_rolls = %d\n", num_players, num_snakes, num_rolls);

      int begin, end;
      int line, column, rem;
      int snakes_position[num_snakes][2];

      for (int j = 0; j < num_snakes; j++){
          // Para cada cobra, registra a posição de início e fim
          cin >> begin;
          cin >> end;

          snakes_position[j][0] = begin;
          snakes_position[j][1] = end;
      }

      // Resultado de cada jogada do dados
      int players_position[num_players];
      for (int i = 0; i < num_players; i++){
          players_position[i] = 1;
      }

      int steps, position, player, game_end = 0;
      for (int k = 0; k < num_rolls; k++){
           cin >> steps;

           if (!game_end){
               if (num_players != 0){
                   player = k % num_players;
                   position = players_position[player] + steps;
               }

               if (position > 100){
                   position = 100;
               }

               for (int j = 0; j < num_snakes; j++){
                   // Verifica se encontra alguma cabeça da cobra
                   if (position == snakes_position[j][0]){
                       // Colidiu com a cabeça da cobra, então vai para a cauda
                       position = snakes_position[j][1];
                   }
               }

               players_position[player] = position;

               if (players_position[player] == 100){
                   game_end = 1;
               }
           }
      }

      for (int p = 0; p < num_players; p++){
          cout << "Position of player " << p + 1 << " is " << players_position[p] << ".\n";

      }
  }

  return 0;
}
