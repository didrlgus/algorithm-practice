// 최대공약수와 최소공배수
#include <string>
#include <vector>

using namespace std;

int gcd(int n,int m) {
    int a=n;
    int b=m;
    
    while(1) {
        int atmp=a;
        int btmp=b;
        
        a=b;
        b=atmp%btmp;
        
        if(b==0) break;
    }

    return a;
}

int lcm(int n,int m,int a) {
    return n*m/a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    int a=gcd(n,m);
    int b=lcm(n,m,a);
    answer.push_back(a);
    answer.push_back(b);

    return answer;
}

int main() {

    vector<int> result=solution(3,12);
    for(int i=0;i<result.size();i++) printf("%d ",result[i]);

    return 0;
}