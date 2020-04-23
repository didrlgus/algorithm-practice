// 타겟 넘버
#include <string>
#include <vector>

using namespace std;

int n,t;
int cnt=0;

void dfs(int current,int sum,vector<int> numbers) {
    if(current>=n) {
        if(sum==t) cnt++;
    } else {
        dfs(current+1,sum+numbers[current],numbers);
        dfs(current+1,sum-numbers[current],numbers);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    n=numbers.size();
    t=target;

    dfs(0,0,numbers);
    answer=cnt;
    
    return answer;
}

int main() {

    vector<int> numbers={1,1,1,1,1};
    int target=3;

    int result=solution(numbers,target);
    printf("%d\n",result);

    return 0;
}