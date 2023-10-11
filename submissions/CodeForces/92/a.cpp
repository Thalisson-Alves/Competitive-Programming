#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	function<int(int)> sum = [&sum](int a){return a? a+sum(a-1): 0;};
	int chips = sum(n);
	int rem = m%chips;
	for(int i=1; i<=rem; i++)
		rem-=i;
	cout << rem << endl;

	return 0;
}