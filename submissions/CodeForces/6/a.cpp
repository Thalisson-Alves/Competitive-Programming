#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l[4];
    for(int i =0 ; i < 4; i++)
        cin >> l[i];
    sort(l, l+4);

    string ans;
    if(l[0]+l[1] > l[2] || l[1] + l[2] > l[3])
        ans = "TRIANGLE";
    else if (l[0]+l[1] == l[2] || l[1] + l[2] == l[3])
        ans = "SEGMENT";
    else
        ans = "IMPOSSIBLE";

    cout << ans << endl;

    return 0;
}
