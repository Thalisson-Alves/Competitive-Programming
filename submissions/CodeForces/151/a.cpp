#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    enum things{friends, bottles, ml, limes, slides, salt, need_ml, need_salt};
    int ar[8];
    for(int i = 0; i < 8; i++){
        cin >> ar[i];
    }
    int ans = min({ar[bottles]*ar[ml]/ar[need_ml]/ar[friends], ar[salt]/ar[need_salt]/ar[friends], ar[slides]*ar[limes]/ar[friends]});
    cout << ans << endl;

    return 0;
}
