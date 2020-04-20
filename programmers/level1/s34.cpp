// 평균 구하기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    int sum=0;
    for(int i=0;i<arr.size();i++) sum+=arr[i]; 

    answer=(double)sum/arr.size();

    return answer;
}

int main() {

    vector<int> arr={1,2,3,4};
    double result=solution(arr);

    cout<<result<<endl;

    return 0;
}