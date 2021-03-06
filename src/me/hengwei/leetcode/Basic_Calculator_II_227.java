package me.hengwei.leetcode;

import java.math.BigInteger;
import java.util.*;

/**
 * https://leetcode.com/problems/basic-calculator-ii/
 *
 */
public class Basic_Calculator_II_227 {

    private Collection<String> operators = new ArrayList<>();
    private Map<String, Integer> operatorPriority = new HashMap<>();
    private String curCharSeq = null;
    private int curCharSeqPos = 0;
    private int curCharSeqLen = 0;
    Deque<String> dataStack = new ArrayDeque<>();
    Deque<String> operatorStack = new ArrayDeque<>();

    private final String EmptyOperator = "#";

    private void initOperators() {
        /* supported operator and their priority sort */
        operators.add("+");
        operatorPriority.put("+", 1);

        operators.add("-");
        operatorPriority.put("-", 1);

        operators.add("*");
        operatorPriority.put("*", 2);

        operatorPriority.put("/", 2);
        operators.add("/");

        operatorPriority.put("#", 0);
    }

    /**
     * clear previous data and assign new input string.
     *
     * @param s
     */
    public void clearCalculator(String s) {
        /* remove all blank space */
        this.curCharSeq = s.replaceAll(" ", "");
        this.curCharSeqPos = 0;
        this.curCharSeqLen = curCharSeq.length();
        dataStack.clear();
        operatorStack.clear();
    }

    /**
     * Assume the input string is always valid.
     *
     * @param s input in-order format string.
     * @return calculate result.
     */
    public int calculate(String s) {
        /* indicate invalid result by default */
        int result = -99999;
        /* null or blank situation, return directly */
        if (s == null || s.trim().isEmpty()) {
            return result;
        }
        this.clearCalculator(s);
        this.initOperators();

        String firstOperation = this.getElement();
        dataStack.push(firstOperation);
        /* only one digital situation, return first digital directly */
        if(this.curCharSeqPos == this.curCharSeqLen) {
            result = Integer.valueOf(firstOperation);
            return result;
        }
        operatorStack.push(this.getElement());
        dataStack.push(this.getElement());
        /* push digital element */
        while (this.curCharSeqPos < this.curCharSeqLen) {

            String operator = this.getElement();
            String topOperator = this.EmptyOperator;

            /* use the default empty operator flag */
            if (!dataStack.isEmpty()) {
                topOperator = operatorStack.peek();
            }

            /*
             * if the next operator's priority is higher then current operator in stack
             * calculate the current expression, and then put the result into data stack.
             */
            if (operatorPriority.get(operator) > operatorPriority.get(topOperator)) {
                String leftOperation = dataStack.pop();
                String rightOperation = this.getElement();
                String expressionResult = this.calculateExpression(leftOperation, operator, rightOperation);
                dataStack.push(expressionResult);
            } else {
                String rightOperation = dataStack.pop();
                String leftOperation = dataStack.pop();
                String expressionResult = this.calculateExpression(leftOperation, topOperator, rightOperation);
                dataStack.push(expressionResult);
                /* pop the previous top operator, push the current low priority operator */
                operatorStack.pop();
                operatorStack.push(operator);
                /* push the right operation data of this low priority operator. */
                dataStack.push(this.getElement());
            }
        }
        if (!operatorStack.isEmpty()) {
            String rightOperation = dataStack.pop();
            String leftOperation = dataStack.pop();
            String operator = operatorStack.pop();
            result = Integer.valueOf(this.calculateExpression(leftOperation, operator, rightOperation));
        }
        return result;
    }

    private String calculateExpression(String leftOperation, String operator, String rightOperation) {
        BigInteger result = null;
        if (!this.operators.contains(operator)) {
            return null;
        }
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
        String ele;
        if (this.curCharSeqPos == this.curCharSeq.length()) {
            return null;
        }
        String firstChar = String.valueOf(curCharSeq.charAt(this.curCharSeqPos));
        /* operator situation */
        if (operators.contains(firstChar)) {
            ele = firstChar;
            /* move forward to the next. */
            this.curCharSeqPos = this.curCharSeqPos + 1;
        } else {
            ele = getDigitalStr();
        }
        return ele;
    }

    /**
     * be capable of getting digital string at the begin of a string.
     *
     * @return first digital element
     */
    private String getDigitalStr() {
        String digitalStr;
        int i;
        for (i = this.curCharSeqPos; i < this.curCharSeqLen; i++) {
            Character character = this.curCharSeq.charAt(i);
            if (character < '0' || character > '9') {
                break;
            }
        }
        digitalStr = this.curCharSeq.substring(this.curCharSeqPos, i);
        /* move forward to next. */
        this.curCharSeqPos = i;
        return digitalStr;
    }

    public static void main(String[] args) {
        Basic_Calculator_II_227 basic_calculator_ii_227 = new Basic_Calculator_II_227();
        List<String> test_set = new ArrayList<>();
        test_set.add("0");
        test_set.add(" 3/2 ");
        test_set.add(" 3+5 / 2 ");
        test_set.add("0-2147483648");

        String inputExpression = "0";
        System.out.println(basic_calculator_ii_227.calculate(inputExpression));

    }
}

