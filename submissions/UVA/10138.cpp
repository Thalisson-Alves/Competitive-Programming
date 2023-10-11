#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

struct Record
{
    string plate;
    int month, date, hour, minute, dist;
    bool entering;

    bool operator<(const Record &r)
    {
        tuple<int, int, int, int, int, bool> me{month, date, hour, minute, dist, not entering},
            other{r.month, r.date, r.hour, r.minute, r.dist, not r.entering};
        return me < other;
    }
};

bool read_record(Record &r)
{
    string line;
    getline(cin, line);
    if (line.empty())
        return false;

    stringstream ss(line);
    char c;
    string s;
    ss >> r.plate >> r.month >> c >> r.date >> c >> r.hour >> c >> r.minute >> s >> r.dist;
    r.entering = (s == "enter");
    return true;
}

void solve()
{
    vector<int> v(24);
    for (auto &x : v) cin >> x;
    cin.ignore();

    vector<Record> records;
    for (Record record; read_record(record);) records.push_back(record);
    sort(all(records));
    /*
    cerr << dfv(v);
    for (auto &r : records)
        if (r.plate == "AY")
            cerr << df(r.plate) << df(r.month) << df(r.date) << df(r.hour) << df(r.minute) << boolalpha << df(r.entering) << dfn(r.dist);
            */

    unordered_map<string, pair<int, int>> mp;
    map<string, int> ans;
    for (auto &r : records)
    {
        if (r.entering)
            mp[r.plate] = {r.dist, v[r.hour]};
        else
        {
            if (not mp.count(r.plate))
                continue;
            ans[r.plate] += 100 + abs(r.dist - mp[r.plate].first) * mp[r.plate].second;
            mp.erase(r.plate);
        }
    }
    for (auto &x : ans)
        cout << x.first << " $" << x.second / 100 + 2 << '.' << setw(2) << setfill('0') << x.second % 100 << '\n';
    /*
    cerr << dfv(v);
    for (auto &r : records)
        cerr << df(r.plate) << df(r.month) << df(r.date) << df(r.hour) << df(r.minute) << boolalpha << df(r.entering) << dfn(r.dist);
        */
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; i++)
    {
        solve();
        if (i < t)
            cout << "\n";
    }

    return 0;
}

