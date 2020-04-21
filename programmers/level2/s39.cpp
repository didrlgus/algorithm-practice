// 후보키
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rSize,cSize;
vector<int> v;

int bitCnt(int n) {
    int cnt=0;
    
    while(n) {
        if(n&1) cnt++;
        n=n>>1;
    }
    return cnt;
}

bool cmp(int a, int b) {
    int cnt1=bitCnt(a);
    int cnt2=bitCnt(b);

    return cnt1>cnt2;	// 내림차순
}

bool check(vector<vector<string>> relation,int subset) {
    for(int i=0;i<rSize-1;i++) {
        for(int j=i+1;j<rSize;j++) {
            bool flag=false;

            for(int k=0;k<cSize;k++) {
                if(!(subset & 1<<k)) continue;
                if(relation[i][k]!=relation[j][k]) {
                    flag=true;
                    break;
                }
            }

            if(!flag) return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    rSize=relation.size();
    cSize=relation.front().size();

    for(int i=1;i<(1<<cSize);i++) {
        if(check(relation,i)) v.push_back(i);
    }
    
    sort(v.begin(),v.end(),cmp);

    while(!v.empty()) {
        int b=v.back();
        v.pop_back();
        answer++;

        for(auto it=v.begin();it!=v.end();) {
            if((b&*it)==b) {
                it=v.erase(it);
            } else it++;
        }
    }

    return answer;
}

int main() {

    vector<vector<string>> relation=
         {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},
          {"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};

    int result=solution(relation);
    printf("%d\n",result);

    return 0;
}