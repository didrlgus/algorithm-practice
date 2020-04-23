// 종이접기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    if(n==1) {
        answer.push_back(0);
        return answer;
    }

    vector<string> v(25);
    v[1]+='0';

    for(int i=2;i<=n;i++) {
        v[i]=v[i-1]+'0';

        for(int j=v[i].size()-2;j>=0;j--) {
            if(v[i].at(j)=='0') v[i]+='1';
            else v[i]+='0';
        }
    }

    for(int i=0;i<v[n].size();i++) answer.push_back(v[n].at(i)-'0');

    return answer;
}

int main() {

    int n=4;
    vector<int> result=solution(4);
    for(int i=0;i<result.size();i++) printf("%d ",result[i]);

    return 0;
}