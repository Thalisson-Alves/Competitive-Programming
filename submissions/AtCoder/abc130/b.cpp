#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    int l[n];
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    int c = 0;
    int bounce[n+1] = {0};
    for (int i = 0; i < n; i++){
        c += l[i];
        bounce[i] = c;
    }
    for (int i = 0; i <= n; i++){
        if(bounce[i] <= x)
            ans++;
    }
    cout << ans << endl;

    return 0;
}