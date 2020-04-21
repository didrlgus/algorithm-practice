// [1차] 캐시
#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<string> dq;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if(cacheSize==0) {
        answer=cities.size()*5;
        return answer;
    }

    for(int i=0;i<cities.size();i++) {
        for(int j=0;j<cities[i].size();j++) {
            cities[i].at(j)=tolower(cities[i].at(j));
        }
    }
    // "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"
    // 캐시 채우기
    int idx=0;
    for(int i=0;i<cities.size();i++) {
        string s=cities[i];
        bool flag=false;
        
        for(int j=0;j<dq.size();j++) {
            if(s==dq[j]) {                  // 캐시 hit
                dq.erase(dq.begin()+j);
                dq.push_back(s);
                answer+=1;
                flag=true;
                break;
            }
        }

        if(!flag) {                         // 캐시 miss
            if(dq.size()<cacheSize) dq.push_back(s);
            else {
                dq.pop_front();
                dq.push_back(s);
            }
            answer+=5;
        }
    }

    return answer;
}

int main() {

    int cacheSize=3;
    vector<string> cities={"Jeju", "Jeju", "Jeju", "Jeju", "Jeju", "Jeju", "Jeju", "Jeju", "Jeju"};

    int result=solution(cacheSize,cities);
    printf("%d\n",result);

    return 0;
}