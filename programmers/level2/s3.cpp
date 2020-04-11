// 주식가격
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    // 1, 2, 3, 3, 2
    //       i     j
    // 1
    //    
    for(int i=0;i<prices.size()-1;i++) {
        int t=0;
        bool flag=false;

        for(int j=i+1;j<prices.size();j++) {
            if(prices[i]>prices[j]) {
                answer.push_back(t+1);
                flag=true;
                break;
            }
            t++;
        }
        if(flag) continue;
        else answer.push_back(t);
    }

    answer.push_back(0);

    return answer;
}

int main() {
    vector<int> prices={1, 2, 3, 2, 3};

    vector<int> answer=solution(prices);

    for(int i=0;i<answer.size();i++) printf("%d ",answer[i]);
    
    return 0;
}