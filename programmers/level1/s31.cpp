// 다트게임
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int solution(string dartResult) {
    int answer=0;
    for(int i=0;i<(int)dartResult.size();i++) {
        if(dartResult[i]>='0'&&dartResult[i]<='9') {
            string num_str="";
            while(dartResult[i]>='0'&&dartResult[i]<='9') {
                num_str+=dartResult[i];
                i++;
            }
            v.push_back(stoi(num_str.c_str()));
            i--;
            continue;
        }
        if(dartResult[i]=='S'||dartResult[i]=='D'||dartResult[i]=='T') {
            if(dartResult[i]=='D') v.back()=pow(v.back(),2);
            if(dartResult[i]=='T') v.back()=pow(v.back(),3);
            continue;
        }
        if(dartResult[i]=='*'||dartResult[i]=='#') {
            int len=(int)v.size();
            if(dartResult[i]=='*') {
                if(len==1) {
                    v[len-1]*=2;
                } else {
                    v[len-1]*=2;
                    v[len-2]*=2;
                }
            } else {
                v[len-1]*=-1;
            }
        }
    }
    for(auto it:v) answer+=it;
    return answer;
}
int main() {
    string dartResult="1S2D*3T";
    int result=solution(dartResult);
    printf("%d\n",result);
    return 0;
}