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

int main(int qtd, char* nome[])
{
    solveB();

    return 0;
}