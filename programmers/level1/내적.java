// 내적
class Solution {
    public int solution(int[] a, int[] b) {
        int answer = 0;
        
        int N = a.length;
        
        for (int i = 0; i < N; i++) {
            answer += a[i] * b[i];
        }
        
        return answer;
    }
}