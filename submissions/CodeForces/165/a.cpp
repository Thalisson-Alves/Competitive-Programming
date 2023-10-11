#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool l = false, r = false, u = false, d = false;
        for(int j = 0; j < n; j++){
            if(p[i].first > p[j].first && p[i].second == p[j].second)
                l = true;
            if(p[i].first < p[j].first && p[i].second == p[j].second)
                r = true;
            if(p[i].first == p[j].first && p[i].second > p[j].second)
                d = true;
            if(p[i].first == p[j].first && p[i].second < p[j].second)
                u = true;
        }
        if(l && r && u && d)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
