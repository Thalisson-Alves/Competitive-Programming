#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string guest, host, pile;
    cin >> guest >> host >> pile;
    unordered_map<char, int> mp;
    for(char c: guest){
        mp[c]++;
    }
    for(char c: host){
        mp[c]++;
    }
    int ans = guest.size() + host.size();
    for(char c: pile){
        auto it = mp.find(c);
        if(it != mp.end()){
            it->second--;
            ans = it->second >= 0? ans-1: ans+1000;
        }
        else
            ans = 1e5+1;
    }
    if(ans)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}
