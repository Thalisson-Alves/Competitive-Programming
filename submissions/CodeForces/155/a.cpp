#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x, menor, maior;
        cin >> x;
        if(i == 0){
            menor = x;
            maior = x;
        }
        else{
            if(x > maior){
                maior = x;
                ans++;
            }
            if(x < menor){
                menor = x;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
