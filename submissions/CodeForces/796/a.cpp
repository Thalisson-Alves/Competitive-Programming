#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int INF = 1e9+5;
    int n, m, k;
    cin >> n >> m >> k;
    int price[n];
    int ans = INF;
    for(int i = 0; i < n; i++){
        cin >> price[i];
        if (price[i] <= k && abs(m-1-i)*10 < ans && price[i] != 0){
            ans = abs(m-1-i) * 10;
        }
    }
    cout << ans  << endl;

    return 0;
}