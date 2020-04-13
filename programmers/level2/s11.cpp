// 문자열 압축
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = s.length();

    int size=s.length();

    if(size==1) return 1;

    // s   aabbaccc (8)
    // i   3
    // j   2
    // s1  bac
    // s2  cc
    // rs  aabbac
    // cnt 1 
    for(int i=1;i<=size/2;i++) {
        string s1=s.substr(0,i);    // 0번째에서 i개 만큼의 문자열
        string rs="";
        int cnt=1;

        for(int j=i;j<size;j+=i) {
            string s2=s.substr(j,i);

            if(s1==s2) {
                cnt++;
            } else {
                if(cnt<=1) rs+=s1;
                else rs=rs+to_string(cnt)+s1;
                s1=s2;
                cnt=1;
            }

            if(j+i>=size) {
                if(cnt<=1) rs+=s.substr(j);
                else rs=rs+to_string(cnt)+s1;
            }
        }
        int len=rs.length();
        answer=min(answer,len);
    }

    return answer;
}

int main() {
    string s="aabbaccc";
    int result=solution(s);

    printf("%d\n",result);

    return 0;
}