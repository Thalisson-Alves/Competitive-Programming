#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    string p;
    cin >> p;

    char color = p[0];
    int ans = 0;
    for (int i = 1; i < p.size(); i++){
        if(color == p[i]){
            ans++;
            if (p[i] == '0')
                p[i] = '1';
            else
                p[i] = '0';
        }
        color = p[i];
    }
    cout << ans << endl;

    return 0;
}
