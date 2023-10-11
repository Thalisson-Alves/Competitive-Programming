#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, k;
    cin >> a>> b >> k;

    vector<int> m;
    for (int i = 1; i <= min(a, b); i++){
        if (a % i == 0 && b % i == 0)
            m.push_back(i);
    }
    cout << m[m.size()-k] <<  endl;

    return 0;
}