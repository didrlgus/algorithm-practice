// 외벽 점검
#include<bits/stdc++.h>

using namespace std;

#include <string>
#include <vector>

using namespace std;

const int INF=987987987;

vector<int> changeStart(int start,int n,vector<int> weak) {
    vector<int> _weak;
    // start -> weak.size-1 까지 그대로
    for(int i=start;i<weak.size();i++) {
        _weak.push_back(weak[i]);
    }
    // 0 -> start-1 까지 weak[i]+n  (원형이기 때문)
    for(int i=0;i<start;i++) {
        _weak.push_back(weak[i]+n);
    }
    return _weak;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer=INF;

    do {
        for(int i=0;i<weak.size();i++) {
            vector<int> _weak=changeStart(i,n,weak);
            
            bool flag=false;
            int curr=_weak[0]+dist[0];
            int idx=0;
            for(int j=1;j<_weak.size();j++) {
                if(curr<_weak[j]) {
                    if(idx+1==dist.size()) {    // 취약지점을 모두 검사할 수 없는경우
                        flag=true;
                        break;
                    }
                    curr=_weak[j]+dist[++idx];
                }
            }
            if(!flag) answer=min(answer,idx+1);
        }
    } while(next_permutation(dist.begin(),dist.end()));

    if(answer==INF) return -1;

    return answer;
}

int main() {

    int n=12;
    vector<int> weak={1, 5, 6, 10}, dist={1, 2, 3, 4};
    int result=solution(n,weak,dist);
    printf("%d\n",result);

    return 0;
}