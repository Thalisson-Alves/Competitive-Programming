#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	function<void(int, int, int, int)> print = [](int a, int b, int c, int d) -> void {
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	};
	if(x1 == x2)
		print(x1+abs(y1-y2), y1, x1+abs(y1-y2), y2);
	else if(y1 == y2)
		print(x1, y1+abs(x1-x2), x2, y1+abs(x1-x2));
	else if(abs(x1-x2) != abs(y1-y2))
		cout << "-1\n";
	else
		x1 > x2 == y1 > y2? print(min(x1, x2), max(y1, y2), max(x1, x2), min(y1, y2)):
							print(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));

	return 0;
}