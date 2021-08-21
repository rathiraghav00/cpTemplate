#include<bits/stdc++.h>
using namespace std;

#define vvi             vector<vector<int>>
#define ld              long double
#define mod             1000000007
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define pss             pair<string,string>
#define vpii            vector<pair<int,int>>
#define all(x)          (x).begin(),(x).end()
#define sz(a)           (int)((a).size())
#define vi              vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


const int mxN = 2e5 + 100;
int a[mxN];
int b[mxN];
int n, m, k, q, x, y;
int ans;
string s;
int dp[mxN];
set<int> v[mxN];

bool isLeaf(int x) {
    if(sz(v[x]) == 1) {
        if(*v[x].begin() < x) {
            return 1;
        }
    }
    return 0;
}

void test_case()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++) 
    {
        v[i].clear();
    }


    for(int i = 1; i <= m; i++) 
    {
        int x, y;
       cin >> x >> y;
       v[x].insert(y);
       v[y].insert(x);
    }

    

    set<int> leaf;

    for(int i = 1; i <= n; i++) 
    {
        if(isLeaf(i)) {
            leaf.insert(i);
        }
    }

   

    cin >> q;

    for(int i = 1; i <= q; i++) 
    {
        int stat;
        cin >> stat;

        if(stat == 1) {

            int x, y;
            cin >> x >> y;

            if(isLeaf(x)) {
                leaf.erase(x);
            }

            if(isLeaf(y)) {
                leaf.erase(y);
            }

           
            v[x].insert(y);
            v[y].insert(x);

            if(isLeaf(x)) {
                leaf.insert(x);
            }

            if(isLeaf(y)) {
                leaf.insert(y);
            }

        } else if(stat == 2) {

            int x, y;
            cin >> x >> y;

            if(isLeaf(x)) {
                leaf.erase(x);
            }

            if(isLeaf(y)) {
                leaf.erase(y);
            }

           
            v[x].erase(y);
            v[y].erase(x);

            if(isLeaf(x)) {
                leaf.insert(x);
            }

            if(isLeaf(y)) {
                leaf.insert(y);
            }

        } else if(stat == 3) {

            cout << sz(leaf) << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        test_case();
    }

    return 0;
}