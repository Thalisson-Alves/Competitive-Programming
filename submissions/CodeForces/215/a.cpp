#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	pair<int, int> ans;
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i){
		int b;
		cin >> b;
		for(int j = 0; j < n; j++){
			if(!(b % a[j])){
				if(b / a[j] > ans.first){
					ans.first = b/a[j];
					ans.second = 1;
				}
				else if (b/a[j] == ans.first)
					ans.second++;
			}
		}
	}
	cout << ans.second << endl;

    return 0;
}