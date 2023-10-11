#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    while(k--){
        if(n %10 == 0){
            n/=10;
        }
        else{
            --n;
        }
    }
    cout << n << endl;

    return 0;
}