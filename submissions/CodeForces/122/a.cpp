#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string ans = "NO\n";
	function<bool(int)> lucky = [](int x) -> bool {
		while(x){
			if(x%10 != 4 && x%10 != 7)
				return false;
			x /= 10;
		}
		return true;
	};
	for(int div=4; div<=n; div+=(div%10==4? 3: 7))
		if(lucky(div) && !(n%div))
			ans = "YES\n";
	
	cout << ans;

	return 0;
}