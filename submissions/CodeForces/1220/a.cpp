#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;cin.ignore();
    string s;
    cin >> s;
    int o=0, z=0;
    for (int i = 0; i < t; i++){
        if(s[i] == 'z')
            z++;
        if(s[i] =='n')
            o++;
    }
    while(o--){
        cout << '1';
        if (o > 1 || z)
            cout << " ";
        else
            cout << endl;
    }
    while(z--){
        cout << '0';
        if(z>1)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}