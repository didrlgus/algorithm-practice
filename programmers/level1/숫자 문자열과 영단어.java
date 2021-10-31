// 숫자 문자열과 영단어
import java.util.*;

class Solution {
    
    Map<String, Integer> map = new HashMap<>();
    String[] arr = new String[]{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    public int solution(String s) {
        int answer = 0;
        StringBuilder ret = new StringBuilder();
        
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], i);
        }
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                StringBuilder prefix_num = new StringBuilder();
                prefix_num.append(ch).append(s.charAt(i + 1)).append(s.charAt(i + 2));
                for (Map.Entry<String, Integer> entry : map.entrySet()) {
                    String key = entry.getKey();
                    if (key.contains(prefix_num)) {
                        ret.append(entry.getValue());
                        i += key.length() - 1;
                        break;
                    }
                }
            } else {
                ret.append(ch);
            }
        }
        
        answer = Integer.parseInt(ret.toString());
        
        return answer;
    }
}