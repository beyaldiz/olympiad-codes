#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;
typedef pair < int , int > ii;

int n, x, y, ans = 1, amk, su, bas = 1, son;
ii q[N];

void ekle(int x, int i){
	while(son - bas + 1 > 0 and q[son].st <= x)
		son--;
	q[++son] = mp(x, i);
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d",&x ,&y);
		if(i == 1){
			amk = 1;
			ekle(x, i);
		// cout << i << " " << q[bas].st << " " << q[bas].nd << endl;
			continue;
		}
		while(son - bas + 1 > 0 and q[bas].st > y){
			// cout << "amk " << i << " " << y << q[bas].st << endl;
			amk = q[bas].nd + 1;
			bas++;
		}
		ekle(x, i);
		ans = max(ans, i - amk + 1);
		// cout << i << " " << q[bas].st << " " << q[bas].nd << " " << amk << endl;
	}
	printf("%d\n", ans);
	return 0;
}
