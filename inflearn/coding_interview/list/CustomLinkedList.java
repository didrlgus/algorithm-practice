package coding_interview.list;

class Node {
    int data;
    Node prev;
    Node next;

    public Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

/**
 *
 * addFirst, addLast, removeFirst, removeLast, getNode, add, remove, get
 *
 */
class LinkedList {

    Node head, tail;
    int size;

    // addFirst: List의 맨 앞(head)에 data를 추가하는 메서드
    public void addFirst(int data) {
        Node newNode = new Node(data);

        if (this.size == 0) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }

        this.size += 1;
    }

    // addLast: List의 맨 뒤(tail)에 data를 추가하는 메서드
    public void addLast(int data) {
        if (this.size == 0) {
            addFirst(data);
        } else {
            Node newNode = new Node(data);
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
            this.size += 1;
        }
    }

    // removeFirst: List의 맨앞에 있는 data를 삭제하는 메서드
    public void removeFirst() {
        if (this.size == 0) {
            System.out.println("삭제할 노드가 없습니다.");
        } else {
            Node removeNode = head;
            head = removeNode.next;
            head.prev = null;
            this.size -= 1;
        }
    }

    // removeLast: List의 맨뒤에 있는 data를 삭제하는 메서드
    public void removeLast() {
        if (this.size == 0) {
            System.out.println("삭제할 노드가 없습니다.");
        } else {
            Node removeNode = tail;
            tail = removeNode.prev;
            tail.next = null;
            this.size -= 1;
        }
    }

    // getNode: 원하는 index 위치의 노드를 조회하는 메서드
    private Node getNode(int index) {
        Node node = head;

        while(index-- > 0) {
            node = node.next;
        }

        return node;
    }

    // add: 원하는 index 위치에 data를 추가하는 메서드
    public void add(int index, int data) {
        if (index == 0) {
            addFirst(data);
        } else if (index == this.size) {
            addLast(data);
        } else if (index > this.size) {
            System.out.println("인덱스 값이 너무 큽니다.");
        } else {
            Node newNode = new Node(data);
            Node prevNode = getNode(index - 1);
            Node nextNode = prevNode.next;

            prevNode.next = newNode;
            nextNode.prev = newNode;

            newNode.prev = prevNode;
            newNode.next = nextNode;

            this.size += 1;
        }
    }

    // remove: index 위치의 data를 삭제하는 메서드
    public void remove(int index) {
        if (index == 0) {
            removeFirst();
        } else if (index == this.size - 1) {
            removeLast();
        } else {
            Node removeNode = getNode(index);
            Node prevNode = removeNode.prev;
            Node nextNode = removeNode.next;

            prevNode.next = nextNode;
            nextNode.prev = prevNode;
            this.size -= 1;
        }
    }

    // get: index위치의 data를 return하는 메서드
    public int get(int index) {
        return getNode(index).data;
    }
}

public class CustomLinkedList {

    public static void main(String args[]) throws Exception {
        LinkedList linkedList = new LinkedList();

        linkedList.addLast(1);
        linkedList.addLast(2);
        linkedList.addLast(3);
        linkedList.addLast(4);
        linkedList.addLast(5);

        linkedList.removeFirst();
        linkedList.removeLast();
        linkedList.remove(1);

        linkedList.add(1, -1000000);

        for (int i = 0; i < linkedList.size; i++) {
            System.out.println(linkedList.get(i));
        }
    }
}

