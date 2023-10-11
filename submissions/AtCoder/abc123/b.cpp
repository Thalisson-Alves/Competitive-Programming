#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    int a[5];
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }
    int t = 0;
    int ultima = a[0];
    for (int i = 1; i < 5; i++){
        if (a[i] % 10 != 0)
        if (10 - ultima % 10 < 10 - a[i] % 10){
            ultima = a[i];
        }
    }
    int ult = ultima;
    for (int i = 0; i < 5; i++){
        if (a[i] == ultima){
            ultima = -1;
            continue;
        }
        if (a[i] % 10 != 0)
            t += a[i] + 10 - (a[i] % 10);
        else
            t += a[i];
    }

    cout << t + ult << endl;

    return 0;
}