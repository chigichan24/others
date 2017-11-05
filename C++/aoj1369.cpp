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
typedef long long ll;
typedef pair<ll,ll> Pii;
typedef pair<Pii,int> P;
typedef vector<int> vi;
 
template<class T>
ostream& operator<<(ostream &out, const vector<T> &v){
    out << "{";
    rep(i,v.size()){
        out << v[i] <<", ";
    }
    return out << "}" << endl;
}
ll s[200001];
int memo[200001];
vector<Pii> cordinate;
int main(){
    fill(s,s+200001,1LL);
    memset(memo,0,sizeof(memo));
    int N,M;
    cin >> N >> M;
    rep(i,M){
        ll x,y;
        cin >> x >> y;
        --y;
        cordinate.pb(mk(x,y));
    }
    sort(cordinate.begin(),cordinate.end());
 
    rep(i,M){
        ll y = cordinate[i].sc;
        if(memo[y] == 0){
            ll sum = s[y]+s[y+1];
            s[y] = s[y+1] = sum;
            memo[y] = sum;
        }
        else{
            s[y] = s[y+1] = s[y] + s[y+1] - memo[y];
            memo[y] = s[y];
        }
    }
 
    rep(i,N){
        printf("%lld%c",s[i],i==N-1?'\n':' ');
    }
 
    return 0;
}