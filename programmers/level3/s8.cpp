// 디스크 컨트롤러
#include<bits/stdc++.h>

using namespace std;

struct p {
    int st,pt;      // 시작시간, 처리시간
};

bool cmp(p p1, p p2) {
    if(p1.pt==p2.pt) return p1.st<p2.st;
    return p1.pt<p2.pt;
}

vector<p> v;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    for(int i=0;i<jobs.size();i++) v.push_back({jobs[i][0],jobs[i][1]});
    
    sort(v.begin(),v.end(),cmp);

    int time=0,sum=0;
    while(!v.empty()) {
        bool flag=false;
        for(int i=0;i<v.size();i++) {
            if(time>=v[i].st) {
                time+=v[i].pt;
                sum+=time-v[i].st;

                v.erase(v.begin()+i);
                flag=true;
                break;
            }
        }

        if(!flag) time++;
    }

    answer=sum/jobs.size();

    return answer;
}

int main() {

    vector<vector<int>> jobs={{0,3},{1,9},{2,6}};
    int result=solution(jobs);
    printf("%d\n",result);

    return 0;
}