#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    while(cin >> a){
        cin >> b;
        cout << abs(a-b) << endl;
    }

    return 0;
}