#include <bits/stdc++.h>

using namespace std;

string solve(string s)
{
    for(char c: s)
        if(c == 'Q' || c == 'H' || c == '9')
            return "YES";
    return "NO";
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    auto ans = solve(s);
    cout << ans << endl;

    return 0;
}
