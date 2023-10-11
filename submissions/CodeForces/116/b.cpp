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
	vector<vector<char>> a(n, vector<char>(m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> a[i][j];
	int ans = 0;
	vector<pair<int, int>> direction = {{0,-1}, {0,1}, {-1,0}, {1,0}};
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] == 'W'){
				for(pair<int, int> dir: direction){
					int row = i+dir.first;
					int col = j+dir.second;
					if(row>=0 && row<n && col>=0 && col<m && a[row][col] == 'P'){
						ans++;
						a[row][col] = '*';
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}