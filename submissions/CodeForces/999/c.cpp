#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k; cin.ignore();
    string s;
    cin >> s;

    map<char, int> mp;
    for(char &c: s)
        mp[c]++;

    for(auto it = mp.begin(); it != mp.end(); it++){
        int temp = it->second;
        it->second -= k;
        k -= temp;
        if(k <= 0)
            break;
    }
    string ans;
    for(int i = n-1; i >= 0; i--){
        if(mp[s[i]]-- > 0)
            ans += s[i];
    }

    for(int i = ans.length()-1; i >= 0; i--)
        cout << ans[i];
    cout << endl;

}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int t;
	// cin >> t;
	// while(t--)
		solve();

	return 0;
}
