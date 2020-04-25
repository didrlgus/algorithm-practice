// N으로 표현
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int a[10];
int min_=987987987;
bool flag=false;

void dfs(int current,int result,int number) {
    if(current>8) return;
    else if(result==number) {
        flag=true;
        if(current<min_) {
            min_=current;
        }
    } else {
        for(int i=0;i<8;i++) {
            int count=i+1;

            // +,-,*,/
            dfs(current+count,result+a[i],number);
            dfs(current+count,result-a[i],number);
            dfs(current+count,result*a[i],number);
            dfs(current+count,result/a[i],number);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    
    a[0]=1*N;
    for(int i=1;i<8;i++) a[i]=a[i-1]*10+(1*N);      // 5, 55, 555, 5555, 55555, 555555, 5555555, 55555555
    
    dfs(0,0,number);

    if(flag) answer=min_;
    else answer=-1;

    return answer;
}

int main() {

    int N=5, number=12;
    int result=solution(N,number);
    printf("%d\n",result);

    return 0;
}