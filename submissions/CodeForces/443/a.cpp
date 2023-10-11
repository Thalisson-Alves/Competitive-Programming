#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dp[26]={0};

    string line;
    getline(cin, line);
    set<char> words;
    for(int i = 1; i < (int)line.size()-1; ++i){
        if(line[i] >= 97 && line[i] <= 122)
            words.insert(line[i]);
    }
    int ans = words.size();
    cout << ans << endl;

    return 0;
}
