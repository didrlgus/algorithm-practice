// 크레인 인형뽑기 게임
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int len=board.size();
    stack<int> s;

    for(int i=0;i<moves.size();i++) {
        int col=moves[i]-1;

        int idx=0;

        while(idx<len) {
            if(!board[idx][col]) {
                idx++;
                continue;
            }

            if(s.empty()) s.push(board[idx][col]);
            else {
                int t=s.top();

                if(t==board[idx][col]) {
                    s.pop();
                    answer+=2;
                } else {
                    s.push(board[idx][col]);
                }
            }

            board[idx][col]=0;
            break;
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> board={{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves={1,5,3,5,1,2,1,4}; 

    int result=solution(board,moves);

    printf("%d\n",result);

    return 0;
}