// N개의 최소공배수
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

// GCD(a,b) = GCD(b, b%a)
int lcm(int n,int m) {
    int a=n,b=m;

    while(1) {
        int atmp=a;
        int btmp=b;
        a=b;
        b=atmp%btmp;
        
        if(b==0) break;
    }
    return n*m/a;
}

int solution(vector<int> arr) {
    int answer = 0;

    // 2 6 8 14
    // 2 6
    //   6 8 14
    for(int i=0;i<arr.size()-1;i++) {
        arr[i+1]=lcm(arr[i],arr[i+1]);
    }
    answer=arr[arr.size()-1];

    return answer;
}

int main() {

    vector<int> arr={2,6,8,14};
    int result=solution(arr);
    printf("%d\n",result);

    return 0;
}