#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int lower_case = 0;
    for(char c: s){
        lower_case += (c >= 97)? 1 : 0;
    }
    if(lower_case >= s.length()/2.0)
        for(char c: s){
            c += (c < 97) ? 32 : 0;
            cout << c;
        }
    else
        for(char c: s){
            c -= (c > 96) ? 32 : 0;
            cout << c;
        }

    return 0;
}
