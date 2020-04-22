// [3차] 압축
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> m;

    for(int i=1;i<=26;i++) {
        string s;
        s+='A'+(i-1);
        m.insert({s,i});
    }
    
    int num=27;
    int idx=0;
      
    // msg      K   A   K   A   O
    //              i
    //              ix
    //   s     K A
    // map ... KA(27), 
    // ans 11 
    for(int i=0;i<msg.size();) {
        string s="";
        idx=i;
        s+=msg[idx];

        while(true) {
            if(m.find(s)!=m.end()) {
                s+=msg[++idx];
            } else {
                m.insert({s,num++});
                s.pop_back();
                i+=s.size();            // i값을 map에 일치하는 문자열의 길이만큼 더함
                answer.push_back(m.find(s)->second);
                break;
            }
        }
    }

    return answer;
}

int main() {

    string msg="KAKAO";
    vector<int> result=solution(msg);

    for(int i=0;i<result.size();i++) printf("%d ",result[i]);

    return 0;
}