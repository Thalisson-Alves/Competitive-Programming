#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n;
	cin >> a >> b >> n;
	int t=0, g;
	for(int i=0; i<10; i++)
		(a*10+i)%b==0? t+=1, g=i: t+=0;
	if(!t)
		cout << "-1\n";
	else{
		cout << a << g;
		for(int i=1; i<n; i++)
			cout << 0;
		cout << endl;
	}
	
	return 0;
}