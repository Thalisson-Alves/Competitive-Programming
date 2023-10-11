#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	long long l = 1, r = 2*k;
	while(l<=r){
		long long m = l+(r-l)/2;
		if(m-m/n>=k)
			r = m-1;
		else
			l = m+1;
	}
	cout << l << endl;
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
