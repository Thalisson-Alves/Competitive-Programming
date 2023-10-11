#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    bool hard = false;
    while(n--){
        int x;
        cin >> x;
        if (x == 1){
            hard = true;
        }
    }
    if (hard){
        cout << "HARD\n";
    }else
        cout << "EASY\n";

    return 0;
}
