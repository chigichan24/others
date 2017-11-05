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
int memo[200001];
int main(){
    int N,M;
    cin >> N >> M;
    vi a;
    rep(i,M){
        int tmp;
        cin >> tmp;
        a.pb(tmp);
    }
    reverse(a.begin(),a.end());
    rep(i,M){
        if(!memo[a[i]]++){
            cout << a[i] << endl;
        }
    }
    reps(i,1,N+1){
        if(!memo[i]){
            cout << i << endl;
        }
    }
    return 0;
}