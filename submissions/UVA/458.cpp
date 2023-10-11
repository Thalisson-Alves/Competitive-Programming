#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while(getline(cin, line)){
        for(int i = 0; i < (int) line.size(); i++){
            cout << (char) (line[i] - 7);
        }
        cout << endl;
    }

    return 0;
}
