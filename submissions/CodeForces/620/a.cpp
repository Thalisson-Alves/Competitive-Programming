#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int ans = max(abs(x1 - x2), abs(y1 - y2));
    cout << ans << endl;

    return 0;
}
