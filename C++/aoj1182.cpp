#include<bits/stdc++.h>
#define reps(i,j,k) for(int i=(j); i<(k); i++)
#define rep(i,j) reps(i,0,j)
#define fs first
#define fr fs
#define sc second
#define pb push_back
#define mk make_pair
#define INF 1e9
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int D[20][128][128];
int D2[128][128];
vi q[22];
vi r[22];
vi po[22];
int calcCost(int campany, int distance){
    rep(i,q[campany].size()){
        if(distance < q[campany][i]){
            return po[campany][i-1] + r[campany][i-1]*(distance-q[campany][i-1]);
        }
    }
    int t = po[campany].size()-1;
    if(distance >= INF)return INF;
    return po[campany][t] + r[campany][t]*(distance-q[campany][t]);
}
 
int main(){
    int N,M,C,S,G;
    while(cin >> N >> M >> C >> S >> G,N){
        --S;--G;
         
        rep(i,20)rep(j,128)rep(k,128){
            D[i][j][k] = INF*(j!=k);
        }
        rep(i,22){
            q[i].clear();
            r[i].clear();
            po[i].clear();
        }
         
        rep(i,M){
            int x,y,c,d;
            cin >> x >> y >> d >> c;
            --x;--y;--c;
            D[c][x][y] = D[c][y][x] = min(d,D[c][y][x]); 
        }
        vi p(C);
        rep(i,C){
            cin >> p[i];
        }
 
        rep(i,C){
            q[i].pb(0);
            rep(j,p[i]-1){
                int tmp;
                cin >> tmp;
                q[i].pb(tmp);
            }
 
            rep(j,p[i]){
                int tmp;
                cin >> tmp;
                r[i].pb(tmp);
            }
        }
        rep(i,C){
            po[i].pb(0);
            rep(j,p[i]-1){
                po[i].pb(po[i][j]+r[i][j]*(q[i][j+1]-q[i][j]));
            }
        }
         
        rep(t,C)rep(k,N)rep(i,N)rep(j,N){
            D[t][i][j] = min(D[t][i][j],D[t][i][k]+D[t][k][j]);
        }
 
        rep(i,N)rep(j,N){
            D2[i][j] = INF * (i != j);
        }
        rep(t,C)rep(i,N)rep(j,N){
            D2[i][j] = min(D2[i][j],calcCost(t,D[t][i][j]));
        }
 
        rep(k,N)rep(i,N)rep(j,N){
            D2[i][j] = min(D2[i][j],D2[i][k]+D2[k][j]);
        }
        if(D2[S][G] >= INF)cout << -1 << endl;
        else cout << D2[S][G] << endl;
    }
}
