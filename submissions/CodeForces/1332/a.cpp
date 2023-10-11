#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if((x1 == x2 && x == x1 && (a || b)) || (y1 == y2 && y == y1) && (c || d)){
		cout << "No" << endl;
		return ;
	}
	if(b-a > x2-x || d-c > y2-y || a-b > x-x1 || c-d > y-y1){
		cout << "No" << endl;
		return;
	}
	cout << "Yes\n";
}



int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	
	while(t--)
		solve();

    return 0;
}