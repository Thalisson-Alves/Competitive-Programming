#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	int d[k];
	for(int i=0; i<k; i++)
		cin >> d[i];
	int ans;
	function<bool(int)> f = [&d, &k](int n){
		while(n){
			int digit = n%10;
			for(int i=0; i<k; i++)
				if(digit == d[i])
					return false;
			n/=10;
		}
		return true;
	};
	for(ans=n; ans<1000000; ans++)
		if(f(ans))
			break;
	
	cout << ans << '\n';
	
	return 0;
}