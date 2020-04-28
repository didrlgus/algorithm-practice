// 정수 삼각형
#include<bits/stdc++.h>

using namespace std;

int a[510][510];
int solution(vector<vector<int>> triangle) {
    int answer = -1;
    
    a[0][0]=triangle[0][0];

    if(triangle.size()<=1) return triangle[0][0];

    for(int i=0;i<triangle.size()-1;i++) {
        for(int j=0;j<triangle[i+1].size();j++) {
            if(j==0) {
                a[i+1][j]=a[i][j]+triangle[i+1][j];
            } else if(j==triangle[i+1].size()-1) {
                a[i+1][j]=a[i][j-1]+triangle[i+1][j];
            } else {
                a[i+1][j]=max(a[i][j-1]+triangle[i+1][j], a[i][j]+triangle[i+1][j]);
            }
        }
    }

    for(int i=0;i<triangle[triangle.size()-1].size();i++) {
        if(answer<a[triangle.size()-1][i]) answer=a[triangle.size()-1][i];
    }

    return answer;
}

int main() {

    vector<vector<int>> triangle={{7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5}};
    int result=solution(triangle);
    printf("%d\n",result);

    return 0;
}