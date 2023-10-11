#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll next_lucky(string &n){
	bool g = false, can = (n[0] > '7'? false: true);
	int i;
	if(can)
		for(i=0; i<(int)n.size(); i++)
			if(g) n[i] = '4';
			else if(n[i] == '4' || n[i] == '7') continue;
			else{
				if(n[i] < '4')
					n[i] = '4', g=true;
				else if(n[i] < '7')
					n[i] = '7', g=true;
				else{
					for(--i; i>=0; i--)
						if(n[i] < '7'){
							n[i] = '7', g=true;
							break;
						}
					if(i < 0){
						can = false;
						break;
					}
				}
			}
	if(!can){
		for(char &c: n)
			c = '4';
		n += '4';
	}
	#ifdef debug
	cout << n << endl;
	#endif
	return stoll(n);
}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int l, r;
	cin >> l >> r;
	ll ans = 0, n = l;
	while(n <= r){
		string s(to_string(n));
		#ifdef debug
		cout << "DEBUGGIN -> " + s + " = ";
		#endif
		ll nxt = next_lucky(s);
		ans += ((nxt < r? nxt: r) - n+1)*nxt;
		n = nxt+1;
	}
	cout << ans << endl;
	
	return 0;
}