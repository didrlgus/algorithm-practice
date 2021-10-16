package coding_interview.array;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Question. 숫자로 구성된 배열 numbers와 target 숫자 하나가 주어졌을 때 numbers 배열에 들어있는 두 수를 더해 target 숫자를 만들 수 있는
 * 인덱스 두개를 찾는 함수를 작성하라. 예) numbers = [2, 3, 5, 7] target = 8, 8을 만들 수 있는 3과 5의 인덱스인 1, 2를 리턴해야 한다.
 * 예) numbers = [1, 2, 6, 8] target = 9, 9를 만들 수 있는 1과 8의 인덱스인 0, 3을 리턴해야 한다. numbers 배열에 중복되는 숫자는
 * 없으며 target 숫자를 만들 수 있는 조합은 하나 뿐이라고 가정해도 좋다.
 */


public class Quiz3 {

    /**
     * 시간복잡도: O(N^2)
     * 공간복잡도: O(1)
     */
    public int[] solution1(int[] numbers, int target) {

        int N = numbers.length;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (numbers[i] + numbers[j] == target) {
                    return new int[]{i, j};
                }
            }
        }

        return null;
    }

    /**
     * 시간복잡도: O(N)
     * 공간복잡도: O(N)
     */
    public int[] solution2(int[] numbers, int target) {

        int N = numbers.length;
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            int findNumber = target - numbers[i];

            if (map.containsKey(findNumber) && map.get(findNumber) != i) {
                return new int[]{i, map.get(findNumber)};
            }

            map.put(numbers[i], i);
        }

        return null;
    }

    public static void main(String[] args) {
        Quiz3 quiz3 = new Quiz3();

        int[] numbers = new int[]{1, 2, 6, 8};

        System.out.println(Arrays.toString(quiz3.solution1(numbers, 9)));
        System.out.println(Arrays.toString(quiz3.solution2(numbers, 9)));
    }

}
