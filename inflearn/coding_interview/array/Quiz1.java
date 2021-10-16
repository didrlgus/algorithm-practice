package coding_interview.array;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Question.
 * 숫자로 구성된 배열이 주어졌을 때, 그 배열에 중복된 숫자가 있는지 확인하는 함수를 작성하라.
 * 중복된 숫자가 있다면 true 없다면 false
 *
 */

/**
 * TIP.
 * 배열 문제가 나오면 항상 정렬이 돼있는지 그렇지 않은지를 물어봐야 함.
 */


public class Quiz1 {

    // 시간복잡도 O(N^2)
    // 공간복잡도 O(1)
    public boolean solution1(int[] numbers) {

        int N = numbers.length;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (numbers[i] == numbers[j]) {
                    return true;
                }
            }
        }

        return false;
    }

    // 시간복잡도: O(NlogN)
    // 공간복잡도: O(logN)
    public boolean solution2(int[] numbers) {

        // 시간복잡도: O(NlogN)
        // 공간복잡도: O(logN)
        Arrays.sort(numbers);

        for (int i = 0; i < numbers.length - 1; i++) {
            if (numbers[i] == numbers[i + 1]) {
                return true;
            }
        }

        return false;
    }

    // 시간복잡도 O(N)
    // 공간복잡도 O(N)
    public boolean solution3(int[] numbers) {

        // set은 해시값 조회 -> O(1)
        Set<Integer> set = new HashSet<>();

        for (int element : numbers) {
            // set의 contains -> O(N)
            if (set.contains(element)) {
                return true;
            }
            set.add(element);
        }

        return false;
    }

    // 시간복잡도 O(N)
    // 공간복잡도 O(N)
    public boolean solution4(int[] numbers) {

        Map<Integer, Integer> map = new HashMap<>();

        for (int element : numbers) {
            if (map.containsKey(element)) {
                map.put(element, map.get(element) + 1);
                continue;
            }
            map.put(element, 1);
        }

        for (int key : numbers) {
            if (map.get(key) >= 2) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {

        ListQuiz1 listQuiz1 = new ListQuiz1();

        int[] numbers = new int[] {1, 2, 3, 4, 5};

        System.out.println(listQuiz1.solution1(numbers));
        System.out.println(listQuiz1.solution2(numbers));
        System.out.println(listQuiz1.solution3(numbers));
        System.out.println(listQuiz1.solution4(numbers));
    }

}
