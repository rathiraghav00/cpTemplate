#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int                     long long int
#define ld                      long double
#define pb                      push_back
#define rep(i,a,b,c)            for(int i=(a);i<=(b);i+=(c))
#define repb(i,a,b,c)           for(int i=(a);i>=(b);i-=(c))
#define MOD                     1000000007
#define inf                     3e18
#define vpii                    vector<pair<int,int>>
#define si 	           		   	set<int>
#define usi                     unordered_set<int>
#define vi 						vector<int>
#define vld                     vector<ld>
#define vvi                     vector<vector<int>>
#define vvld                    vector<vector<ld>>
#define pii                     pair<int,int>
#define vvpii                   vector<vector<pair<int,int>>>
#define pqi                     priority_queue<int>
#define mii                     map<int,int>
#define mic                     map<int,char>
#define um                      unordered_map
#define umii                    um<int,int>
#define umic                    um<int,char>
#define umci                    um<char,int>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define tests                   int Testcases;cin>>Testcases;while(Testcases--)
#define input(a,n)              for(int i=0;i<n;++i) cin>>a[i];
#define fastIO                  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << " "<< name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
        //  shuffle(arr.begin(), arr.end(), rng); 
        //  or rng() to generate random number

#define pbds             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> //pbds or ordered_set
//template <typename T>
//using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo(k)                  find_by_order(k)    //Valid for ordered set(K-th element in a set (counting from zero)                  
#define ook(k)                  order_of_key(k)     //Valid for ordered set(Number of items strictly smaller than k)                 

int bin_exp(int b,int e)
{
	if(e==0)	
		return 1;
	int a=bin_exp(b,e/2);
	if(e&1)	
		return a*a*b;
	else 
		return a*a;
}

int powm(int x,int y,int m=MOD) 
{
	x=x%m;
	int res=1;
	while(y)
	{
		if(y&1)
			res=res*x;
		res%=m;
		y=y>>1;
		x=x*x;
		x%=m;
	}
	return res;
}

int modInverse(int a,int m=MOD)
{
	return powm(a,m-2,m);
}

int extended_GCD(int a ,int b ,int &x ,int &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1 , y1;
    int gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}

int mulInv(int a , int mod=MOD)
{
    int x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}

vector<int> prime;
void seive(int n)
{
    prime.resize(n+1,1);
    prime[0] = 0, prime[1] = 0;
    for (int i = 2; i*i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
}

int nCr(int n,int r)
{
 	if(n<r)
    	return 0;
  	int ans=1;
  	if(n-r<r)
    	r=n-r;
  	for(int i=0;i<r;++i)
  	{
    	ans*=(n-i);
    	ans/=(i+1);
  	}
  	return ans;
}

bool isPalindrome(string s)
{
  int i,j;
  for(i=0,j=s.length()-1;i<=j;i++,j--)
    if(s[i]!=s[j])
        return 0;
  return 1;
}

int stn(string s)       //stn=string_to_number
{
	stringstream s1;
	s1<<s;
	int num;
	s1>>num;
	return num;
}

string nts(int n)       //nts=number_to_string
{
	stringstream s1;
	s1<<n;
	string s;
	s1>>s;
	return s;
}

void modBigNumber(string num, int m)
{
    // Store the modulus of big number
    vector<int> vec;
    int mod = 0;

    // Do step by step division
    for (int i = 0; i < num.size(); i++) {

        int digit = num[i] - '0';

        // Update modulo by concatenating
        // current digit.
        mod = mod * 10 + digit;

        // Update quotient
        int quo = mod / m;
        if((vec.size()!=0)||(quo!=0))        //to remove initiale zeros
        vec.push_back(quo);
        // Update mod for next iteration.
        mod = mod % m;
    }
   // cout << "\nRemainder : " << mod << "\n";
   // cout << "Quotient : ";rep(i,0,vec.size()-1,1)cout<<vec[i];cout<<"\n";
    return;
}

class DSU
{
	public:
	vector<int> v,size;

	DSU(int n)
	{
	    v.resize(n+1);
		size.resize(n+1,1);
		for(int i=1;i<=n;++i)
			v[i]=i;
	}

	int find_set(int a)
	{
		if(v[a]==a)
			return a;
		else
			return v[a]=find_set(v[a]);
	}

	void union_sets(int a,int b)
	{
		a=find_set(a);
		b=find_set(b);
		if(a!=b)
		{
			if(size[a]<size[b])
			{
				v[a]=b;
				size[b]+=size[a];
			}
			else
			{
				v[b]=a;
				size[a]+=size[b];
			}
		}
	}
};

struct BIT          //Pass index with zero based
{
	vector<int> v;
	int sz;
	
	void init(int n)
	{
		v.clear();
		v.resize(n+1,0);
		sz=n+1;
	}

	void update_BIT(int index,int n)
	{
		index++;
		while(index<sz)
		{
			v[index]+=n;
			index+=index&(-index);
		}
	}

	int get_sum(int index)
	{
		int sum=0;
		index++;
		while(index>0)
		{
			sum+=v[index];
			index-=index&(-index);
		}
		return sum;
	}
	
	int get_sum(int l,int r)
	{
		if(r<l)
			return 0;
		if(l==0)
			return get_sum(r);
		else
			return get_sum(r)-get_sum(l-1);		
	}
};


struct SegmentTree
{
	int n;
	vector<int> v,lazy,ar;

	void init(vector<int> a,int sz)
	{
		n=sz;
		ar=a;
		sz=4*n+1;
		v.clear();
		lazy.clear();
		v.resize(sz,0);
		lazy.resize(sz,0);
	}

	void build(int ipos,int fpos,int pos=1)
	{
		if(ipos>fpos)
			return ;
		if(ipos==fpos)
			v[pos]=ar[ipos];
		else
		{
			int mid=(ipos+fpos)/2;
			build(ipos,mid,pos*2);
			build(mid+1,fpos,pos*2+1);
			v[pos]=v[pos*2]+v[pos*2+1];
		}
	}


	int query(int l,int r,int ipos,int fpos,int pos=1) //<--This segtree is for sum of range
	{
		if(ipos>fpos)
			return 0;
		if(l>r)
			return 0;
		if (lazy[pos] != 0) 
	    	{ 
			v[pos] +=(fpos-ipos+1) * lazy[pos]; 
			if (ipos != fpos) 
			{
			    lazy[pos*2]  += lazy[pos]; 
			    lazy[pos*2 + 1]   += lazy[pos]; 
			} 
			lazy[pos] = 0; 
	    	} 
		int mid=(ipos+fpos)/2;
		if((l==ipos)&&(r==fpos))
			return v[pos];
		else
		 	return query(l,min(mid,r),ipos,mid,pos*2)+query(max(mid+1,l),r,mid+1,fpos,pos*2+1);
	}

	void update(int index,int val,int ipos,int fpos,int pos=1)
	{
		if(ipos>fpos)
			return ;
		if(ipos==fpos)
		{
			if(ipos==index)
			{
				v[pos]+=val;
			}
		}	
		else
		{
			int mid=(ipos+fpos)/2;
			if(mid>=index)
				update(index,val,ipos,mid,pos*2);
			else
				update(index,val,mid+1,fpos,pos*2+1);
			v[pos]=v[pos*2]+v[pos*2+1];
		}

	}

	void updateRangeUtil(int l,int r,int diff,int ipos,int fpos,int pos=1) 
	{ 
	    if (lazy[pos] != 0) 
	    { 
	    	//if using segtree for max element remove (fpos-ipos+1) and add only lazy[pos]
	        v[pos] +=(fpos-ipos+1) * lazy[pos];   
	        if (ipos != fpos) 
	        {
	            lazy[pos*2]  += lazy[pos]; 
	            lazy[pos*2 + 1]   += lazy[pos]; 
	        } 
	        lazy[pos] = 0; 
	    } 
	  
	    if (ipos>fpos || ipos>r || fpos<l) 
	        return ; 
	  
	    if (ipos>=l && fpos<=r) 
	    { 
	        v[pos] += (fpos-ipos+1)*diff; 
	        if (ipos != fpos) 
	        { 
	            lazy[pos*2]+= diff; 
	            lazy[pos*2+1]+= diff; 
	        } 
	        return; 
	    } 
	    int mid = (ipos+fpos)/2; 
	    updateRangeUtil(l, r, diff, ipos, mid, pos*2); 
	    updateRangeUtil(l, r, diff, mid+1, fpos, pos*2+1); 
	    v[pos] = v[pos*2] + v[pos*2+1]; 
	} 
};

struct Dijkstra
{
	vector<int> p,dis;
	int n;
	vector<int> check;
	Dijkstra(int size)          
	{
		n=size;
		p.resize(n+1,-1);
		dis.resize(n+1,inf);
		check.resize(n+1,0);
	}


	void build(int s,vector<vector<pair<int,int>>> adj)            //adj pair-->i.fi==node and i.se=cost better make vvpii adj global
	{
	    dis[s]=0;
	    set<pair<int,int>> q;
	    q.insert({0,s});
		while(!q.empty())
		{
			int v=q.begin()->se;
			q.erase(q.begin());
			
			for(auto i:adj[v])
			{
				if(dis[i.fi]>dis[v]+i.se)
				{
					q.erase({dis[i.fi],i.fi});	
					dis[i.fi]=dis[v]+i.se;
					p[i.fi]=v;
					q.insert({dis[v]+i.se,i.fi});
				}
			}	
		}
	}

	vector<int> get_path(int s,int v)
	{
		vector<int> path;
		int i;
		for(i=v;p[i]!=-1;i=p[i])
			path.pb(i);
		path.pb(i);
		reverse(path.begin(),path.end());
		return path;
	}
};




struct edge
{
	int u,v,cost;
};
struct belman_ford
{
	vector<int> dis;
	vector<int> par;
	int n;
	
	belman_ford(int n)
	{
		this->n=n;
		dis.resize(n+1,inf);
		par.resize(n+1);
	}

	vector<int> find_dis(vector<edge> e,int m,int pos)
	{
		dis[pos]=0;
		par[pos]=pos;
		bool change;
		for(int j=0;j<n-1;++j)
		{
			change=false;
			for(int i=0;i<m;i++)
			{
				if(dis[e[i].u]<inf)
				if(dis[e[i].v]>dis[e[i].u]+e[i].cost)
				{
					change=true;
					dis[e[i].v]=dis[e[i].u]+e[i].cost;
					par[e[i].v]=e[i].u;
				}
			}
			if(change==false)
			break;
		}
		return dis;
	}

	vector<int> get_path(int pos1,int pos2)
	{
		vector<int> path;
		if(dis[pos2]==inf)
			return path;
		path.pb(pos2);
		while(pos2!=pos1)
		{
			pos2=par[pos2];
			path.pb(pos2);
		}
		reverse(all(path));
		return path;
	}
};


vector<int> bfs(vector<vector<int>> adj,int no_of_edges,int root_node)
{
	int n=no_of_edges;
	int root=root_node;
	vector<int> parent(n+1);
	vector<int> mp(n+1);        //visited
	queue<int> qu;
	qu.push(root);
	mp[root]=1;
	parent[root]=0;        //--> Parent of root node we have assigned 0 <----
	while(!qu.empty())
	{
		int node=qu.front();
		qu.pop();
		int flag=0;
		for(auto i:adj[node])
		{
			if(mp[adj[node][i]]==0)
			{
				flag=1;
				parent[adj[node][i]]=node;
				mp[adj[node][i]]=1;	
				qu.push(adj[node][i]);
			}
		}
	}
	return parent;
}

vector<int> visited;
vector<vector<int>> adj;
void dfs(int root)
{
	visited[root]=1;
	for(auto i:adj[root])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
}

//vector<vi> adj,parent;  -->parent size is = [N][22]
//vi vis,depth;

/* DFS for LCA*/
void dfs(int root)
{
	vis[root]=1;
	for(auto i:adj[root])
		if(!vis[i])
		{
			parent[i][0]=root;
			for(int j=1;j<21;++j)
				parent[i][j]=parent[parent[i][j-1]][j-1];

			depth[i]=depth[root]+1;

			dfs(i);
		}
}

int LCA(int u,int v)
{
	if(depth[u]>depth[v])
		swap(u,v);

	int diff=depth[v]-depth[u];

	for(int i=0;i<21;++i)
		if((diff>>i) & 1)
			v=parent[v][i];
	if(u==v)
		return u;

	for(int i=20;i>=0;--i)
		if(parent[u][i]!=parent[v][i])
		{
			u=parent[u][i];
			v=parent[v][i];
		}

	return parent[u][0];
}


//vector<vector<int>> trie(1200001,vector<int>(26,-1));     //12000.. is size of string * no. of strings
int timer;
void maketrie(vector<vector<int>> trie,string &s)
{
	int sz=s.size();
	int i=0,v=0;
	while(i<sz)
	{
		if(trie[v][s[i]-'a']==-1)
		{
			trie[v][s[i]-'a']=++timer;
		}
		v=trie[v][s[i]-'a'];
		++i;
	}
}

/*
string s;

struct node
{
	int cnt=0;
	node *ptr[26];
	node()
	{
		for(int i=0;i<26;++i)
		{
			ptr[i]=NULL;
		}
	}
};

void maketrie(node *root,int idx,int sz)
{
	if(s[idx]=='\0')
	{
		root->cnt++;
		return;
	}

	int num=s[idx]-'A';
//	root->cnt++;
	if(root->ptr[num]==NULL)
	{
		root->ptr[num]=new node;
	}

	maketrie(root->ptr[num],idx+1,sz);
}

*/



struct node
{
	int cnt;
	node *left,*right;
	node()
	{
		cnt=0;
		left=NULL;
		right=NULL;
	}
};
struct trieforMaxXor
{
	void insert(node *root,string &s,int idx=0)
	{
		if(s[idx]=='\0')
			return;
		else
		{
			if(s[idx]=='0')
			{
				if(root->left==NULL)
					root->left=new node();
				root->left->cnt++;
				insert(root->left,s,idx+1);
			}
			else 
			{
				if(root->right==NULL)
					root->right=new node();
				root->right->cnt++;
				insert(root->right,s,idx+1);
			}
		}
	}

	void erase(node *root,string &s,int idx=0)
	{
		if(s[idx]=='\0')
			return;
		else
		{
			if(s[idx]=='0')
			{
				root->left->cnt--;
				if(root->left->cnt==0)
				{
					root->left=NULL;
					delete(root->left);
				}
				else erase(root->left,s,idx+1);
			}
			else
			{
				root->right->cnt--;
				if(root->right->cnt==0)
				{
					root->right=NULL;
					delete(root->right);
				}
				else erase(root->right,s,idx+1);
			}
		}
	}

	void cal(node *root,string &s,string &match,int idx=0)
	{
		if(s[idx]=='\0')
			return;
		else
		{
			if(s[idx]=='0')
			{
				if(root->left!=NULL)
				{
					match[idx]='1';
					cal(root->left,s,match,idx+1);
				}
				else
				{
					cal(root->right,s,match,idx+1);
				}
			}
			else
			{
				if(root->right!=NULL)
				{
					match[idx]='1';
					cal(root->right,s,match,idx+1);
				}
				else
				{
					cal(root->left,s,match,idx+1);
				}
			}
		}
	}
};



struct polyhash
{
	vector<pair<int,int>> table;
	int base1=31,base2=37,mod1=1e9+7,mod2=1e9+9,val1,val2,n;
	pair<int,int> hashpair(string s)
	{
		val1=1;
		val2=1;
		table.clear();
		n=s.size();
		table.resize(n);
		pii res={0,0};
		for(int i=0;i<n;++i)
		{
			res.fi+=(val1*(s[i]-'a'+1))%mod1;
			res.fi%=mod1;
			res.se+=(val2*(s[i]-'a'+1))%mod2;
			res.se%=mod2;
			table[i]={res.fi,res.se};
			val1*=base1;
			val2*=base2;
			val1%=mod1;
			val2%=mod2;
		}
		return res;
	}
};

/*
int longest_palindrome_prefix(string s)
{
 
	string kmprev = s;
	reverse(kmprev.begin(), kmprev.end());
	string kmp = s + "#" + kmprev;
 
	vector<int> lps(kmp.size(), 0);
	for (int i = 1; i < lps.size(); ++i)
	{
		int prev_idx = lps[i - 1];
 
		while (prev_idx > 0 && kmp[i] != kmp[prev_idx])
		{
			prev_idx = lps[prev_idx - 1];
		}
 
		lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
	}
 
 
	return lps[lps.size() - 1];
}*/


//KMP O(n) solution (Longest palindromic prefix)

int solve(string s) {
	int arr[100001];
    string res = s;
    int len;
    // Create pre-process array for KMP
    // Reverse and append to original
    reverse(s.begin(), s.end()); 
    // To avoid already palindrome cases
    // aa -> aa + aa = aaaa -> length = 3 which is greater than 2
    s = res + "#" + s;
    // 0 length from start matches 0 characters from last
    arr[0] = 0;
    int i=0, j=1;
    // Finding longest palindromic prefix
    len = s.length();
    while(j < len)
    {
        if(s[i] == s[j])
        {
            arr[j] = i+1;
            i++; j++;
        }
        else 
        {
            if(i>=1)
                i = arr[i-1];
            else
            {
                arr[j] = 0;
                j++;
            }
        }
    }
    return res.length() - arr[len-1];
}


vector<int> manacher(string s)    //Return a vector of longest Palindrome with ith centre
						  //if size of palindrome is even ith character is in left part
{
	int n=s.size();
	vector<int> res(n,0);
	string temp="@#";
	for(int i=0;i<n;++i)
	{
		temp+=s[i];
		temp+='#';
	}
	temp+='%';
	
	int mxr=temp.size();
	vector<int> val(mxr,0);
	int mirror=1,r=1;
	for(int i=2;i<mxr-1;++i)
	{
		if(r>i)
			val[i]=min(r-i,val[mirror-(i-mirror)]);
		
		while(temp[val[i]+i+1]==temp[i-(val[i]+1)])
		{
			++val[i];
		}

		if(i+val[i]>r)
		{
			mirror=i;
			r=i+val[i];
		}
		res[i/2-1]=max(res[i/2-1],val[i]);
		
	}
	return res;
}

/*Include for um<pll,ll>*/
struct hash_pair
{
	template<class T1,class T2>
	size_t operator()(const pair<T1, T2>&p) const
	{
		auto hash1=hash<T1>{}(p.fi);
		auto hash2=hash<T2>{}(p.se);
		return hash1^hash2;
	}
};

void inp_out()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

int32_t main()
{
	fastIO
	//inp_out();
	
	return 0;
}

