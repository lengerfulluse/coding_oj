package me.hengwei.leetcode;

import sun.awt.image.ImageWatched;

import java.util.LinkedList;

/**
 * https://leetcode.com/problems/implement-stack-using-queues/
 */
public class Implement_Stack_using_Queues_225 {
    private final int QUEUE_CAPACITY = 20;
    private LinkedList<Integer> queue1 = new LinkedList<>();
    private LinkedList<Integer> queue2 = new LinkedList<>();

    // Push element x onto stack.
    public void push(int x) {
        queue1.offer(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        queue1.poll();

    }

    // Get the top element.
    public int top() {

    }

    // Return whether the stack is empty.
    public boolean empty() {

    }
}
