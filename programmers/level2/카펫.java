class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
            
        int sum = brown + yellow;
        
        int ret_width = -1, ret_height = -1;
        
        for (int i = 1; i <= Math.sqrt(yellow); i++) {
            if (yellow % i != 0) {
                continue;
            }
            
            int width = yellow / i + 2;
            int height = i + 2;
            
            if (sum == width * height) {
                ret_width = width;
                ret_height = height;
                break;
            }
        }
        
        answer[0] = ret_width;
        answer[1] = ret_height;
        
        return answer;
    }
}