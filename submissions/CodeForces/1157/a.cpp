#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define debug(x) cerr << #x << " = " << x << endl

long f(long n) {
	n++;
	while (n%10 == 0)
		n/=10;
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	long n;
	cin >> n;
	set<long> st;
	int prev = -1;
	while (prev < (int) st.size()) {
		prev = st.size();
		st.insert(n);
		n = f(n);
	}
	
	cout << st.size() << '\n';
	
	return 0;
}