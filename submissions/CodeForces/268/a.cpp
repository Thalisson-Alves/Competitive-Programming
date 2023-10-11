#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector< pair<int, int> > uni(n);
    for(int i = 0; i < n; i++){
        cin >> uni[i].first >> uni[i].second;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(uni[i].first == uni[j].second){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
