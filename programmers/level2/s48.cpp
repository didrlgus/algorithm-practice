// 소수 만들기
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x) {
  
  if(x==1) return false;
  if(x==2 || x==3) return true;
  
  for(int i=2;i<=sqrt(x);i++) {
    if(x%i==0) return false;
  }
  
  return true;
}

int cnt=0;
bool checked[60];
int result[3];
int idx=0;

// 재귀로 풀어보기
void func(int current,vector<int> nums) {
    if(current>=3) {
        int sum=0;
        for(int i=0;i<current;i++) sum+=result[i];

        if(isPrime(sum)) cnt++;
    } else {
        for(int i=idx;i<nums.size();i++) {
            if(!checked[i]) {
                checked[i]=true;
                result[current]=nums[i];
                idx=i+1;                        // idx 따로 빼서 새어주기 (176, 167은 동일하기 때문)

                func(current+1,nums);

                checked[i]=false;
                result[current]=0;
            }
        }
    }
}

int solution(vector<int> nums) {
    int answer = -1;

    func(0,nums);
    answer=cnt;

    return answer;
}

int main() {
    
    vector<int> nums={1,2,7,6,4};
    int result=solution(nums);
    cout<<result<<endl;

    return 0;
}