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


class DSU
{
public :
    vector < int >  parent, sz;
    DSU(int n)
    {
        parent = vector < int > (n + 1);
        sz = vector < int > (n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int i)
    {
        if (i == parent[i])
            return i;
        else return parent[i] = find_set(parent[i]);
    }

    bool same_set(int i, int j)
    {
        i = find_set(i);
        j = find_set(j);
        return i == j;
    }

    void union_sets(int i, int j)
    {
        i = find_set(i);
        j = find_set(j);

        if (i  == j)
            return;

        if (sz[i] > sz[j])
            swap(i, j);

        parent[i] = j;
        sz[j] += sz[i];
    }
};

const int mxN = 1e6 + 100;
int a[mxN];
int n, m, k, q;
int ans;
string s;
int sp[mxN];
int vis[mxN];



class DSU
{
public :
    vector < int >  parent, sz;
    DSU(int n)
    {
        parent = vector < int > (n + 1);
        sz = vector < int > (n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int i)
    {
        if (i == parent[i])
            return i;
        else return parent[i] = find_set(parent[i]);
    }

    void union_sets(int i, int j)
    {
        i = find_set(i);
        j = find_set(j);

        if (i  == j)
            return;

        if (sz[i] > sz[j])
            swap(i, j);

        parent[i] = j;
        sz[j] += sz[i];
    }
};

void test_case()
{
    cin >> n;

    int cntOne = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (a[i] == 1)
        {
            cntOne++;
        }
    }

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    if (cntOne == n)
    {
        cout << 2 * n << '\n';
        return;
    }

    set<int> s;

    for (int i = 1; i <= n; i++)
    {
      //    if(a[i] != 1)
        {
            s.insert(a[i]);
        }
    }

    n = sz(s);

    int ptr = 1;

    for (int xx : s)
    {
        a[ptr] = xx;

        ptr++;
    }

    int mx = 0;

    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, a[i]);
    }

    for (int i = 1; i <= mx; i++)
    {
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        vis[a[i]] = 1;
    }

    DSU dsu(mx + 10);

    for (int i = 2; i <= mx; i++)
    {
        vi nodes;

        for (int j = i; j <= mx; j += i)
        {
            if(vis[j])
            {
                nodes.pb(j);
            }
        }

        for(int j = 1; j < sz(nodes); j++)
        {
            dsu.union_sets(nodes[j], nodes[j - 1]);
        }
    }

    s.clear();

    for (int i = 1; i <= mx; i++)
    {
        if (vis[i])
        {
            s.insert(dsu.find_set(i));
        }

    }

   
    int mn = 1e10;

    for (int i = 2; i <= mx; i++)
    {
        if (vis[i] == 1)
        {
            mn = min(mn, sp[i]);
        }
    }

    assert(mn != 1e10);
    
    int cc = sz(s) + cntOne - 1;
    if(cntOne == 0)
        ++ cc; 


    int ans = min(2 * cc, mn * (cc - 1));

/*    ans = min((ans - 1) * mn, ans * 2); 
    ans = max(0ll, ans - 1) * mn;

    ans += min(mn + 2 * (cntOne), mn * cntOne);*/

    cout << ans << '\n';
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
    cin >> t;

    for (int i = 1; i <= mxN - 5; i++)
    {
        sp[i] = i;
    }

    for (int i = 2; i <= mxN - 5; i++)
    {
        if (sp[i] == i)
        {
            for (int j = i * i ; j <= mxN - 5; j += i)
            {
                if (sp[j] == j)
                {
                    sp[j] = i;
                }
            }
        }

    }


    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        test_case();
    }

    return 0;
}