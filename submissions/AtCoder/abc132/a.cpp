#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    string ans = "Yes";
    int c = 0;
    char c1=s[0], c2 = (s[1]!=c1)? s[1]: s[2];
    for(int i = 0; i < 4; ++i){
        if(s[i] != c1 && c2 != s[i]){
            ans = "No";
        }
        if(c1 == s[i])
            c++;
    }
    if(c != 2)
        ans = "No";

    cout << ans << endl;

    return 0;
}