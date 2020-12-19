#include<bits/stdc++.h>
using namespace std;
struct fish {
    int size,dir;
};
int n;
stack<fish> stk;
int solution(vector<int> &A, vector<int> &B) {
    n=(int)A.size();
    stk.push({A[0],B[0]});
    for(int i=1;i<n;i++) {
        int cur_size=A[i],cur_dir=B[i];
        while(!stk.empty()) {
            fish front_fish=stk.top();
            if(front_fish.dir==1&&cur_dir==0) {
                if(front_fish.size<cur_size) {
                    stk.pop();
                } else {
                    break;
                }
            } else {
                stk.push({cur_size,cur_dir});
                break;
            }
        }
        if(stk.empty()) stk.push({cur_size,cur_dir});
    }
    return (int)stk.size();
}