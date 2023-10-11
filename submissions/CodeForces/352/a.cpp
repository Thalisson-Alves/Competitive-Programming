#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int fives = 0;
    int zeros = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 0)
            zeros++;
        else
            fives++;
    }
    if(!zeros)
        cout << -1 << endl;
    else{
        if(fives >= 9){
            for(int i = 0; i < fives-fives%9; i++){
                cout << 5;
            }
            for(int i = 1; i < zeros; i++){
                cout << 0;
            }
        }
        cout << 0;
    }
    return 0;
}
