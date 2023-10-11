#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        int f;
        cin >> f;
        int fa[3];
        double ans = 0;
        for(int j = 0; j < f; j++){
            for (int i = 0; i < 3; i++){
                cin >> fa[i];
            }
            double sp = (double)fa[0] / fa[1];
            ans += sp * (double)fa[2] * (double)fa[1];
        }
        cout << (long long)ans << endl;
    }

    return 0;
}
