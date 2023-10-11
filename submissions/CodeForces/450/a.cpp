#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int ans = n;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(make_pair(x, i+1));
    }

    while(!q.empty()){
        if(q.front().first > m)
            q.push(make_pair(q.front().first -m, q.front().second));
        ans = q.front().second;
        q.pop();
    }

    cout << ans << endl;

    return 0;
}
