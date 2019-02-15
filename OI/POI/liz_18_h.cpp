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
#define inf 1000000000000000000
#define MOD 1000000007
#define N 1000005	
#define M 1000003
#define LOG 19
#define KOK 650
using namespace std;

int n,m,val;
int lsts[N],pre[N];
char s[N];

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m>>(s+1);

	for(int i=n+1;i>=1;i--) lsts[i]=(s[i]!='T'?i-1:lsts[i+1]);

	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+1+(s[i]=='T');

	while(m--) {

		cin>>val;

		int pos=lower_bound(pre+1,pre+1+n,val)-pre;

		if(pre[pos]==val) {

			cout<<1<<" "<<pos<<"\n";

		}
		else if(lsts[1]+pos>n && lsts[pos]==n) {

			cout<<"NIE"<<"\n";

		}
		else {

			int be=lsts[1]+1;
			int en=lsts[pos]+1;

			if(be-1<en-pos) {

				cout<<be+1<<" "<<be+pos-1<<"\n";

			}
			else {

				cout<<en-pos+1<<" "<<en<<"\n";

			}

		}

	}

}
