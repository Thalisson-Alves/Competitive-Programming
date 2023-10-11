#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int read[7];
    for(int i = 0; i < 7; i++){
        cin >> read[i];
    }
    int ans, sum = 0;
    for(ans = 0; sum < n; ans++){
        ans %= 7;
        sum += read[ans];
    }
    cout << ans << endl;

    return 0;
}
