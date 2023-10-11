#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int d[n-1];
    for(int i = 0; i < n-1; i++){
        cin >> d[i];
    }
    int a, b;
    cin >> a >> b;
    int dif = b-a;
    int ans = 0;
    for(int i = 0; i < dif; i++, a++){
        ans += d[a-1];
    }

    cout << ans << endl;

    return 0;
}
