#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int maior;
    maior = max(a, b);
    maior = max(c, maior);

    while(k--){
        if(a >= maior)
            a *= 2;
        else
        if(b >= maior)
            b *= 2;
        else
        if(c >= maior)
            c *= 2;
    }
    cout << a+b+c;

    return 0;
}
