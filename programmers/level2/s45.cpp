// 위장
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;

    for(int i=0;i<clothes.size();i++) {
        string s=clothes[i][1];

        if(m.find(s)==m.end()) {        // 요소가 존재하지 않을 경우
            m.insert({s,1});
        } else {
            m[s]+=1;
        }
    }

    vector<int> v;
    
    for(auto iter:m) {
        v.push_back(iter.second);
    }

    for(int i=0;i<v.size();i++) {
        answer*=(v[i]+1);           // 종류마다 -> 옷을 입는 가지수 (v[i]) + 입지 않는경우 (1)
    }

    answer--; // 옷을 아예입지 않는 경우 -1

    return answer;
}

int main() {

    vector<vector<string>> clothes={{"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},
            {"green_turban", "headgear"}};

    int result=solution(clothes);
    printf("%d\n",result);

    return 0;
}