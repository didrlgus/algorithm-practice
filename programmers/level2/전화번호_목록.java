import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        List<String> sortedPhoneNum = Arrays.stream(phone_book).sorted().collect(Collectors.toList());
        
        for (int i = 0; i < sortedPhoneNum.size() - 1; i++) {
            String a = sortedPhoneNum.get
(i), b = sortedPhoneNum.get(i+1);
            if (b.startsWith(a)) {
                answer = false;
                break;
            }
        }
        
        return answer;
    }
}