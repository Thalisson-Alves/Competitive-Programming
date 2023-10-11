#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int total = 0;
    int values[n];
    for(int i =0; i < n; i++){
        cin >> values[i];
        total += values[i];
    }
    sort(values, values+n);
    int ans = 0, sum = 0;
    for(int i = n-1; i >= 0; i--){
        if(sum <= (total)/2){
            ans++;
            sum += values[i];
        }
    }
    cout << ans << endl;

    return 0;
}