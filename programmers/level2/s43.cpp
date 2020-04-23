// [3차] n진수 게임
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> func(int n,int t,int m) {
    vector<char> cv;

    for(int i=0;i<t*m;i++) {
        vector<int> v;
        int a=i;

        if(a==0) v.push_back(a);
        while(a) {
            v.push_back(a%n);
            a/=n;
        }

        for(int j=v.size()-1;j>=0;j--) {
            if(v[j]>=10) {
                char c= v[j]-10+'A';
                cv.push_back(c);
            } else {
                cv.push_back(v[j]+'0');
            }
        }

        if(cv.size()>=t*m) break;
    }
    return cv;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    vector<char> cv=func(n,t,m);

    int idx=0;
    while(answer.size()<t) {
        if((idx%m)+1==p) answer+=cv[idx];
        idx++;
    }

    return answer;
}

int main() {

    int n=2,t=4,m=2,p=1;
    string result=solution(n,t,m,p);
    cout<<result<<endl;

    return 0;
}