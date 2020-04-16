// 행렬의 곱셈
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.assign(arr1.size(), vector<int>(arr2[0].size(), 0));

    for(int i=0;i<arr1.size();i++) {
        for(int j=0;j<arr1[0].size();j++) {
            for(int k=0;k<arr2[0].size();k++) {
                answer[i][k]+=arr1[i][j]*arr2[j][k];
            }
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> arr1={{1, 4},{3, 2},{4, 1}};
    vector<vector<int>> arr2={{3, 3},{3, 3}};

    vector<vector<int>> answer=solution(arr1,arr2);

    for(int i=0;i<answer.size();i++) {
        for(int j=0;j<answer[i].size();j++) printf("%d ",answer[i][j]);
        printf("\n");
    }

    return 0;
}