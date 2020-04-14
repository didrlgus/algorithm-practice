// 소수찾기
#include <string>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int a[1000010];
char b[10];
bool check[10];
int r[10];
int len;
int cnt;

bool numChk[10000010];

bool isPrime(int x) {
  
  if(x==0 || x==1) return false;
  if(x==2 || x==3) return true;
  
  for(int i=2;i<=sqrt(x);i++) {
    if(x%i==0) return false;
  }
  
  return true;
}

void func(int current,int n) {
    // base condition
    if(current>=n) {
        int num=0;
        int p=0;
        // 0 1 1
        for(int i=n-1;i>=0;i--) {
            num+=r[i]*pow(10,p++);
        }

        if(!numChk[num]) {
            numChk[num]=true;
            if(isPrime(num)) cnt++;
        }
    } else {
        for(int i=0;i<len;i++) {
            if(!check[i]) {
                check[i]=true;
                r[current]=b[i]-'0';

                func(current+1,n);

                check[i]=false;
                r[current]=0;
            }
        }
    }
}

int solution(string numbers) {
    len=numbers.size();

    for(int i=0;i<len;i++) b[i]=numbers.at(i);
    
    for(int i=1;i<=len;i++) {
        func(0,i);
    }

    return cnt;
}

int main() {

    int reuslt=solution("011");
    printf("%d\n",reuslt);

    return 0;
}