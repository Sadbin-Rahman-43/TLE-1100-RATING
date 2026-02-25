#include <bits/stdc++.h>
using namespace std;

// ============================= TYPEDEFS ===============================
// Common type aliases for competitive programming
using ll = long long;           // 64-bit integer
using ull = unsigned long long; // Unsigned 64-bit
using ld = long double;         // High precision float
using pii = pair<int, int>;     // Pair of integers
using pll = pair<ll, ll>;       // Pair of long longs
using vi = vector<int>;         // Vector of ints
using vl = vector<ll>;          // Vector of long longs
using vvi = vector<vi>;         // 2D vector of ints
using vvl = vector<vl>;         // 2D vector of long longs
using vpii = vector<pii>;       // Vector of pairs
using str = string;             // Shorter string alias
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>; // Min-heap
template <class T>
using pqm = priority_queue<T>; // Max-heap (default)

// ============================= CONSTANTS ================================
#define endl "\n"                       // Faster than std::endl (no flush)
static constexpr ll LINF = (ll)4e18;    // Large infinity for ll
static constexpr int INFi = 2e9;        // Large infinity for int
static constexpr ll MOD = 1000000007LL; // Common prime modulus
static constexpr ll MOD2 = 998244353LL; // Another common prime modulus
static constexpr int MAXN = 200010;     // Common array size limit
static constexpr int LOG = 20;          // log2(1e6) ~ 20, for sparse tables / binary lifting
static constexpr double EPS = 1e-10;    // Floating point comparison tolerance

// =============================== MACROS =================================
#define rep(i, a, n) for (int i = (a); i < (n); i++)      // Loop from a to n-1
#define repan(i, a, n) for (ll i = (a); i <= (n); i++)    // Loop from a to n (inclusive)
#define per(i, a, n) for (int i = (n) - 1; i >= (a); i--) // Reverse loop
#define pb push_back
#define eb emplace_back // Faster than push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define each(x, v) for (auto &x : v)       // Range-based for loop
#define mset(a, v) memset(a, v, sizeof(a)) // Fast array initialization
#define sb(v) sort(all(v))                 // Sort ascending
#define bs(v) sort(rall(v))                // Sort descending
#define rs(v) reverse(all(v))              // Reverse vector
// Remove duplicates
#define uniq(v)   \
    sort(all(v)); \
    v.erase(unique(all(v)), v.end())
// Ultra-fast 2D vector creation (replaces make2d function)
#define vvii(rows, cols, val) vvi(rows, vi(cols, val))
#define vvll(rows, cols, val) vvl(rows, vl(cols, val))
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr); // Fast I/O

// =========================== FAST INPUT/OUTPUT ===========================
// Fast single value read
template <class T>
inline void read(T &x) { cin >> x; }

// Fast multiple value read
template <class T, class... Args>
inline void read(T &x, Args &...args)
{
    cin >> x;
    read(args...);
}

// Read entire line after skipping whitespace
inline str readline()
{
    str s;
    getline(cin >> ws, s);
    return s;
}

// Read vector of size n (or full if n=-1)
template <class T>
inline void readvec(vector<T> &v, int n = -1)
{
    if (n == -1)
        n = sz(v);
    rep(i, 0, n) cin >> v[i];
}

// Read multiple values into a tuple
template <class... Args>
inline tuple<Args...> read()
{
    tuple<Args...> t;
    apply([](auto &&...args)
          { ((cin >> args), ...); }, t);
    return t;
}

// Print with optional newline
template <class T>
inline void print(const T &x, bool nl = true)
{
    cout << x;
    if (nl)
        cout << endl;
}

// Print vector with custom separator
template <class T>
inline void printvec(const vector<T> &v, char sep = ' ', bool nl = true)
{
    for (int i = 0; i < sz(v); i++)
    {
        if (i)
            cout << sep;
        cout << v[i];
    }
    if (nl)
        cout << endl;
}

// Print 2D vector
template <class T>
void print2d(const vector<vector<T>> &g)
{
    rep(i, 0, sz(g)) printvec(g[i]);
}
// Print unordered_map
template <class K, class V>
void printmap(const unordered_map<K, V> &mp, char sep = '\n', str kv_sep = ": ", str prefix = "")
{
    cout << prefix;
    int cnt = 0;
    each(p, mp)
    {
        if (cnt++)
            cout << sep;
        cout << p.ff << kv_sep << p.ss;
    }
    if (sz(mp))
        cout << endl;
}

// Print ordered map
template <class K, class V>
void printmap(const map<K, V> &mp, char sep = '\n', str kv_sep = ": ", str prefix = "")
{
    cout << prefix;
    int cnt = 0;
    each(p, mp)
    {
        if (cnt++)
            cout << sep;
        cout << p.ff << kv_sep << p.ss;
    }
    if (sz(mp))
        cout << endl;
}

// Common contest output macros
inline void YES(bool caps = true) { cout << (caps ? "YES\n" : "Yes\n"); }
inline void NO(bool caps = true) { cout << (caps ? "NO\n" : "No\n"); }
inline void setprec(int x = 15) { cout << fixed << setprecision(x); }

// =========================== HELPER FUNCTIONS ===========================

// Count frequencies in vector
template <class T>
map<T, int> count_freq(const vector<T> &arr)
{
    map<T, int> freq;
    each(x, arr) freq[x]++;
    return freq;
}

// Count frequencies with unordered_map (faster)
template <class T>
unordered_map<T, int> count_freq_unordered(const vector<T> &arr)
{
    unordered_map<T, int> freq;
    each(x, arr) freq[x]++;
    return freq;
}
void solve()
{

    int n;
    cin >> n;
    vector<pair<ll,int>> v(n);
    rep(i, 0, n)
    {
        cin >> v[i].ff;
        v[i].ss = i;
    }
    sb(v);
    vl ans(n);
    ll sum = 0;
    stack<ll> stk;
    rep(i, 0, n)
    {
        if (sum < v[i].ff)
        {
            while (stk.size())
            {
                ans[stk.top()] = i - 1;
                stk.pop();
            }
        }
        sum += v[i].ff;
        stk.push(v[i].ss);
    }
    while (stk.size())
    {
        ans[stk.top()] = n - 1;
        stk.pop();
    }
    each(x, ans) cout << x << " ";
    cout << endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}