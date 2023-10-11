#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if(a >= 13)
        cout << b << endl;
    else if(a >= 6)
        cout << b/2 << endl;
    else
        cout << 0 << endl;

    return 0;
}