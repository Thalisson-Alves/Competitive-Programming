#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int &x: a)
		cin >> x;
	vector<ll> suf(n+1);
	for(int i=n-1; i>=0; i--)
		suf[i] = suf[i+1] + a[i];
	int best_suf = 0;
	for(int i=1; i<n-k+1; i++)
		if(suf[i]-suf[i+k] > suf[best_suf]-suf[best_suf+k])
			best_suf = i;
	function<ll(int)> sum = [&sum](int a){return a? (ll)a+sum(a-1): 0;};
	double ans = 0;
	for(int i=best_suf; i<best_suf+k; i++)
		ans += (double)sum(a[i])/a[i];
	cout << fixed << setprecision(12) << ans << endl; 
	
	return 0;
}