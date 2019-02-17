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
#define inf 1000000000
#define MOD 1000000007
#define N 250005	
#define M 1000003
#define LOG 19
#define KOK 750
using namespace std;

int k;
ll a[N];
ll n;
vector<ll> pr;
map<ll,bool> ok;

void solve(ll val) {

	if(ok[val]) return ;

	ok[val]=1;

	for(int i:pr) {

		if(val%i==0) solve(val/i);

	}

}

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>k;

	if(k==1) {

		cout<<n;

		return 0;

	}

	for(int i=1;i<=k;i++) cin>>a[i];

	bool ok0=!a[k];

	a[k]=__gcd(a[k],n);

	for(int i=1;i<k;i++) a[i]=__gcd(a[i],a[k]);

	ll tut=a[k];

	for(int i=2;(ll)i*i<=a[k];i++) {

		int cnt=0;

		while(a[k]%i==0) {

			++cnt;

			a[k]/=i;

		}

		if(cnt) pr.pb(i);

	}

	if(a[k]) pr.pb(a[k]);

	for(int i=1;i<k;i++) {

		solve(a[i]);		

	}

	a[k]=tut;

	stack<ll> s;

	for(int i=1;(ll)i*i<=a[k];i++) {

		if(a[k]%i==0) {

			if(!ok[i]) {

				cout<<n/i;

				return 0;

			}

			s.push(a[k]/i);

		}

	}

	while(!s.empty()) {

		ll val=s.top();

		s.pop();

		if(!ok[val]) {

			cout<<n/val;

			return 0;

		}

	}

	cout<<(*min_element(a+1,a+1+k)!=0 && ok0);

}
