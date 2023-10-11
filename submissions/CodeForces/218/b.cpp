#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a[m];
	for(int i = 0; i < m; i++)
		cin >> a[i];
	
	int ans1 = 0, ans2 = 0;
	vector<int> MN(a, a+m);
	for(int i = 0, mx = 0, mn = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(MN[mn] <= 0)
				mn = j;
			if(a[j] > a[mx])
				mx = j;
			if(MN[j] > 0 && MN[j] < MN[mn])
				mn = j;
		}
		ans1 += a[mx]--;
		ans2 += (MN[mn] <= 0? 0: MN[mn]--);
	}
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}
