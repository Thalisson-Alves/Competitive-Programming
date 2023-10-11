#include <bits/stdc++.h>

using namespace std;

void solveA()
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
}

void solveB()
{
    int p, q, r;
    int ans = 0;
    cin >> p >> q >> r;
    int menor = min(p, q);
    menor = min(menor, r);
    ans = menor;
    if (menor == p){
        ans += min(q, r);
    }
    else
    if (menor == q){
        ans += min(r, p);
    }
    else{
        ans += min(p, q);
    }

    cout << ans << endl;
}

void solveC()
{
    int a[5], k;
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }
    cin >> k;
    int maior = a[0], menor = a[0];
    for(int i = 1; i < 5; i++){
        maior = max(maior, a[i]);
        menor = min(menor, a[i]);
    }
    int dist = maior - menor;
    if (dist > k)
        cout << ":(\n";
    else
        cout << "Yay!\n";

}

int main(int qtd, char* nome[])
{
    solveC();

    return 0;
}