#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    int a, b;
    cin >> a >> b;
    int coins = 0, t = 2;
    while(t--){
        if (a >= b){
            coins += a;
            a--;
        }
        else{
            coins += b;
            b--;
        }
    }

    cout << coins << endl;

    return 0;
}