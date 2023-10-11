#include <bits/stdc++.h>

using namespace std;

int somaDig(int a, int b){
    int soma = 0;
    while(a){
        soma += a%10;
        a/=10;
    }
    while(b){
        soma += b%10;
        b/=10;
    }
    return soma;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);

    int a, b, n;
    cin >> n;

    int resp = somaDig(n/2, n-(n/2));
    int i = 0;
    while (true){
        int a;
        a = pow(10, i);
        if (resp > somaDig(a, n-a))
            resp = somaDig(a, n-a);
        else
            break;
    }
    cout << resp;

    return 0;
}
