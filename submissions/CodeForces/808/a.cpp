#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define debug(x) cerr << #x << " = " << x << endl

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	long long n;
	cin >> n;
	long long len = 0, last = 0;
	int tmp = n;
	while(tmp)
	{
		last = tmp % 10;
		len++;
		tmp /= 10;
	}
	cout << (last + 1) * (long long)(pow(10, len - 1)) - n << '\n';
	
	return 0;
}