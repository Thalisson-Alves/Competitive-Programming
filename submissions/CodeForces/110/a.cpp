#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    cin >> n;
    int nearly_lucky_count = 0;
    for(int i = 0; i < n.length(); ++i){
        if(n[i] == '4' || n[i] == '7')
            nearly_lucky_count++;
    }
    bool nearly_lucky = true;
    for(char c: to_string(nearly_lucky_count))
        if(c != '4' && c != '7'){
            nearly_lucky = false;
            break;
        }
    if (nearly_lucky)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
