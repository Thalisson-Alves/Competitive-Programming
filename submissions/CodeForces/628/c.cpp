#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int n, k;
	scanf("%d %d", &n, &k);
	char s[(int)3e5+2];
	scanf("%s", s);
	ll mxK = 0;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
        v[i] = max(s[i]-'a', 'z'-s[i]);
        mxK += v[i];
	}
    if(mxK < k)
        printf("-1\n");
    else{
        char ans[n+1];
        for(int i=0; i<n; i++){
            if(k - v[i] >= 0){
                ans[i] = (s[i] + v[i] <= 'z'? s[i]+v[i]: s[i]-v[i]);
                k -= v[i];
            }
            else{
                ans[i] = (s[i] + k <= 'z'? s[i]+k: s[i]-k);
                k = 0;
            }
        }
        ans[n] = '\0';
        printf("%s\n", ans);
    }

	return 0;
}
