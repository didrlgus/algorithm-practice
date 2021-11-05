// 없는 숫자 더하기
class Solution {
    
    boolean[] check = new boolean[10];
    
    public int solution(int[] numbers) {
        int answer = 0;
        
        int N = numbers.length;
        
        for (int i = 0; i < N; i++) {
            check[numbers[i]] = true;
        }
        
        for (int i = 0; i < 10; i++) {
            if (!check[i]) {
                answer += i;
            }
        }
        
        return answer;
    }
}