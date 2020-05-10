// 하노이의 탑
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void func(int n,int start,int end) {
    if(n==0) return;
    
    int mid=6-start-end;        // 막대가 1,2,3 있으므로 모두 더한 값(6)에서 start와 end막대 2개를 빼주면 나머지 하나가 나옴.
    func(n-1,start,mid);
    answer.push_back({start,end});
    func(n-1,mid,end);
}

vector<vector<int>> solution(int n) {
    
    func(n,1,3);

    return answer;
}

int main() {

    int n=3;
    vector<vector<int>> result=solution(n);
    for(auto iter:result) {
        for(auto iter2:iter) printf("%d ",iter2);
        printf("\n");
    }

    return 0;
}