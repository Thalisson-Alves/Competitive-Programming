#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int maior = a[0];
    for (int i = 0; i < n; i++){
        if (maior <= a[i]){
            ans++;
            maior = a[i];
        }
    }
    cout << ans << endl;

    return 0;
}
