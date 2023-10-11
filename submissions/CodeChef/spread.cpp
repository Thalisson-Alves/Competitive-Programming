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

template<typename T>
double D(const pair<T, T>& P, const pair<T, T>& Q, const pair<T, T>& R)
{
    return (P.first * Q.second + P.second * R.first + Q.first * R.second) -
           (R.first * Q.second + R.second * P.first + Q.first * P.second);
}

template<typename T>
struct BITree
{
    int N;
    vector<T> v;

    BITree(int n) : N(n), v(n+1, 0) {}

    void update(int i, const T& x)
    {
        if (i == 0) return;
        for (; i <= N; i += i & -i)
            v[i] += x;
    }

    T range_sum(int i, int j)
    {
        return range_sum(j) - range_sum(i - 1);
    }

    T range_sum(int i)
    {
        T sum = 0;
        for (; i > 0; i -= i & -i)
            sum += v[i];
        return sum;
    }
};

/*
inline void input(int *a)
{
    char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
*/

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    //input(&n); input(&m); input(&c);
    BITree<ll> st(n);

    for (auto i = 0; i < m; i++)
    {
        char ch;
        cin >> ch;
        /*
        char ch;
        ch=getchar_unlocked();
		while(!(ch=='Q'||ch=='S'))
			ch=getchar();
        */

        if (ch == 'S')
        {
            int u, v, k;
            cin >> u >> v >> k;
            //input(&u); input(&v); input(&k);
            st.update(u, k);
            st.update(v+1, -k);
        }
        else
        {
            int p;
            cin >> p;
            //input(&p);
            cout << c + st.range_sum(p) << '\n';
            //printf("%lld\n", c + st.range_sum(p));
        }
    }
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

