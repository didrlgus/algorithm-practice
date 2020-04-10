// 다트게임
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> v;
    int idx=0;

    for(int i=0;i<dartResult.size();i++) {
        char c=dartResult.at(i);

        if(c=='S'){}
        else if(c=='D') {
            v[idx-1]=pow(v[idx-1],2);
        } else if(c=='T') {
            v[idx-1]=pow(v[idx-1],3);
        } else if(c=='*') {
            if(idx==1) {
                v[idx-1]*=2;
            } else {
                v[idx-2]*=2;
                v[idx-1]*=2;
            }
        } else if(c=='#') {
            v[idx-1]*=-1;
        } else {
            if(c=='1' && dartResult.at(i+1)=='0') {
                v.push_back(10);
                i++;
            } else {
                v.push_back(c-'0');
            }
            idx++;
        }
    }

    for(int i=0;i<v.size();i++) {
        answer+=v[i];
    }
    return answer;
}

int main() {
    string dartResult="1S2D*3T";

    int result=solution(dartResult);

    printf("%d\n",result);

    return 0;
}