#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	function<ll(int)> sum = [&sum](int n){return n? (ll)n-1+sum(n-1): 0;};
	cout << sum(n)+sum(m) << endl;
	
	return 0;
}