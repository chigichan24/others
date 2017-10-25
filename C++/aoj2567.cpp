#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define reps(i,j,k) for(int i = (j); i < (k); ++i)
#define rep(i,j) reps(i,0,j)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<Pii,int> P;
typedef vector<int> vi;
typedef long long ll;
template<class T>
ostream& operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()){
		out << v[i] <<", ";
	}
	return out << "}" << endl;
}
int N, M, L, S, T;
int D[310][310];
vector<Pii> town;
int memo[1<<17][17];

int solve(int bit, int now) {
	int t = INF;
	rep(i,town.size()) {
		if(!(1&(bit>>i))){
			if(memo[bit|(1<<i)][i] != -1){
				return memo[bit|(1<<i)][i];
			}
			t = min(t, solve(bit|(1<<i),i) + D[town[now].fr][town[i].fr] + town[i].sc);
			memo[bit|(1<<i)][i] = t;
		}
	}
	return 0;
}


int main() {

	while(cin >> N  >> M >> L >> S >> T,N){
		town.clear();
		memset(memo,-1,sizeof(memo));
		--S;
		rep(i,N){
			rep(j,N){
				D[i][j] = INF*(i!=j);
			}
		}
		rep(i,M){
			int a,b,c;
			cin >> a >> b >> c;
			--a;--b;
			D[a][b] = D[b][a] = c;
		}
		rep(k,N){
			rep(i,N){
				rep(j,N){
					D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
				}
			}
		}
		town.pb(mk(S,0));
		rep(i,L){
			int j,e;
			cin >> j >> e;
			--j;
			town.pb(mk(j,e));
		}
		memo[1<<0][0] = 0;
		solve(1<<0, 0);
		int mx = 0;

		rep(i,1<<town.size()){
			
			 if(!(1&(i>>0))){
			 	continue;
			 }

			reps(j,1,town.size()){
				if(memo[i][j] == -1)continue;
				if(memo[i][j]+D[town[j].fr][S] <= T) {
					mx = max(mx, __builtin_popcount(i)-1);
				}
			}
		}

		cout << mx << endl;

	}
	
	return 0;
}