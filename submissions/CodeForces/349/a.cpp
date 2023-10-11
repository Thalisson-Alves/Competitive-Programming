#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	string ans = "YES\n";
	int a=0, b=0, c=0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(ans == "YES\n")
			if(x == 25)
				a++;
			else if(x == 50){
				b++;
				if(a)
					a--;
				else
					ans = "NO\n";
			}else{
				c++;
				if(a && b)
					a--, b--;
				else if(a >= 3)
					a-=3;
				else
					ans = "NO\n";
			}
	}
	
	cout << ans;
	
	return 0;
}