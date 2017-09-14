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

    int n, operation, number;
    bool is_stack, is_queue, is_prio_queue;

    while(cin >> n){
        stack<int> stack_numbers;
        queue<int> queue_numbers;
        priority_queue<int> prio_queue_numbers;

        is_stack = true;
        is_queue = true;
        is_prio_queue = true;


        for (int i = 0; i < n; i++){
            cin >> operation;
            cin >> number;

            if (operation == 1){
                /* Coloca os itens nas possíveis estruturas de dados */
                stack_numbers.push(number);
                queue_numbers.push(number);
                prio_queue_numbers.push(number);
            }
            else{
                /* Verifica se pode ser uma pilha */
                if (stack_numbers.empty()){
                    is_stack = false;
                }
                else{
                    // Verifica se o número é o mesmo número da entrada
                    if (stack_numbers.top() != number){
                        is_stack = false;
                    }
                    stack_numbers.pop(); // retira o número já lido da pilha
                }

                /* Verifica se pode ser uma fila (FIFO) */
                if (queue_numbers.empty()){
                    is_queue = false;
                }
                else{
                    // Verifica se o número é o mesmo número da entrada
                    if (queue_numbers.front() != number){
                        is_queue = false;
                    }
                    queue_numbers.pop(); // retira o número já lido da pilha
                }

                /* Verifica se pode ser uma fila de prioridades */
                if (prio_queue_numbers.empty()){
                    is_prio_queue = false;
                }
                else{
                    // Verifica se o número é o mesmo número da entrada
                    if(prio_queue_numbers.top() != number){
                        is_prio_queue = false;
                    }
                    prio_queue_numbers.pop(); // retira o número já lido da pilha
                }
            }
        }

        if ((is_stack && is_queue && is_prio_queue) || (is_stack && is_queue) || (is_stack && is_prio_queue) || (is_queue && is_prio_queue)){
                cout << "not sure" << endl;
        }
        else{
            if (is_stack){
                cout << "stack" << endl;

            }
            else if (is_queue){
                cout << "queue" << endl;
            }
            else if (is_prio_queue){
                cout << "priority queue" << endl;
            }
            else{
                cout << "impossible" << endl;
            }
        }

    }

  return 0;
}

