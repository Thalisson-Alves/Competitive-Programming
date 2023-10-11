#include <bits/stdc++.h>

using namespace std;

int main (int argc, char* argv[])
{
    int matriz[5][5], pos[2];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> matriz[i][j];
            if (matriz[i][j] == 1){
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
    int contador = 0;
    while (true){
        if (pos[0] > 2){
            pos[0]--;
            contador++;
        }
        if (pos[0] < 2){
            pos[0]++;
            contador++;
        }
        if (pos[1] > 2){
            pos[1]--;
            contador++;
        }
        if (pos[1] < 2){
            pos[1]++;
            contador++;
        }
        if (pos[1] == 2 && pos[0] == 2)
            break;
    }
    cout << contador << '\n';

    return 0;
}
