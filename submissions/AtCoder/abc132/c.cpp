#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int d[n];
    for(int i = 0; i < n; i++)
        cin >> d[i];
    sort(d, d+n);
    int ans = n%2? 0: abs(d[n/2] - d[n/2-1]);
    cout << ans << endl;

    return 0;
}
