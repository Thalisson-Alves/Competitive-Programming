#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int x[n], y[n], z[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }

    int sumx = 0, sumy=0, sumz=0;
    for(int i = 0; i < n; i++){
        sumx += x[i];
        sumy += y[i];
        sumz += z[i];
    }
    if(sumx == sumy && sumz == sumy && sumx == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
