#include <bits/stdc++.h>
using namespace std;

const double EPS{1e-9};

template <typename T>
bool equals(const T &a, const T &b)
{
    if (std::is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

template <typename T>
struct Point
{
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator==(const Point &o) const { return equals(x, o.x) && equals(y, o.y); }
    bool operator!=(const Point &o) const { return !(*this == o); }

    T x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vs(n);
    map<int, int> mp;
    for (auto &x : vs) cin >> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[__gcd(vs[i], vs[j])]++;
        }
    }
    int best = 0;
    map<int, int> cn;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        for (auto x : vs)
            if (x % it->first == 0)
                cn[it->first]++;
    }
    cn[1] = 0;
    for (auto it = cn.begin(); it != cn.end(); it++)
        if (it->second > cn[best])
            best = it->first;
    cout << best << '\n';

    return 0;
}
