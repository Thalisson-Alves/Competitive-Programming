#include <bits/stdc++.h>

using namespace std;

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int year;
    cin >> year;
    int ans = year+1;

    auto distinct = [](int y)
    {
        unordered_map<int, int> first_incidence;
        while(y){
            first_incidence[y%10]++;
            if(first_incidence[y%10] > 1)
                return false;
            y /= 10;
        }
        return true;
    };

    while(!distinct(ans)){
        ans++;
    }
    cout << ans << endl;

    return 0;
}
