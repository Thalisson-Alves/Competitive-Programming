#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int l_closed = 0, r_closed = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        if(l == 0) l_closed++;
        if(r == 0) r_closed++;
    }

    cout << min(l_closed, n-l_closed) + min(r_closed, n-r_closed) << endl;

    return 0;
}
