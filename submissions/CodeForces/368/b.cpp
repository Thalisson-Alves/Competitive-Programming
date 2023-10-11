#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int &x: a)
		cin >> x;
	set<int> st;
	ll suf[n];
	memset(suf, 0, sizeof suf);
	for(int i=n-1; i>=0; i--){
		st.insert(a[i]);
		suf[i] = st.size();
	}
	for(int i=0; i<m; i++){
		int l;
		cin >> l;
		cout << suf[l-1] << '\n';
	}
	
	return 0;
}
