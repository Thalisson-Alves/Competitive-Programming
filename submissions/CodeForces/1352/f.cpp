#include <bits/stdc++.h>

using namespace std;

int n1, n2, n3;
string ans;

void solve()
{
	cin >> n1 >> n2 >> n3;
	ans = "";
	if(n1)
        for(int i = 0; i <= n1; i++)
            ans += '0';
    if(!ans.empty() && ans[ans.length()-1] == '0' && n2){
        ans += '1';
        n2--;
    }
    if(ans.empty() && n2)
        n2++;
    for(int i = 0; i < n2; i++){
        ans += (i%2? '1' : '0');
    }
    if((ans.empty() && n3))
        ans += '1';
    else if(n3 && ans[ans.length()-1] == '0'){
        if(ans[1] == '1'){
            ans += '1';
            ans = string(ans.begin()+1, ans.end());
        }
        else if(n3 && ans[ans.length()-2] == '1'){
            ans = "1" + string(ans.begin(), ans.end()-1);
        }
    }
    for(int i = 0; i < n3; i++)
        ans += '1';
    cout << ans << endl;
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

