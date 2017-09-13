#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int tamX, tamY, zeros1, zeros2;
    int dir=0, esq=0, cima=0, baixo=0;
    string linha;
    int direcao = 1;
    int ondeEstouX, ondeEstouY;

    cin >> tamX >> tamY;
    while(tamX != 0 && tamY != 0){

        int matriz[tamX][tamY];
        int ondeAndei[tamX][tamY];

        ondeEstouX= tamX-1;
        ondeEstouY = 0;

        for(int i=0; i<tamX; i++){
            cin >> linha;
            for(int j=0; j<tamY; j++){
                matriz[i][j] = (int)linha[j] - 48; // garante que será int
                //cout << matriz[i][j] << " ";
            }
            //cout << "\n";
        }

         for(int i=0; i<tamX; i++){
            for(int j=0; j<tamY; j++){
                if(matriz[i][j] == 1){
                    ondeAndei[i][j] = -1;
                }else{
                    ondeAndei[i][j] = 0;
                }
                if (i == tamX-1 && j == 0){
                    // Marca a posição inicial
                    ondeAndei[i][j] = 1;
                }
                //cout << ondeAndei[i][j] << " ";
            }
            //cout << "\n";
        }
        //cin >> zeros1 >> zeros2;

        do{
            if(direcao ==1){ // --> lado direito

                if(ondeEstouY+1 < tamY && matriz[ondeEstouX][ondeEstouY+1] == 0){ //posso andar para a direita?
                    if(ondeEstouX==tamX-1 || matriz[ondeEstouX+1][ondeEstouY] == 1){ //tem parede na prox posicao a direita?
                        ondeEstouY++;
                        dir++;
                        ondeAndei[ondeEstouX][ondeEstouY]++;


                    }else{//vira esquerda
                        direcao = 2;
                        //cout << "vou virar" << endl;
                    }
                }else{ //vira para esquerda
                    //cout << "nao posso andar p direita\n";
                    direcao = 0;
                    //cout << "vou virar" << endl;
                }

            }else if(direcao == 2){ //para baixo
                if(ondeEstouX+1 < tamX && matriz[ondeEstouX+1][ondeEstouY] == 0){ //posso andar para baixo?
                    //cout << "posso andar para baixo";
                    if(ondeEstouY==0 || matriz[ondeEstouX][ondeEstouY-1] == 1){ //tem parede na prox posicao a direita?
                        ondeEstouX++;
                        ondeAndei[ondeEstouX][ondeEstouY]++;
                        //cout << "sigo baixo " << endl;
                    }else{//vira esquerda
                        direcao = 3;
                        //cout << "vou virar 1" << endl;
                    }
                }else if(matriz[ondeEstouX-1][ondeEstouY-1] == 1){ //vira para esquerda
                    //cout << "vira para esquerda";
                    direcao = 3;

                }else{
                    direcao = 1;
                    //cout << "vou virar 1" << endl;
                }

            }else if(direcao ==3){ //lado esquerdo

                if(ondeEstouY-1 >= 0 && matriz[ondeEstouX][ondeEstouY-1] == 0){ //posso andar para a esquerda?
                    if(ondeEstouX==0 || matriz[ondeEstouX-1][ondeEstouY-1] == 1){ //tem parede na prox posicao a direita?
                        ondeEstouY--;
                        ondeAndei[ondeEstouX][ondeEstouY]++;

                    }else{//vira esquerda
                        //cout << "nao tem parede na direita, vou para cima\n";
                        direcao = 0;
                        //cout << "vou virar" << endl;
                    }
                }else{ //vira para baixo
                    direcao = 2;
                    //cout << "vou virar para baixo" << endl;
                }

            }else if(direcao == 0){ //para cima

                if(ondeEstouX-1 >= 0 && matriz[ondeEstouX-1][ondeEstouY] == 0){ //posso andar para cima?
                    if(ondeEstouY+1 == tamY || matriz[ondeEstouX][ondeEstouY+1] == 1){ //tem parede na prox posicao a direita?
                        ondeEstouX--;
                        ondeAndei[ondeEstouX][ondeEstouY]++;

                    }else{//vira esquerda
                        direcao = 1;
                        //cout << "vou virar para 1" << endl;
                    }
                }else{ //vira para esquerda
                    //cout << "nao posso andar para cima";
                    direcao = 3;
                    //cout << "vou virar para esquerda" << endl;
                }
            }
            //cout << ondeEstouX << " " << ondeEstouY << endl;
        }while(!(ondeEstouX == tamX-1 && ondeEstouY == 0));

        // Printa por onde andou a cada vez
        int visitou0 = 0, visitou1 = 0, visitou2 = 0, visitou3 = 0, visitou4 = 0;

        for (int i = 0; i < tamX; i++){
            for (int j = 0; j < tamY; j++){
                if (ondeAndei[i][j] == 0){
                    visitou0++;
                }
                else if(ondeAndei[i][j] == 1){
                    visitou1++;
                }
                else if(ondeAndei[i][j] == 2){
                    visitou2++;
                }
                else if(ondeAndei[i][j] == 3){
                    visitou3++;
                }
                else if(ondeAndei[i][j] == 4){
                    visitou4++;
                }
            }
        }
        cout << visitou0 << " " << visitou1 << " " << visitou2 << " " << visitou3 << " " << visitou4;

        cin >> tamX >> tamY;
    }

    return 0;
}
