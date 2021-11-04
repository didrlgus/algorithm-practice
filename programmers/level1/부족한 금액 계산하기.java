// 부족한 금액 계산하기
class Solution {
    public long solution(int price, int money, int count) {
        long answer = -1;
        
        long sum = price;
        
        for (int i = 1; i < count; i++) {
            sum += price * (i + 1);
        }
        
        long diff = money - sum;
        
        if (diff >= 0) {
            answer = 0;
        } else {
            answer = Math.abs(diff);
        }
        
        return answer;
    }
}