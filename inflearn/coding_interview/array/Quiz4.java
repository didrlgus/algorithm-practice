package coding_interview.array;

/**
 *
 * Question.
 * 1부터 100 까지의 숫자 중에 50개의 랜덤한 숫자가 중복없이 들어있는 배열이 있다. 이 배열을 O(n)의 시간복잡도로 정렬하라.
 *
 */

public class Quiz4 {

    /**
     *
     * 시간복잡도: O(N)
     * 공간복잡도: O(N)
     *
     */
    public int[] sortArray(int[] numbers) {

        boolean[] check = new boolean[101];

        int[] sortedArray = new int[numbers.length];

        for (int number : numbers) {
            check[number] = true;
        }

        int idx = 0;
        for (int i = 1; i <= 100; i++) {
            if (check[i]) {
                sortedArray[idx++] = i;
            }
        }

        return sortedArray;
    }
}
