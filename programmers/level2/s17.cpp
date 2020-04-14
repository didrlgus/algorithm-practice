// H-Index
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end());
    
    for(int i=0;i<=10000;i++) {
        int h=0;

        for(int j=0;j<citations.size();j++) {
            if(citations[j]>=i) h++;
        }

        if(h<=i) answer=max(answer,h);
    }

    return answer;
}

int main() {

    vector<int> citations={5,5,5,5,1};

    int result=solution(citations);
    printf("%d\n",result);

    return 0;
}