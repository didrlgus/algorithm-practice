// k번째수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++) {
        vector<int> v;
        
        int s=commands[i][0];
        int e=commands[i][1];
        int k=commands[i][2];
        
        for(int j=s-1;j<=e-1;j++) v.push_back(array[j]);
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[k-1]);
    }
    
    return answer;
}

int main() {

    vector<int> array = {1,5,2,6,3,7,4};
    vector<vector<int>> commands = {{2,5,3},{4,4,1},{1,7,3}};

    vector<int> result = solution(array, commands);

    for(int i=0;i<result.size();i++) printf("%d ", result[i]);

    return 0;
}