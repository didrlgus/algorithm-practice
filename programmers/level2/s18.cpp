// 숫자 야구
#include <string>
#include <vector>

using namespace std;

bool arr[15][15][15]={0,};

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            for(int k=1;k<=9;k++) {
                if(i!=j && j!=k && i!=k) {
                    arr[i][j][k]=true;
                }
            }
        }
    }

    for(int q=0;q<baseball.size();q++) {
        int o=baseball[q][0];           // 123
        int strike=baseball[q][1];      // 1
        int ball=baseball[q][2];        // 1

        for(int i=1;i<=9;i++) {
            for(int j=1;j<=9;j++) {
                for(int k=1;k<=9;k++) {
                    if(i!=j && j!=k && i!=k) {
                        int a=o/100;        //1
                        int b=(o%100)/10;   //2
                        int c=o%10;         //3
                        int sCnt=0,bCnt=0;

                        if(a==i) sCnt++;
                        if(b==j) sCnt++;
                        if(c==k) sCnt++;

                        if(strike!=sCnt) {
                            arr[i][j][k]=false;
                            continue;
                        }

                        if(a==j || a==k) bCnt++;
                        if(b==i || b==k) bCnt++;
                        if(c==i || c==j) bCnt++;

                        if(ball!=bCnt) arr[i][j][k]=false;
                    }
                }
            }
        }
    }

    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            for(int k=1;k<=9;k++) {
                if(i!=j && j!=k && i!=k) {
                    if(arr[i][j][k]) answer++;
                }
            }
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> baseball={{123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1}};

    int result=solution(baseball);
    printf("%d\n",result);

    return 0;
}