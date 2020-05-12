// 숫자 게임
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    int size1=A.size(), size2=B.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while(A.size()>0 && B.size()>0) {
      if(A[A.size()-1]>=B[B.size()-1]) {
        A.pop_back();
      }
      else {
        answer++;
        A.pop_back();
        B.pop_back();
      }
    }

    return answer;
}

int main() {

    vector<int> A={5,1,3,7},B={2,2,6,8};
    int result=solution(A,B);
    printf("%d\n",result);

    return 0;
}