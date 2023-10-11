#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n; cin.ignore();
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] % 2 == 0){
            ans += i+1;
        }
    }
    cout << ans << endl;

    return 0;
}