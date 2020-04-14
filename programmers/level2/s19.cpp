// 카펫
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    for(int i=1;i<=red;i++) {
        if(i>(red/i)) break;

        if(red%i==0) {
            int h,w;    // 세로, 가로
            h=i;
            w=red/i;

            if(brown==(h*2)+(w+2)*2) {
                answer.push_back(w+2);
                answer.push_back(h+2);
            }
        }
    }

    return answer;
}

int main() {

    vector<int> result=solution(24,24);
    printf("%d %d",result[0],result[1]);

    return 0;
}