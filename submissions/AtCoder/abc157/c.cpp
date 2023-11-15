#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string ans(n, '0');
	ans[0] = (n == 1? '0': '1');
	bool a[n];
	bool can = true;
	memset(a, false, sizeof a);
	for(int i=0; i<m; i++){
		int pos, num;
		cin >> pos >> num;
		if(!a[pos-1] || num+'0' == ans[pos-1])
			ans[pos-1] = num+'0', a[pos-1] = true;
		else
			can = false;
	}
	
	cout << ((ans[0] == '0' && n>1) || !can? "-1": ans) << endl;
	
	return 0;
}