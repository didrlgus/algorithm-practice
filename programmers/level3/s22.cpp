// 기둥과 보 설치
#include<bits/stdc++.h>

using namespace std;

int arr[110][110][2];
int N;

bool insert(int y,int x,int t) {
    if(t==0) {          // 기둥
        if(y==0) {      // 기둥이 바닥 위일 경우
            return true;
        } else if((x-1>=0 && arr[y][x-1][1]==1) || arr[y][x][1]==1) {   // 보의 끝부분일 경우
            return true;
        } else if(y-1>=0 && arr[y-1][x][0]==1) {   // 다른 기둥 위일 경우
            return true;
        }
    } else {            // 보
        if((y-1>=0 && arr[y-1][x][0]==1) || (x+1<=N && y-1>=0 && arr[y-1][x+1][0]==1)) {            // 한쪽 끝 부분이 기둥일 경우
            return true;
        } else if(x-1>=0 && x+1<=N && arr[y][x-1][1]==1 && arr[y][x+1][1]==1) {       // 양쪽 끝이 보일 경우, 꼭지점마다 요소가 추가되므로 범위에서 N을 포함해야함
            return true;
        }
    }
    return false;
}

bool remove() {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            for(int k=0;k<2;k++) {
                if(arr[i][j][k]==1) {
                    arr[i][j][k]=0;         // 지워보고

                    if(!insert(i,j,k)) {    // 설치가 불가능 하면 지우는것 불가
                        arr[i][j][k]=1;
                        return false;
                    }

                    arr[i][j][k]=1;         // 복구
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N=n;

    // ex)  x,y,a,b (1,0,0,1)  -> 1,0 좌표에 기둥(0) 설치(1) 
    for(int i=0;i<build_frame.size();i++) {
        int y=build_frame[i][1], x=build_frame[i][0];
        if(build_frame[i][2]==0) {              // 1. 기둥일 경우
            if(build_frame[i][3]==1) {          // 설치
                if(insert(y,x,0)) {             // y,x 기둥
                    arr[y][x][0]=1;
                }
            } else {                            // 제거
                arr[y][x][0]=0;                 // 지우려는 것을 일단 제거해보고

                if(!remove()) {                 // 지우는것이 불가능 하면 원상복구
                    arr[y][x][0]=1;             
                }
            }
        } else {                                // 2. 보일 경우
            if(build_frame[i][3]==1) {          // 설치
                if(insert(y,x,1)) {             // y,x, 보
                    arr[y][x][1]=1;
                }
            } else {                            // 제거
                arr[y][x][1]=0;                 

                if(!remove()) {                 
                    arr[y][x][1]=1;
                }
            }
        }
    }

    for(int j=0;j<=n;j++) {
        for(int i=0;i<=n;i++) {
            for(int k=0;k<2;k++) {
                vector<int> tmp;
                if(arr[i][j][k]==1) {
                    tmp.push_back(j);
                    tmp.push_back(i);
                    tmp.push_back(k);
                    answer.push_back(tmp);
                }
            }
        }
    }

    return answer;
}

int main() {

    int n=5;
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, 
            {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};

    vector<vector<int>> result=solution(n,build_frame);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) printf("%d ",result[i][j]);
        printf("\n");
    }
    return 0;
}