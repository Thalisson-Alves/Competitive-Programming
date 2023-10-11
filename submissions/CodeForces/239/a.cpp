#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int y, k, n;
    cin >> y >> k >> n;
    bool vl = true;
    int ans = k - y%k;
    while(ans + y <= n){
        vl = false;
        cout << ans << " ";
        ans += k;
    }
    if(vl)
        cout << -1 << endl;
    else
        cout << endl;

    return 0;
}