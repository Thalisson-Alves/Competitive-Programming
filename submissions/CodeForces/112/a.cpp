#include <bits/stdc++.h>

using namespace std;

void to_upper(string& s)
{
    for(char &c: s)
        c = c>=97? c-32: c;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);
    to_upper(a);
    to_upper(b);

    if(a == b)
        cout << 0 << endl;
    else if(a > b)
        cout << 1 << endl;
    else
        cout << -1 << endl;

    return 0;
}
