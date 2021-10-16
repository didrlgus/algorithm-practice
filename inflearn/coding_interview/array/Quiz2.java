package coding_interview.array;

/**
 * Question.
 * 주어진 문자열을 거꾸로 뒤집은 문자열을 만드는 함수를 작성하라.
 * 예) hello => olleh
 * 예) happy new year => reay wen yppah
 *
 * 출제 의도
 * ● 난이도: 쉬움
 * ● 배열 조회, 순회, 반복문 등 기본적인 프로그래밍 경험이 있는가?
 * ● 간단한 swap 기능을 구현할 수 있는가?
 * ● 자바의 StringBuilder API를 알고 있는가?
 */

public class Quiz2 {

    /**
     *
     * 시간복잡도: O(N)
     * 공간복잡도: O(N)
     *
     */
    public char[] solution1(char[] message) {

        int N = message.length;

        char[] reversedMessage = new char[N];

        for (int i = N - 1; i >= 0; i--) {
            reversedMessage[N - 1 - i] = message[i];
        }

        return reversedMessage;
    }

    /**
     *
     * 시간복잡도: O(N)
     * 공간복잡도: O(1)
     *
     */
    public char[] solution2(char[] message) {

        int N = message.length;

        // a b a c d
        // 0 1 2 3 4
        for (int i = 0; i < N / 2; i++) {
            char tmp;
            tmp = message[i];
            message[i] = message[N - 1 - i];
            message[N - 1 - i] = tmp;
        }

        return message;
    }

    public static void main(String[] args) {

        Quiz2 quiz2 = new Quiz2();

        char[] message = new char[]{'h', 'a', 'p', 'p', 'y', ' ', 'n', 'e', 'w', ' ', 'y', 'e', 'a', 'r'};

        System.out.println(quiz2.solution1(message));
        System.out.println(quiz2.solution2(message));
    }

}