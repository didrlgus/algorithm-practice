#include <string>
#include <vector>

using namespace std;

int a[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i=0;i<reserve.size();i++) a[reserve[i]]=1;
    
    for(int i=0;i<lost.size();i++) a[lost[i]]--;
    
    for(int i=0;i<lost.size();i++) {
        if(a[lost[i]]==-1 && a[lost[i]-1]>=1) {
            a[lost[i]]++;
            a[lost[i]-1]--;
        } else if (a[lost[i]]==-1 && a[lost[i]+1]>=1) {
            a[lost[i]]++;
            a[lost[i]+1]--;
        }
    }
    
    for(int i=1;i<=n;i++) {
        if(a[i]>=0) answer++;
    }
    
    return answer;
}

int main() {

    int n=5;
    vector<int> lost = {2,4};
    vector<int> reserve = {1,3,5};

    int result = solution(n,lost,reserve);

    printf("%d\n",result);

    return 0;
}