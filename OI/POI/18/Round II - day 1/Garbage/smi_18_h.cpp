#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1ll<<(x))
#define inf 2000000000
#define MOD 1000000009
#define N 1000005
#define M 1000003
#define LOG 25
#define KOK 580
using namespace std;

int n,m,tot;
int mark[N],in[N],e[N];
vector<int> went,v[N];
vector<vector<int>> ans;

void dfs(int node) {

	while(sz(v[node])) {

		int ed=v[node].back();

		v[node].ppb();

		if(mark[ed]) continue ;

		mark[ed]=1;

		dfs(e[ed]^node);

	}

	went.pb(node);	

}

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;

	for(int i=1;i<=m;i++) {

		int x,y,z,w;

		cin>>x>>y>>z>>w;

		if(z^w) {

			e[++tot]=x^y;

			v[x].pb(tot);
			v[y].pb(tot);

		}

	}

	for(int i=1;i<=n;i++) {

		if(sz(v[i])&1) {

			cout<<"NIE";

			return 0;

		}

	}

	for(int i=1;i<=n;i++) {

		if(sz(v[i])) dfs(i);

	}

	vector<int> tut;

	for(int i=0;i<sz(went);i++) {

		int node=went[i];

		if(in[node]) {

			int cur;
			vector<int> add;

			add.pb(node);

			do {

				cur=tut.back();

				tut.ppb();

				in[cur]=0;

				add.pb(cur);

			} while(cur!=node);

			ans.pb(add);

		}

		tut.pb(node);
		in[node]=1;

	}

	cout<<sz(ans)<<"\n";

	for(auto x:ans) {

		cout<<sz(x)-1<<" ";

		for(int y:x) {

			cout<<y<<" ";

		}

		cout<<"\n";

	}

}
