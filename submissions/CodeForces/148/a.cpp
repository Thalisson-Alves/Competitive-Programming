#include <bits/stdc++.h>

using namespace std;

int solve(int n, int p[])
{
    set<int> ans;
    for(int i = 0; i < 4; i++){
        if(p[i] == 1)
            return n;
        for(int j = p[i]; j <= n; j+=p[i])
            ans.insert(j);
    }
    return ans.size();
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p[4];
    for(int i = 0; i < 4; i++){
        cin >> p[i];
    }
    int n;
    cin >> n;

    auto ans = solve(n, p);
    cout << ans << endl;

    return 0;
}
