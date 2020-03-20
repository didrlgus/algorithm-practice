// 제일 작은 수 제거하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size()==1) {
        answer.push_back(-1);
        return answer;
    }

    int min = 987987987;

    for(int i=0;i<arr.size();i++) {
        if(arr[i]<min) min = arr[i];
    }
    
    for(int i=0;i<arr.size();i++) {
        if(arr[i]!=min) answer.push_back(arr[i]);
    }

    return answer;
}

int main() {
    vector<int> arr = {4,3,2,1};
    vector<int> v = solution(arr);

    for(int i=0;i<v.size();i++) {
        printf("%d ", v[i]);
    }

    return 0;
}