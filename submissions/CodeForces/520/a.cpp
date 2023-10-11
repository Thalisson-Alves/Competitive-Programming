#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n; cin.ignore();
	string s;
	cin >> s;
	if(n <= 25){
        cout << "NO\n";
        return;
	}
	unordered_set<char> st;
	for(char c: s)
        st.insert((c < 96? c+32: c));
    if(st.size() > 25)
        cout << "YES\n";
    else
        cout << "NO\n";

}
int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int t;
    //cin >> t;
    //while(t--)
        solve();

    return 0;
}

