// 가장 긴 팰린드롬
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int solution(string s) {
    int dp[2510][2510] = {0};
    int Max;
    
    // 길이 1
    for(int i = 0; i < s.size(); i++){
        dp[i][i] = 1;
        Max = 1;
    }
    
    // 길이 2
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            Max = 2;
        }
    }
    
    // 길이 3 이상
    for(int k = 2; k < s.size(); k++) {
        for(int i = 0; i <= s.size()-1-k; i++) {
            int j = i + k;
            
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                if(Max < k+1) {
                    Max = k+1;
                }
            }
        }
    }
 
    return Max;
}
