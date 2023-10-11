#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int x;
	cin >> x;
    vector<int> ans;
    int p = 1;
	while(x){
        if(x%10)
            ans.push_back((x%10)* p);
        p*=10;
        x/=10;
    }
	cout << ans.size() << endl;
    for(int v: ans)
		cout << v << " ";
	cout << endl;
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
