#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 2 == 0){
        cout << n;
    }else
    cout << n*2;

    return 0;
}
