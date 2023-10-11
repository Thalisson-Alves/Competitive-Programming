#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t, s, x;
	cin >> t >> s >> x;
	int time = t;
	for(int i = 1; time+1 < x; i++){
		time = t+(i*s);
		if(time == x || time + 1 == x){
			time += (time+1 == x? 1: 0);
			break;
		}
	}
	if(time == x)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int t;
	// cin >> t;
	// while(t--)
		solve();

	return 0;
}
