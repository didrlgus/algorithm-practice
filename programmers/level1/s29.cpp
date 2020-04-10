// 비밀지도
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

char map1[20][20];
char map2[20][20];

void func(int n,vector<int> arr,char map[][20]) {
    for(int i=0;i<n;i++) {
        int num=arr[i];
        stack<int> s;

        if(num==0) {
            s.push(0);
        } else {
            while(num>0) {
                s.push(num%2);
                num/=2;
            }
        }

        int size=s.size();
        if(s.size()<n) {
            for(int j=0;j<n-size;j++) s.push(0);
        }

        for(int j=0;j<n;j++) {
            int t=s.top();
            s.pop();

            if(t==1) map[i][j]='#';
            else map[i][j]='0';
        }
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    func(n,arr1,map1);
    func(n,arr2,map2);

    for(int i=0;i<n;i++) {
        string s;
        for(int j=0;j<n;j++) {
            if(map1[i][j]=='#' || map2[i][j]=='#') s.append("#");
            else s.append(" ");
        }
        answer.push_back(s);
    }

    return answer;
}

int main() {
    vector<int> arr1={9, 20, 28, 18, 11};
    vector<int> arr2={30, 1, 21, 17, 28};

    vector<string> answer=solution(5,arr1,arr2);

    for(int i=0;i<answer.size();i++) cout << answer[i] << endl;

    return 0;
}