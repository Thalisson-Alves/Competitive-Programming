#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n)
{
    if(n%2)
        return vector<int>(1,-1);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = (i+1)%2? i+2: i;
    }
    return ans;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    auto ans = solve(n);
    for(auto x: ans)
        cout << x << (x==ans[ans.size()]? '\n': ' ');

    return 0;
}
