#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> st(n);
    for(int i = 0; i < n; i++)
        cin >> st[i];

    int m;
    cin >> m;
    ll ans = st[0];
    ll mxH = st[0];
    for(int i = 0; i < m; i++){
        ll w, h;
        cin >> w >> h;
        ans = max(st[w-1], mxH);
        mxH = max(st[w-1] + h, mxH+h);
        cout << ans << endl;
    }

    return 0;
}
