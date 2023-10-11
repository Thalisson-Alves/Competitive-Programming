#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s, m;
	cin >> n;cin.ignore();
	cin >> s;cin.ignore();
	cin >> m;
	sort(s.begin(), s.end());
	sort(m.begin(), m.end());
	int ans1 = 0, ans2 = 0;
	for(int i = n-1, k = n-1, j = n-1; i >= 0; i--){
        if(s[i] <= m[k]){
            k--;
        }else{
            ans1 += 1;
        }
        if(s[i] < m[j])
            ans2 += 1, j--;
	}
	cout << ans1 << '\n' << ans2 << '\n';

	return 0;
}
