import java.util.*;

class Solution {
    
    private Set<Integer> set = new HashSet<>();
    private String str = "";
    private boolean[] check;

    public boolean isPrime(int x) {

        if (x == 0 || x == 1) {
            return false;
        }
        if (x == 2 || x == 3) {
            return true;
        }

        for (int i = 2; i <= Math.sqrt(x); i++) {
            if(x % i == 0) {
                return false;
            }
        }

        return true;
    }

    public void permu(int n, String numbers) {
        if (str.length() == n) {
            Integer num = Integer.parseInt(str);
            if (isPrime(num)) {
                set.add(num);
            }
            return;
        }
        for (int i = 0; i < numbers.length(); i++) {
            if (!check[i]) {
                check[i] = true;
                str += numbers.charAt(i);

                permu(n, numbers);

                check[i] = false;
                str = str.substring(0, str.length() - 1);
            }
        }
    }

    public int solution(String numbers) {
        int answer = 0;

        int N = numbers.length();

        for (int i = 1; i <= N; i++) {
            str = "";
            check = new boolean[N];
            permu(i, numbers);
        }

        answer = set.size();
        
        return answer;
    }
}