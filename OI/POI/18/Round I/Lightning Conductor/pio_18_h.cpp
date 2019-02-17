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
#define N 500005	
#define M 1000003
#define LOG 19
#define KOK 750
using namespace std;

int n,tot;
int rmost[KOK+5],lmost[KOK+5],val[KOK+5],lmax[N],rmax[N];
ii a[N];

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n;

	for(int i=1;i<=n;i++) {
	
		cin>>a[i].st;

		a[i].nd=i;
	
	}

	sort(a+1,a+1+n,greater<ii>());

	for(int i=1;i<=n && tot<KOK;i++) {

		++tot;

		rmost[tot]=a[i].nd;

		while(i+1<=n && a[i].st==a[i+1].st) i++;

		lmost[tot]=a[i].nd;

		val[tot]=a[i].st;

	}

	for(int i=1;i<=tot;i++) {

	//	cout<<"i val[i]: "<<i<<" "<<val[i]<<"\n";

	//	cout<<"lmost[i] rmost[i]: "<<lmost[i]<<" "<<rmost[i]<<"\n";

		for(int j=0;lmost[i]+j*j+1<=n;j++) {

			umax(lmax[lmost[i]+j*j+1],val[i]+j+1);

		}

		for(int j=0;rmost[i]-j*j-1>=1;j++) {

			umax(rmax[rmost[i]-j*j-1],val[i]+j+1);

		}

	}

	for(int i=1;i<=n;i++) umax(lmax[i],lmax[i-1]);

	for(int i=n;i>=1;i--) umax(rmax[i],rmax[i+1]);

	sort(a+1,a+1+n,[](ii x,ii y) {return x.nd<y.nd;});

	for(int i=1;i<=n;i++) cout<<max(0,max(rmax[i],lmax[i])-a[i].st)<<"\n";

}
