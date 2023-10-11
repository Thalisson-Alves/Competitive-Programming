#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        if((p[i] < p[i-1] && p[i] > p[i+1])||(p[i]>p[i-1] && p[i]<p[i+1]))
            ans++;
    }
    cout << ans << endl;

    return 0;
}
