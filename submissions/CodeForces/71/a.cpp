#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;cin.ignore();
        if(s.length() > 10)
            cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        else
            cout << s << endl;
    }

    return 0;
}
