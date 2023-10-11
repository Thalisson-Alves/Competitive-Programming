#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int win = 0;
    for(int i = 0; i < n; i++){
        int m, c;
        cin >> m >> c;
        if(m > c)
            win++;
        else if(m < c)
            win--;
    }
    if(win > 0)
        cout << "Mishka\n";
    else if (win < 0)
        cout << "Chris\n";
    else
        cout << "Friendship is magic!^^\n";

    return 0;
}
