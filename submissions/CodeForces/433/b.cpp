#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	vector<ll> pref(n+1);
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		pref[i+1] = pref[i]+a[i];
	}
	sort(a, a+n);
	vector<ll> sorted_pref(n+1);
	for(int i=0; i<n; i++){
		sorted_pref[i+1] = sorted_pref[i] + a[i];
	}
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int type, l, r;
		cin >> type >> l >> r;
		cout << (type == 1? pref[r]-pref[l-1]: sorted_pref[r]-sorted_pref[l-1]) << '\n';
	}
	
	return 0;
}