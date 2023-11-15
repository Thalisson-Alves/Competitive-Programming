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

void solve()
{
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;
    v.push_back(inf());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto i = 0; i < k; i++)
        pq.emplace(v[i], i);
    set<pii> st, cons;
    ll sum = 0;
    for (auto i = 0; i < d; i++)
    {
        sum += pq.top().first;
        st.insert(pq.top());
        pq.pop();
    }
    cout << sum;
    for (auto i = 0; i < n - k; i++)
    {
        cons.emplace(v[i], i);
        pq.emplace(v[i+k], i+k);
        while (cons.count(pq.top())) pq.pop();
        auto prev = make_pair(v[i], i);
        if (st.count(prev))
        {
            sum -= v[i];
            sum += pq.top().first;
            st.erase(prev);
            st.insert(pq.top());
            pq.pop();
        }

        if (pq.top().first < st.rbegin()->first)
        {
            sum -= st.rbegin()->first;
            sum += pq.top().first;
            auto l = *st.rbegin();
            pq.push(l);
            st.erase(l);
            st.insert(pq.top());
            pq.pop();
        }
        cout << ' ' << sum;
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

