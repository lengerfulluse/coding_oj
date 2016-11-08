package me.hengwei.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/word-ladder/.
 */
public class Word_Ladder_127 {
    class Status {
        private int level;
        private String word;
        public Status(String word, int level) {
            this.word = word;
            this.level = level;
        }
    }

    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {
        Queue<Status> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        /* initiate status */
        Status status = new Status(beginWord, 0);
        queue.add(status);
        while(!queue.isEmpty()) {
            Status cur = queue.poll();
            StringBuffer word = new StringBuffer(cur.word);
            for(int i=0; i<word.length(); i++) {
                for(int j='a'; i<'z'; j++) {
                    char c = word.charAt(i);
                    if(j == c)
                        continue;
                    word.setCharAt(i, (char)j);
                    if (visited.contains(word.toString())) {
                        continue;
                    }
                    if(endWord.equals(word.toString()))
                        return cur.level + 1;
                    if(wordList.contains(word.toString())) {
                        queue.add(new Status(word.toString(), cur.level+1));
                    }
                }
            }
            visited.add(cur.word);
        }
        return -1;
    }


    public static void main(String[] args) {
        Word_Ladder_127 word_ladder_127 = new Word_Ladder_127();
        String beginWord = "hit";
        String endWord = "cog";
        Set<String> wordList = new HashSet<>(Arrays.asList("hot", "dot", "dog", "lot", "log"));
        System.out.println(word_ladder_127.ladderLength(beginWord, endWord, wordList));
    }
}
