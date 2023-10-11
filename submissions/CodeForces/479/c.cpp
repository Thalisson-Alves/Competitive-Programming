#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector< pair<long, long> > day(n);
    for(int i = 0; i < n; i++){
        cin >> day[i].first >> day[i].second;
    }

    sort(day.begin(), day.end());

    int ans=-1;
    for(int i = 0; i < n; i++){
        if(day[i].second >= ans){
            ans = day[i].second;
        }
        else{
            ans = day[i].first;
        }
    }
    cout << ans << endl;

    return 0;
}