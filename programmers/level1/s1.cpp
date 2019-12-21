// 문자열 압축
#include <string>
#include <vector>

using namespace std;

int calcLength(int unit, int len, int cnt) {
    if(cnt==1) return unit+len;
        
    while(cnt / 10 > 0) {   // 숫자의 자리수 세는 방법. len에서 +1 해주면 원하는 자리수를 셀 수 있음
        cnt /= 10;
        len++;
    }
    
    return unit+len+1;
}

int solution(string s) {
    int answer = 0;
    
    int size = s.size();
    answer=size;
    
    if (size==1) return 1;
    
    for(int i=1;i<=size/2;i++) {    // 단위는 문자열 길이의 /2 까지만 계산해주면 됨
        int len=0,cnt=1;
        string before = s.substr(0,i);    
        
        for(int j=i; j+i<=size; j+=i) {
            string now = s.substr(j,i);
            
            if(before == now) {
                cnt++;
            } else {
                len = calcLength(i, len, cnt);
                if(cnt>1) cnt=1;
                before=now;
            }
        }
        
        len = calcLength(i, len, cnt);

        len += size % i;
        
        if(answer>len) answer=len;
    }
    
    return answer;
}

int main() {
    
    string s = "abcabcabcabcdededededede";

    printf("%d\n",solution(s));

    return 0;
}