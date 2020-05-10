// 최고의 집합
#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int a=s/n;
    int b=s%n;

    if(a==0) {
        answer.push_back(-1);
        return answer;
    }

    for(int i=0;i<n;i++) answer.push_back(a);
    for(int i=answer.size()-1;i>=answer.size()-b;i--) answer[i]++;

    return answer;
}

int main() {

    int n=5,s=9;
    vector<int> result=solution(n,s);
    for(auto iter:result) printf("%d ",iter);

    return 0;
}