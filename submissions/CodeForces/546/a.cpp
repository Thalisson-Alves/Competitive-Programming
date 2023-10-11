#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long k, n, w;
    cin >> k >> n >> w;
    for(int i = 1; i <= w; i++){
        n -= i*k;
    }
    n = (n >= 0)? 0: -n;
    cout << n << endl;

    return 0;
}
