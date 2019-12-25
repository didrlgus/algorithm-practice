// 같은 숫자는 싫어
#include <vector>
#include <cstdio>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for(int i=0;i<arr.size()-1;i++) {
        int a = arr[i], b= arr[i+1];
        
        if(a!=b) answer.push_back(b);
    }

    return answer;
}

int main() {
    vector<int> arr, answer;

    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);

    answer = solution(arr);

    for(int i=0;i<answer.size();i++) 
        printf("%d ",answer[i]);

    return 0;
}