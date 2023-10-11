#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; ; i++){
        int n;
        cin >> n;
        if (n < 0)
            break;
        int ans = 0, total = 1;
        for (ans = 0; total < n; ans++, total*=2){}
        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}