#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> remaining(n);
    for(int i = 0; i < n; i++){
        cin >> remaining[i];
    }
    sort(remaining.begin(), remaining.end());
    int ans = 0;
    for(int i = n-1; i > 0; i--){
        ans += remaining[i] - remaining[i-1] - 1;
    }
    cout << ans << endl;

    return 0;
}
