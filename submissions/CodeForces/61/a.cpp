#include <bits/stdc++.h>

using namespace std;

string solve(string a, string b)
{
    string ans;
    for(int i = 0; i < a.size(); i++)
        if(a[i] == b[i])
            ans += '0';
        else
            ans += '1';
    return ans;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a; cin.ignore();
    cin >> b;

    auto ans = solve(a, b);
    cout << ans << endl;

    return 0;
}
