#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    for(int i = 0, j = 0; i < s.length(); i++){
        if(s[i] >= '1' && s[i] <= '3'){
            s[j++] = s[i];
            (i+1 != s.length())? s[j++] = '+': '\n';
        }
    }
    cout << s;

    return 0;
}
