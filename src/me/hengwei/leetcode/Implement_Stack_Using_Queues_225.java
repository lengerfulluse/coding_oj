package me.hengwei.leetcode;


import java.util.LinkedList;

/**
 * https://leetcode.com/problems/implement-stack-using-queues/
 */
public class Implement_Stack_Using_Queues_225 {
    private LinkedList<Integer> queue1 = new LinkedList<>();
    private LinkedList<Integer> queue2 = new LinkedList<>();
    private int top;
    /* Push element x onto stack. */
    public void push(int x) {
        queue1.offer(x);
        top = x;
    }

    /* Removes the element on top of the stack. */
    public void pop() {
        if (queue1.isEmpty()) {
            return;
        }
        while (queue1.size() > 1) {
            top = queue1.poll();
            queue2.offer(top);
        }
        queue1.poll();
        /* Switch the queue1 and queue2 */
        LinkedList<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    /* Get the top element. */
    public int top() {
        return top;
    }

    /* Return whether the stack is empty. */
    public boolean empty() {
        if (queue1.isEmpty() && queue2.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Implement_Stack_Using_Queues_225 implement_stack_using_queues_225 = new Implement_Stack_Using_Queues_225();
        implement_stack_using_queues_225.push(5);
        implement_stack_using_queues_225.push(4);
        implement_stack_using_queues_225.pop();
        implement_stack_using_queues_225.pop();
        implement_stack_using_queues_225.push(8);
        implement_stack_using_queues_225.push(9);
        implement_stack_using_queues_225.pop();
        implement_stack_using_queues_225.push(12);
        implement_stack_using_queues_225.push(21);
        implement_stack_using_queues_225.pop();
        System.out.println(implement_stack_using_queues_225.top());
    }
}
