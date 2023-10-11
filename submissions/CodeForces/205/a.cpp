#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int mn = 1e9+1, ans = -1;
	for(int i =0 ;i < n; i++){
        int a;
        cin >> a;
        if(mn == a)
            ans = -1;
        if(mn > a){
            ans = i+1;
            mn = a;
        }
	}
	if(ans <= 0)
        cout << "Still Rozdil\n";
    else{
        cout << ans << endl;
    }

	return 0;
}
