#include <bits/stdc++.h>
#define reps(i,j,k) for(int i = j; i < k; ++i)
#define rep(i,j) reps(i,0,j)
#define pb push_back
#define fr first
#define fs fr
#define sc second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> Pii;
typedef pair<int,int> pii;
typedef long long ll;
struct data{
    int team;
    int ac;
    int score;
    data(){}
    data(int team,int ac,int score){
        this->team = team;
        this->ac = ac;
        this->score = score;
    }
    bool operator<(const data &a)const{
        if(ac == a.ac && score == a.score){
            return team < a.team;
        }
        else if(ac == a.ac){
            return score < a.score;
        }
        else{
            return ac > a.ac;
        }
    }
};
int main(){
    int T,P,R;
    while(cin >> T >> P >> R,(T|P|R)){
        vector < data > D(T);
        rep(i,T){
            D[i] = data(i,0,0);
        }
        int wrong[55][10810] = {{}};
        rep(i,R){
            int t_id,p_id,t;
            string msg;
            cin >> t_id >> p_id >> t >> msg;
            --t_id;--p_id;
            if(msg == "WRONG"){
                wrong[t_id][p_id]++;    
            }
            else{
                D[t_id] = data(t_id,D[t_id].ac+1,D[t_id].score+wrong[t_id][p_id]*1200+t);
            }
        }
        sort(D.begin(),D.end());
        rep(i,T){
            cout << D[i].team+1 << " " << D[i].ac << " " << D[i].score << endl;
        }
    }
    return 0;
}
