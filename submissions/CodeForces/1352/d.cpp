#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
        cin >> a[i];
	}
	int m = 0, s1 = 0, s2 = 0, le= 0;
	for(int l = 0, r = n-1; l <= r; ){
        if(m%2 == 0){
            int cs = 0;
            while(l <= r && cs <= le){
                cs += a[l++];
            }
            s1 += cs;
            le = cs;
        }
        else{
            int cs = 0;
            while(l<=r && cs <= le){
                cs += a[r--];
            }
            s2 += cs;
            le = cs;
        }
        m++;
	}
	cout << m << " " << s1 << " "  << s2 << endl;
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
