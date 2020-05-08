// 리틀 프렌즈 사천성
#include<bits/stdc++.h>

using namespace std;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int N,M;
bool check(char c,int y,int x,vector<string> &board) {
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];

        while((ny>=0&&nx>=0&&ny<N&&nx<M) && (board[ny][nx]=='.' || board[ny][nx]==c)) {
            if(board[ny][nx]==c) {
                board[y][x]='.';
                board[ny][nx]='.';
                return true;
            }

            for(int j=0;j<4;j++) {
                if(i==j || (i==0&&j==1) || (i==1&&j==0) || (i==2&&j==3) || (i==3&&j==2)) continue;      // 해당 방향에서 동,서쪽이 아닌경우는 검사x

                int nny=ny+dy[j],nnx=nx+dx[j];

                while((nny>=0&&nnx>=0&&nny<N&&nnx<M) && (board[nny][nnx]=='.' || board[nny][nnx]==c)) {
                    if(board[nny][nnx]==c) {
                        board[y][x]='.';
                        board[nny][nnx]='.';
                        return true;
                    }
                    nny+=dy[j];
                    nnx+=dx[j];
                }
            }
            ny+=dy[i];
            nx+=dx[i];
        } 
    }
    return false;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int n, int m, vector<string> board) {
    string answer = "";
    N=n,M=m;
    vector<pair<char,pair<int,int>>> v;     // 문자, 좌표
    set<char> set;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]>='A' && board[i][j]<='Z') {
                if(set.find(board[i][j])==set.end()) {
                    v.push_back({board[i][j],{i,j}});
                    set.insert(board[i][j]);
                }
            }
        }
    }
    sort(v.begin(),v.end());

    bool flag=false;
    do {
        flag=false;

        for(int i=0;i<v.size();i++) {       // 모든 알파벳 다 검사
            if(check(v[i].first,v[i].second.first,v[i].second.second,board)) {
                answer+=v[i].first;
                v.erase(v.begin()+i);
                flag=true;
                
                break;
            }
        }
    } while(flag);

    if(v.size()>0) return "IMPOSSIBLE";

    return answer;
}

int main() {

    int n=4,m=4;
    vector<string> board={".ZI.", "M.**", "MZU.", ".IU."};
    string result=solution(n,m,board);
    cout<<result<<"\n";

    return 0;
}