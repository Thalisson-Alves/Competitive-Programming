#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int, pair<int, int>> mp;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a] = make_pair(i+1, n-i);
    }
    int m;
    cin >> m;
    pair<ll, ll> ans;
    for(int i = 0; i < m; i++){
        int b;
        cin >> b;
        ans.first += mp[b].first;
        ans.second += mp[b].second;
    }

    cout << ans.first << " " << ans.second << endl;

    return 0;
}