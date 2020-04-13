// 큰 수 만들기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int idx=0;
    int o=k;

    while(answer.length()<number.length()-o) {
        char max='+';
        int m=0;
        // number  1 2 3 1 2 3 4
        //                   i
        //                   k
        //                 m
        // max     2
        // ans     3
        for(int i=idx;i<=k;i++) {
            if(max<number.at(i)) {
                max=number.at(i);
                m=i;
            }
        }

        idx=m+1;
        k++;

        answer+=max;
    }

    return answer;
}

int main() {

    string result=solution("1231234",3);

    cout<<result<<endl;

    return 0;
}