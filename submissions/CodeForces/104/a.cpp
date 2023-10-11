#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	n-=10;
	if(n < 1 || n > 11)
		cout << "0\n";
	else{
		int ans[11] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4};
		cout << ans[n-1] << endl;
	}
	
	return 0;
}