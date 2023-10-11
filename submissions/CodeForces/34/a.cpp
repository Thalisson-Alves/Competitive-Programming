#include <bits/stdc++.h>
using namespace std;

#define deb(x) (cerr << #x << " -> " << x << endl)

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n; i++)
		cin >> a[i];
	
	int d = INT_MAX;
	pair<int, int> ans;
	
	for(int i = 0, j = i+1, r = 0; r < n+1; i = (i+1)%n, j = (j+1)%n, r++){
		int dif = abs(a[i]-a[j]);
		if (dif < d){
			d = dif;
			ans.first = i+1;
			ans. second = j+1;
		}
	}
	
	cout << ans.first << " " << ans.second << endl;

    return 0;
}
