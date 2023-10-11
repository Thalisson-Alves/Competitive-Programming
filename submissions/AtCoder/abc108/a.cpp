#include <bits/stdc++.h>

using namespace std;

void solveA()
{
    int x;
    cin >> x;
    if (x == 7|| x == 5|| x == 3)
        cout << "YES\n";
    else
        cout << "NO\n";
}

void solveB()
{
    int a, b, c;
    cin >> a >> b >> c;

    int hp = max(a, b);
    hp = max(hp, c);

    int area;

    if (a == hp)
        area = (b * c) / 2;
    if (b == hp)
        area = (a * c) / 2;
    if (c == hp)
        area = (a * b) / 2;

    cout << area;
}

void solveC()
{
    int a, b;
    cin >> a >> b;
    if ((a*b) % 2 == 0)
        cout << "No\n";
    else
        cout << "Yes\n";
}

void solveD()
{
    int n, s=0, cp;

    cin >> n;
    cp = n;

    while (cp){
        s += cp%10;
        cp /= 10;
    }
    if (n % s == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}

void solveE()
{
    int n, t;

    cin >> n >> t;

    int rotas[n][2];

    int coast = INT_MAX;

    for (int i = 0; i < n; i++){

        cin >> rotas[i][0] >> rotas[i][1];

        if (rotas[i][1] < t){
            coast = min(coast, rotas[i][0]);
        }
    }
    if (coast == INT_MAX)
        cout << "TLE\n";
    else
        cout << coast << "\n";
}

void solveF()
{
    int k;
    cin >> k;
    int par = 0, impar = 0;
    for (int i = 1; i <= k ; i++){
        if (i % 2 == 0)
            par++;
        else
            impar++;
    }
    cout << par * impar << endl;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    solveF();

    return 0;
}
