// 저울
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> weight) {
    int answer=1;

    sort(weight.begin(),weight.end());

    for(int i=0;i<weight.size();i++) {
        if(weight[i]>answer) break;
        else answer+=weight[i];
    }

    return answer;
}

int main() {

    vector<int> weight={3, 1, 6, 2, 7, 30, 1};
    int result=solution(weight);
    printf("%d\n",result);

    return 0;
}