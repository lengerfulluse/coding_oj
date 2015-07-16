package me.hengwei.leetcode;

import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.Deque;

/**
 * https://leetcode.com/problems/basic-calculator/
 */
public class Basic_Calculator_224 {

    private int seqPos = 0;
    private String seq;

    public int calculate(String s) {
        seq = s.replaceAll(" ", "");
        int sum = -99999;
        Deque<String> stackInParen = new ArrayDeque<>();
        Deque<String> stackOutParen = new ArrayDeque<>();
        while (seqPos < seq.length()) {
            String ele = getElement();
            if (ele.equals("(")) {
                stackInParen.push(ele);
                /* pop while pair of "(" has been processed */
                while (stackInParen.size() > 1 || ((stackInParen.size() == 1) && "(".equals(stackInParen.peek()))) {
                    String inParentheses = getElement();
                    if (")".equals(inParentheses)) {
                        String value = stackInParen.pop();
                        String prevRightParen = stackInParen.peek();
                        //System.out.println(prevRightParen);
                        if ("(".equals(prevRightParen.toString())) {
                            stackInParen.pop();
                            stackInParen.push(value);
                            continue;
                        }
                        stackInParen.push(value);
                        // calculate inner parentheses.
                        while (stackInParen.size() > 2) {
                            String rightOperation = stackInParen.pop();
                            String operator = stackInParen.pop();
                            String leftOperation = stackInParen.pop();
                            String result = calculateExpression(leftOperation, operator, rightOperation);
                            System.out.println(leftOperation + operator + rightOperation + "=" + result);
                            if ("(".equals(stackInParen.peek())) {
                                stackInParen.pop();
                                stackInParen.push(result);
                                break;
                            }
                            stackInParen.push(result);
                        }
                    } else {
                        stackInParen.push(inParentheses);
                    }
                }
                stackOutParen.push(stackInParen.pop());
            } else { // sequence calculation outside of parentheses.
                stackOutParen.push(ele);
            }
            if (stackOutParen.size() >= 3) {
                String rightOperation = stackOutParen.pop();
                String operator = stackOutParen.pop();
                String leftOperation = stackOutParen.pop();
                String result = calculateExpression(leftOperation, operator, rightOperation);
                System.out.println(leftOperation + operator + rightOperation + "=" + result);
                stackOutParen.push(result);
            }
        }

        while (stackOutParen.size() > 1) {
            String rightOperation = stackOutParen.pop();
            String operator = stackOutParen.pop();
            String leftOperation = stackOutParen.pop();
            String result = calculateExpression(leftOperation, operator, rightOperation);
            //System.out.println(leftOperation + operator + rightOperation + "=" + result);
            stackOutParen.push(result);
        }
        sum = Integer.valueOf(stackOutParen.pop());
        return sum;
    }

    private String calculateExpression(String leftOperation, String operator, String rightOperation) {
        BigInteger result = null;
        BigInteger left = new BigInteger(leftOperation);
        BigInteger right = new BigInteger(rightOperation);
        switch (operator) {
            case "+":
                result = left.add(right);
                break;
            case "-":
                result = left.subtract(right);
                break;
            case "*":
                result = left.multiply(right);
                break;
            case "/":
                result = left.divide(right);
                break;
        }
        return result.toString();
    }

    private String getElement() {
        Character character = seq.charAt(seqPos);
        int begin = seqPos;
        String ele;
        if (character < '0' || character > '9') {
            ele = character.toString();
            seqPos++;
        } else {
            while (character >= '0' && character <= '9') {
                seqPos++;
                if (seqPos >= seq.length()) {
                    break;
                }
                character = seq.charAt(seqPos);
            }
            ele = seq.substring(begin, seqPos);
        }
        return ele;
    }

    public static void main(String[] args) {
        Basic_Calculator_224 basic_calculator_224 = new Basic_Calculator_224();
        String input = "2-4-(8+2-6+(8+4-(1)+8-10))";
        System.out.println("Final result: " + basic_calculator_224.calculate(input));
    }
}
