#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dp_have[26]={0};
    int dp_want[26]={0};

    string have;
    string want;
    cin >> have;cin.ignore();
    cin >> want;cin.ignore();

    for(int i = 0; i < want.size(); i++){
        dp_want[want[i]-97]++;
    }
    for(int i = 0; i < have.size(); i++){
        dp_have[have[i]-97]++;
    }
    int ans=0;
    for(int i = 0; i < 26; i++){
        if(dp_have[i] >= dp_want[i]){
            ans += dp_want[i];
        }
        else if(dp_have[i] == 0){
            ans = -1;
            break;
        }
        else{
            ans += dp_have[i];
        }
    }
    cout << ans << endl;

    return 0;
}
