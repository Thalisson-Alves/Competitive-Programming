#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    s[0] -= (s[0] > 96)? 32: 0;
    cout << s << endl;

    return 0;
}
