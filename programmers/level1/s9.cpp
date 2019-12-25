// 나누어 떨어지는 숫자 배열
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++)
        if(arr[i]%divisor==0) answer.push_back(arr[i]);
    
    if(answer.size()<=0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}

int main() {

    vector<int> arr;
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(10);

    vector<int> result = solution(arr, 5);

    for(int i=0;i<result.size();i++) printf("%d ", result[i]);

    return 0;
}