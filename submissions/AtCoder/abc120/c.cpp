#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 0, z=0, o=0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '0')
            z++;
        if (s[i] == '1')
            o++;
    }
    cout << 2*min(z, o) << endl;

    return 0;
}