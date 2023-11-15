#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr <<  #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int k;
	cin >> k;
	vector<ll> a;
	for(int i=1; i<10; i++)
		a.push_back(i);
	for(int i=0; a.size() < k; i++){
		int d = a[i] % 10ll;
		if(d > 0)
			a.push_back(10ll*a[i]+d-1);
		a.push_back(10ll*a[i]+d);
		if(d < 9)
			a.push_back(10ll*a[i]+d+1);
	}
	cout << a[k-1] << endl;
	
	return 0;
}