#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int a, b, x;
    cin >> a >> b >> x;

    if(a + b >= x && a <= x)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
