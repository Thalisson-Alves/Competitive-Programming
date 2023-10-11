#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

// S -> T A
// A -> + T A | - T A | e
// T -> F B
// B -> * F B | / F B | e
// F -> ( S ) | digit | e

string S(const string &s, unsigned &i);
string F(const string &s, unsigned &i)
{
    if (s[i] == '(')
    {
        auto x = S(s, ++i);
        i++;
        return x;
    }
    else if (isdigit(s[i]))
        return s.substr(i++, 1);
    return "";
}

string B(const string &s, unsigned &i)
{
    if (i >= s.size() or (s[i] != '*' and s[i] != '/')) return "";
    auto op = s[i++];
    auto f = F(s, i);
    auto b = B(s, i);
    return f + op + b;
}

string T(const string &s, unsigned &i)
{
    auto f = F(s, i);
    auto b = B(s, i);
    return f + b;
}

string A(const string &s, unsigned &i)
{
    if (i >= s.size() or (s[i] != '+' and s[i] != '-')) return "";
    auto op = s[i++];
    auto t = T(s, i);
    auto a = A(s, i);
    return t + op + a;
}

string S(const string &s, unsigned &i)
{
    auto t = T(s, i);
    auto a = A(s, i);
    return t + a;
}

void solve()
{
    string buffer;
    for (string line; getline(cin, line), not line.empty(); buffer += line);
    auto i = 0u;
    cout << S(buffer, i) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t; cin.ignore(2);
    while (t--)
    {
        solve();
        if (t) cout << '\n';
    }

    return 0;
}

