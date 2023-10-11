#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n; cin.ignore();
    string stones;
    cin >> stones;
    if(n < 2){
        cout << 0 << endl;
        return 0;
    }
    char current = stones[0];
    int ans = 0;
    for(int i = 1; i < n; ++i){
        if(stones[i] == current)
            ans++;
        else
            current = stones[i];
    }
    cout << ans << endl;

    return 0;
}
