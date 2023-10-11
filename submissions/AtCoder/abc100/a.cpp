#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(a <= 8 && b <= 8)
        cout << "Yay!\n";
    else
        cout << ":(\n";

    return 0;
}
