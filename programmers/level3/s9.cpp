// 예산
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;

    sort(budgets.begin(),budgets.end());
    
    long long sum_=0;
    for(int i=0;i<budgets.size();i++) sum_+=budgets[i];

    if(sum_<=M) return budgets.back(); 

    int s=1,e=budgets.back();

    // 이진탐색
    while(s+1<e) {
        int m=(s+e)/2;
        
        long long sum=0;
        for(int i=0;i<budgets.size();i++) {
            int a;
            a=budgets[i]>=m ? m : budgets[i];
            sum+=a;
        }

        if(sum==M) return m;
        else if(sum>M) e=m;
        else s=m;
    }

    answer=s;
    return answer;
}

int main() {

    vector<int> budgets={120, 110, 140, 150};
    int M=485;

    int result=solution(budgets,M);
    printf("%d\n",result);

    return 0;
}