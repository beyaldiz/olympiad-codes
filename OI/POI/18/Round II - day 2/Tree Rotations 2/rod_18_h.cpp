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
#define MOD 1000000007
#define N 2000005
#define M 1000003
#define LOG 19
#define KOK 750
using namespace std;

int n,tot;
int f[N],l[N],r[N],val[N],sub[N];
ll ans;

int get(int x) {

	int res=0;

	for(int i=x;i>=1;i-=i&-i) res+=f[i];

	return res;

}

void up(int x,int y) {

	for(int i=x;i<=n;i+=i&-i) f[i]+=y;

}

void dfs3(int node,int mul) {

	if(val[node]) {
	
		up(val[node],mul);

		return ;

	}	

	dfs3(l[node],mul);
	dfs3(r[node],mul);

}

ll dfs2(int node) {

	if(val[node]) return get(val[node]);

	return dfs2(l[node])+dfs2(r[node]);

}

void dfs(int node,int del) {

	if(val[node]) {
	
		if(!del) dfs3(node,1);

		return ;
	
	}

	dfs(r[node],1);
	dfs(l[node],0);

	ll add=dfs2(r[node]);

	umin(add,(ll)sub[l[node]]*sub[r[node]]-add);

	ans+=add;

	if(del) dfs3(l[node],-1);
	else dfs3(r[node],1);

}

int build() {

	int cur=++tot;

	cin>>val[cur];

	if(!val[cur]) {

		l[cur]=build();
		r[cur]=build();

		if(sub[l[cur]]<sub[r[cur]]) swap(l[cur],r[cur]);

		sub[cur]+=sub[l[cur]]+sub[r[cur]];

	}	
	else sub[cur]=1;

	return cur;

}

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n;

	dfs(build(),0);

	cout<<ans;

}
