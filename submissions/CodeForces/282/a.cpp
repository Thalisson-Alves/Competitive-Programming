#include <bits/stdc++.h>
using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;cin.ignore();
    int ans = 0;
    while(n--){
        string s;
        cin >> s; cin.ignore();
        ans += (s[1] == '-'? -1: 1);
    }
    cout << ans << endl;

    return 0;
}
