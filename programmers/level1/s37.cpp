// 행렬의 덧셈
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr1.front().size(),0));
    
    for(int i=0;i<arr1.front().size();i++) {
        for(int j=0;j<arr1.size();j++) {
            answer[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    
    return answer;
}

int main() {

    vector<vector<int>> arr1={{1,2},{2,3}},arr2={{3,4},{5,6}};
    vector<vector<int>> result=solution(arr1,arr2);

    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result.front().size();j++) {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}