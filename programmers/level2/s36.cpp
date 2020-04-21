// [1차] 프렌즈4블록
#include <string>
#include <vector>

using namespace std;

bool charChk(char c1,char c2) {
    if(isupper(c1) && isupper(c2) && c1==c2) {               // 둘 다 대문자
        return true;
    } else if(islower(c1) && isupper(c2) && c1==c2+32) {     // c1 소문자, c2 대문자
        return true;
    } else if(isupper(c1) && islower(c2) && c1+32==c2) {     // c1 대문자, c2 소문자
        return true;
    } else if(islower(c1) && islower(c2) && c1==c2) {        // 둘다 소문자
        return true;
    } else return false;
}

int solution(int n, int m, vector<string> board) {
    int answer = 0;
    
    do {
        bool flag=false;
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<m-1;j++) {
                if(charChk(board[i][j],board[i][j+1]) && charChk(board[i][j],board[i+1][j]) 
                        && charChk(board[i][j],board[i+1][j+1])) {
                    if(isupper(board[i][j])) {board[i][j]+=32; answer++; flag=true;}
                    if(isupper(board[i][j+1])) {board[i][j+1]+=32; answer++; flag=true;}
                    if(isupper(board[i+1][j])) {board[i+1][j]+=32; answer++; flag=true;}
                    if(isupper(board[i+1][j+1])) {board[i+1][j+1]+=32; answer++; flag=true;}
                }
            }
        }

        if(flag) {
            for(int i=0;i<m;i++) {
                for(int j=n-2;j>=0;j--) {
                    for(int k=j;k<n-1;k++) {
                        if(board[k+1][i]==' ' || islower(board[k+1][i])) {
                            board[k+1][i]=board[k][i];
                            board[k][i]=' ';
                        } else break;
                    }
                }
            }
        } else break;
    } while(true);

    return answer;
}

int main() {

    int n=4,m=5;
    vector<string> board={"CCBDE","AAADE","AAABF","CCBBF"};

    int result=solution(n,m,board);
    printf("%d\n",result);
    
    return 0;
}