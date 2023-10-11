#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    string ans;
    for(int i = 0; i < n; i++){
        ans += (s[i] == '.') ? '0' : (i < n-1 && s[++i] == '-') ? '2' : '1' ;
    }
    cout << ans << endl;

    return 0;
}
