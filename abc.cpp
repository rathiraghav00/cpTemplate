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
// #define sz(a)           (int)((a).size())
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




// class tree_cen {

// public:

//     int siz;
//     int cur_siz;
//     vvi tree;
//     vi isCentroid;

//     tree_cen(int n)
//     {
//         siz = n + 1;
//         cur_siz = 0;
//         tree = vvi (n + 1);
//         for(int i = 1; i <= n; i++)
//         {
//             tree[i].clear();
//         }
//         isCentroid = vi(n + 1, 0);
//     }

//     void DFS_UTIL(int src, vi &vis, vi &subtree)
//     {

//         vis[src] = 1;
//         subtree[src] = 1;
//         cur_siz += 1;

//         for(int x : tree[src])
//         {
//             if(!vis[x] and !isCentroid[x])
//             {
//                 DFS_UTIL(x, vis, subtree);
//                 subtree[src] += subtree[x];
//             }
//         }
//     }

//     int findCentroid(int src, vi &vis, vi &subtree)
//     {
//         bool centroid = true;
//         vis[src] = 1;
//         int heavy = 0;

//         for(int x : tree[src])
//         {
//             if(!vis[x] and !isCentroid[x])
//             {
//                 if(subtree[x] > cur_siz / 2)
//                 {
//                     centroid = 0;
//                 }

//                 if(heavy == 0 or subtree[x] > subtree[heavy])
//                 {
//                     heavy = x;
//                 }

//             }
//         }

//         if(centroid && cur_siz - subtree[src] <= cur_siz / 2)
//         {
//             return src;
//         }
//         else
//         {
//             return findCentroid(heavy, vis, subtree);
//         }
//     }

//     int findCentroidUtil(int src = 1)
//     {
//         vi vis(n + 1, 0);
//         vi subtree(n + 1, 0);
//         cur_siz = 0;
//         DFS_UTIL(src, vis, subtree);
//         vis = vi(n + 1, 0);
//         int centroid = findCentroid(src, vis, subtree);
//         isCentroid[centroid] = 1;
//         return centroid;
//     }

//     void addEdge(int a, int b)
//     {
//         tree[a].pb(b);
//         tree[b].pb(a);
//     }

//     void printAns(int src, int k)
//     {
//         vi d(n + 1, 1e10);

//         queue<int> q;

//         q.push(src);

//         d[src] = 1;

//         vi ans;

//         while(size_arr(ans) < k)
//         {
//             int x = q.front();
//             q.pop();

//             ans.pb(x);

//             for(int ch : tree[x])
//             {
//                 if(d[ch] == 1e10)
//                 {
//                     d[ch] = d[x] + 1;
//                     q.push(ch);
//                 }
//             }
//         }

//         // for(int x : ans)
//         // {
//         //     cout << x << ' ';
//         // }

//         // cout << '\n';

//         src = ans.back();

//         vi opt(n + 1, 0);

//         for(int i : ans)
//         {
//             opt[i] = 1;
//         }

//         while(!q.empty())
//         {
//             q.pop();
//         }

//         d = vi(n + 1, -1);

//         d[src] = 0;
//         q.push(src);

//         while(!q.empty())
//         {
//             int x  = q.front();
//             q.pop();

//             for(int ch : tree[x])
//             {
//                 if(d[ch] == -1)
//                 {
//                     d[ch] = d[x] + 1;
//                     q.push(ch);
//                 }
//             }
//         }

//         int dis = -1e10;

//         for(int i = 1; i <= n; i++)
//         {
//             if(opt[i])
//             {
//                 assert(d[i] != -1);
//                 dis = max(dis, d[i]);
//             }
//         }

//         cout << dis << '\n';

//     }
// };

// const int mxN = 2e6 + 100;
// int a[mxN];
// int n, m, k, q;
// int ans;
// string s;
int n, k;

vvi tree;
set<int> vis;

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
            }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}


int printAns(int src, int k)
{

    if(vis.count(src))
    {
        return 1e10;
    }

    vis.insert(src);

    vi d(n + 1, -1);

    queue<int> q;

    q.push(src);

    d[src] = 0;

    vi ans;

    while ((int)(ans.size()) < k)
    {
        int x = q.front();
        q.pop();

        ans.pb(x);

        for (int ch : tree[x])
        {
            if (d[ch] == -1)
            {
                d[ch] = d[x] + 1;
                q.push(ch);
            }
        }
    }

    // cout << "op : ";
    // for(int i : ans)
    // {
    //     cout << i + 1 << " ";
    // }

    // cout << '\n';

    // 2 - BFS -> diameter

    src = ans.back();

    vi opt(n + 1, 0);

    for (int i : ans)
    {
        opt[i] = 1;
    }

    while (!q.empty())
    {
        q.pop();
    }

    d = vi(n + 1, -1);

    d[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int x  = q.front();
        q.pop();

        for (int ch : tree[x])
        {
            if (d[ch] == -1)
            {
                d[ch] = d[x] + 1;
                q.push(ch);
            }
        }
    }

    int dis = -1e10;

    for (int i = 0; i <= n; i++)
    {
        if (opt[i])
        {
            assert(d[i] != -1);
            dis = max(dis, d[i]);
        }
    }

    src = -1;

    for (int i = 0; i <= n; i++)
    {
        if (opt[i])
        {
            if (dis == d[i])
            {
                src = i;
            }
        }
    }

    while (!q.empty())
    {
        q.pop();
    }

    d = vi(n + 1, -1);

    d[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int x  = q.front();
        q.pop();

        for (int ch : tree[x])
        {
            if (d[ch] == -1)
            {
                d[ch] = d[x] + 1;
                q.push(ch);
            }
        }
    }

    dis = -1e10;

    for (int i = 0; i <= n; i++)
    {
        if (opt[i])
        {
            assert(d[i] != -1);
            dis = max(dis, d[i]);
        }
    }

    return dis;

}

void test_case()
{
    vis.clear();

    srand(time(0));

    cin >> n >> k;

    tree.clear();

    tree = vvi (n);

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
        //t.addEdge(a, b);
    }

    vi cen = Centroid(tree);

    assert((int)(cen.size()) <= 2);

    int ans = 1e18;

    int cnt = 50;

    while (cnt--)
    {
        ans = min(ans, printAns(rand() % n, k));
    }

    for (int x : cen)
    {
        ans = min(ans, printAns(x, k));

        for(int z : tree[x])
        {
            ans = min(ans, printAns(z, k));
        }
    }

    



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

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        test_case();
    }

    return 0;
}