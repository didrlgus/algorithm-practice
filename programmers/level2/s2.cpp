// 멀쩡한 사각형
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int c, int d) {
  int tmp;
  
  while(d>0) {
    tmp=c;
    
    c=d;
    d=tmp%d;
  }
  
  return c;
}

long long solution(int w,int h)
{
	long long answer = 1;
    int gcd = GCD(w, h);
    long long sum = (long long)w * (long long)h;

    long long cnt = ((w/gcd) + (h/gcd) - 1) * gcd;

    answer = sum - cnt;

	return answer;
}

int main() {

    long long s = solution(8, 12);
    printf("%lld", s);

    return 0;
}