#include <bits/stdc++.h>
using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
	cin >> n >> k; cin.ignore();
	string s;
	cin >> s;
	int open = 0;
	unordered_map<char, int> mp;
	unordered_set<char> st;
	for(int i = 0; i < n; i++)
        mp[s[i]] = i;
    auto t = st.size();
    string ans = "NO";
	for(int i = 0; i < n; i++){
        st.insert(s[i]);
        if(t != st.size())
            open++;
        t = st.size();
        if(open > k){
            ans = "YES";
            break;
        }
        if(i == mp[s[i]])
            open--;
	}
	cout << ans << endl;

    return 0;
}