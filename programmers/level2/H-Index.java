import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        int N = citations.length;
        
        Arrays.sort(citations);
        
        int mx = citations[N - 1];
        
        for (int i = 0; i <= mx; i++) {
            int idx = -1;
            for (int j = 0; j < N; j++) {
                if (i <= citations[j]) {
                    idx = j;
                    break;
                }
            }
            int more = N - idx;
            int less = N - more;
            if (more >= i && less <= i) {
                answer = i;
            } else {
                break;
            }
        }
        
        return answer;
    }
}