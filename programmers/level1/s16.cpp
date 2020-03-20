// 소수 찾기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;

int number[1000005];

int solution(int n) {
  int answer=0;
  
  //2부터 n까지의 수를 배열에 넣는다.
  for(int i=2; i<=n; i++) {
    number[i] = i;
  }
          
  //2부터 시작해서 그의 배수들을 0으로 만든다.
  //후에 0이면 넘어가고 아니면 그의 배수들을 다시 0으로 만든다.
  for(int i=2; i<=n; i++) {
    if(number[i]==0) continue;
              
    for(int j= 2*i; j<=n; j += i) {
      number[j] = 0;
    }
  }
  
  for(int i=2; i<=n;i++) {
    if(number[i]!=0)answer++;
  }
  
  return answer;
}

int main() {

    int result = solution(10);

    cout << result << endl;

    return 0;
}