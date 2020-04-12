// 탑
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.push_back(0);

    // 3 9 9 3 5 7 2
    //       i
    //     j
    for(int i=1;i<heights.size();i++) {
        bool flag=false;
        for(int j=i-1;j>=0;j--) {
            if(heights[i]<heights[j]) {
                answer.push_back(j+1);
                flag=true;
                break;
            }
        }
        if(!flag) answer.push_back(0);
    }

    return answer;
}

int main() {
    vector<int> heights={3,9,9,3,5,7,2};

    vector<int> v=solution(heights);

    for(int i=0;i<v.size();i++) printf("%d ",v[i]);

    return 0;
}