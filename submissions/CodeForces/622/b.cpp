#include <bits/stdc++.h>

using namespace std;

void solve(string h, int t)
{
    int hour = stoi(h.substr(0, h.find(":")));
    int minutes = stoi(h.substr(h.find(":")+1));
    int passed_hour = t / 60;
    int minutes_passed = minutes;
    hour = (hour + passed_hour) % 24;
    minutes = (t + minutes) % 60;
    if (minutes_passed > minutes){
        hour++;
        hour%=24;
    }
    printf("%02d:%02d\n", hour, minutes);
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    int t;
    cin >> n >> t;
    solve(n, t);
    /*
    auto ans = solve(n, t);
    cout << ans << endl;
    */
    return 0;
}
