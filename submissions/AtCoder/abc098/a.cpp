#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int maior;
    maior = max(a+b, a-b);
    cout << max(maior, a*b);

    return 0;
}
