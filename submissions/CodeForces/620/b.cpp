#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int segments[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int ans = 0;
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        int n = i;
        if(n == 0)
            ans += segments[n];
        while(n){
            ans += segments[n%10];
            n/=10;
        }
    }

    cout << ans << endl;

    return 0;
}
