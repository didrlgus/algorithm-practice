// 키패드 누르기
#include<bits/stdc++.h>
using namespace std;
struct p {
    int y,x;
};
int left_cur_y=3,left_cur_x=0,right_cur_y=3,right_cur_x=2;
vector<p> v;
string solution(vector<int> numbers,string hand) {
    string answer="";
    v.push_back({3,1});
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) v.push_back({i,j});
    }
    for(auto it:numbers) {
        if(it==1||it==4||it==7) {
            left_cur_y = v[it].y;
            left_cur_x = v[it].x;
            answer+='L';
        } else if(it==3||it==6||it==9) {
            right_cur_y=v[it].y;
            right_cur_x=v[it].x;
            answer+='R';
        } else {
            int cur_y=v[it].y,cur_x=v[it].x;
            int left_diff=abs(left_cur_y-cur_y)+abs(left_cur_x-cur_x);
            int right_diff=abs(right_cur_y-cur_y)+abs(right_cur_x-cur_x);
            if (left_diff>right_diff) {
                right_cur_y=cur_y;
                right_cur_x=cur_x;
                answer+='R';
            } else if(left_diff<right_diff) {
                left_cur_y=cur_y;
                left_cur_x=cur_x;
                answer+='L';
            } else {
                if(hand=="left") {
                    left_cur_y=cur_y;
                    left_cur_x=cur_x;
                    answer+='L';
                } else {
                    right_cur_y=cur_y;
                    right_cur_x=cur_x;
                    answer+='R';
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<int> numbers={1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand="right";
    string ret=solution(numbers,hand);
    cout<<ret<<'\n';
    return 0;
}