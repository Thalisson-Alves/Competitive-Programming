#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	unordered_map<int, int> mp;
	int mn = 1e9+7, mx = 0;
	for(int &x: a){
		mp[x]++;
		if(x > mx)
			mx = x;
		if(x < mn)
			mn = x;
	}
	
	function<ll(int)> sum = [&sum](int n) -> ll {return (n <= 0? 0: (ll)n-1 + sum(n-1)); };
	cout << mx-mn << " " << (mx==mn? sum(mp[mx]): (ll)mp[mx]*mp[mn]) << endl;
	
	return 0;
}
