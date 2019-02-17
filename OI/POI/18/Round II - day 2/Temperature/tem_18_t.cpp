#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define len(a) (int)a.size()
#define all(a) (a.begin(),a.end())
#define fi first
#define sc second
#define ort(x,y) (x+y)/2
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);
#define d1(x) cerr<<#x<<":"<<x<<endl;
#define d2(x,y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define d3(x,y,z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define N (int) (1e6+5)
#define M (int) ()
#define inf (int) (1e7)
#define p (1000000007)
#define heap priority_queue
#define mem(a,val) memset(a,val,sizeof(a))
#define y1 asdassa
#define left ind+ind
#define right ind+ind+1
#define mid (l+r)/2
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
pii ar[N],deq[N];
int n,ans,bas,son;
int main(){
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++)
    scanf("%d %d",&ar[i].fi,&ar[i].sc);
  for(int i = 1,j = 0 ; i <= n; i++){

    while(deq[son + 1].fi>ar[i].sc && son!=bas) {
      j = deq[son + 1].sc;
      son++;
    }
    while(deq[bas].fi<ar[i].fi && son!=bas)
      bas--;
    deq[++bas] = mp(ar[i].fi,i);
    ans = max(ans,(i-j));
  }
  printf("%d\n",ans);
  return 0;
}
