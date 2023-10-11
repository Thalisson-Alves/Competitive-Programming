#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n > 2){
        for(int i = 2; i <= n; i++)
            cout << i << " ";
        cout << 1 << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
