#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int gem[n], coast[n], x=0;

    for (int i=0; i < n; i++){
        cin >> gem[i];
    }
    for (int i=0; i < n; i++){
        cin >> coast[i];
    }
    int m = 0;
    for (int i = 0; i < n; ++i){
        m += max(gem[i] - coast[i], 0);
    }
    cout << m;

    return 0;
}