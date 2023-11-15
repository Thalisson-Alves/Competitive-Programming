#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[3][3];
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			cin >> a[i][j];
	bool check[3][3];
	memset(check, false, sizeof check);
	int n;
	cin >> n;
	string ans = "No\n";
	while(n--){
		int x;
		cin >> x;
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				if(a[i][j] == x)
					check[i][j] = true;
	}
	for(int i=0; i<3; i++)
		if(check[i][0] && check[i][0] == check[i][1] && check[i][1] == check[i][2])
			ans = "Yes\n";
		else if(check[0][i] && check[0][i] == check[1][i] && check[1][i] == check[2][i])
			ans = "Yes\n";
	if(check[0][0] && check[0][0] == check[1][1] && check[1][1] == check[2][2])
		ans = "Yes\n";
	if(check[0][2] && check[0][2] == check[1][1] && check[1][1] == check[2][0])
		ans = "Yes\n";
	cout << ans;
	
	return 0;
}