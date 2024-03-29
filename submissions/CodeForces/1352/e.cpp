#include <bits/stdc++.h>

using namespace std;

const int mxN = 8e3;
int n, a[mxN], c[mxN+1];

void solve()
{
	cin >> n;
	for(int i = 0; i < n; i++){
        cin >> a[i], c[i+1] = 0;
	}
	for(int l = 0; l < n; l++){
        int s = a[l];
        for(int r = l+1; r < n; ++r){
            s += a[r];
            if(s > 0 && s <= n){
                ++c[s];
            }
        }
	}
	int ans = 0;
	for(int i= 0; i < n; i++){
        ans += c[a[i]] > 0;
	}
	cout << ans << endl;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

