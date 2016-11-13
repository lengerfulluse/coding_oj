package me.hengwei.interview;

import java.util.HashMap;

/**
 * Least Recent Used cache example. We implements a double-end linked list(with
 * both head and tail element) and combined with a HashMap to implements LRUCache
 */
public class LRUCache {

    public class DeLinkedList {
        private int size = 0;
        private int capacity;
        Node head;
        Node tail;

        public DeLinkedList(int capacity) {
            this.capacity = capacity;
            /*
            * the first two empty element node as guard
            * to avoid empty check.
            */
            head = new Node();
            head.prev = null;
            tail = new Node();
            tail.next = null;
            head.next = tail;
            tail.prev = head;
        }

        class Node<E> {
            E item;
            Node next;
            Node prev;
        }

        /**
         * move the recently used node to linked head.
         * @param node
         */
        public void moveToHead(Node node) {
            if (node == null || head == null) {
                return; // throw exception.
            }
            Node headNext = head.next;
            head.next = node;
            node.prev = head;
            node.next = headNext;
            headNext.prev = node;
        }

        /**
         * remove least used node in tail.
         */
        public Node removeTailNode() {
            if (isEmpty()) {
                return null; // throw exception.
            }
            Node prevTail = tail.prev;
            Node prevPrevTail = prevTail.prev;
            prevPrevTail.next = tail;
            tail.prev = prevPrevTail;
            return prevTail;
        }

        /**
         * add new node to head.
         */
        public void addHeadNode(Node node) {
            if(isFull()) {
                removeTailNode();
            }
            Node headNext = head.next;
            head.next = node;
            node.next = headNext;
            node.prev = head;
            headNext.prev = node;
            size++;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean isFull() {
            return size == capacity;
        }

        public int size() {
            return size;
        }
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        deLinkedList = new DeLinkedList(capacity);
        pageReference = new HashMap<>();
    }

    /* cache element */
    class CacheItem {
        public String key;
        public Object data;
        public CacheItem(String key, Object data) {
            this.key = key;
            this.data = data;
        }
    }

    private int capacity;
    private HashMap<String, DeLinkedList.Node<CacheItem>> pageReference;
    private DeLinkedList deLinkedList;

    /**
     * get a cache object specified by a key. Loaded from disk if not exist, add
     * add it to cache.
     */
    public Object get(String key) {
        if(pageReference.containsKey(key)) {
            System.out.println("hit in cache with key: " + key);
            DeLinkedList.Node<CacheItem> node = pageReference.get(key);
            deLinkedList.moveToHead(node);
            return node.item.data;
        } else {
            /* simulate to load object from disk here */
            System.out.println("missed in cache, loaded from disk with key: " + key);
            if( this.capacity == deLinkedList.size()) {
                DeLinkedList.Node<CacheItem> tailNode = deLinkedList.removeTailNode();
                System.out.println("cached full, remove tail element with key: " + tailNode.item.key);
                pageReference.remove(tailNode.item.key);
            }
            /* add the new loaded element */
            Object object = new Object();
            CacheItem cacheItem = new CacheItem(key, object);
            DeLinkedList.Node<CacheItem> node = deLinkedList.new Node<>();
            node.item = cacheItem;
            deLinkedList.addHeadNode(node);
            pageReference.put(key, node);
            return object;
        }
    }

    public static void main(String[] args) {
        LRUCache lruCache = new LRUCache(5);
        /* example with sequence of 1, 2, 3, 4, 2, 3, 5, 6; */
        lruCache.get("1");
        lruCache.get("2");
        lruCache.get("3");
        lruCache.get("4");
        lruCache.get("2");
        lruCache.get("3");
        lruCache.get("5");
        lruCache.get("6");
        lruCache.get("2");
        lruCache.get("1");
        /*
        OUTPUT AS FOLLOWING

        missed in cache, loaded from disk with key: 1
        missed in cache, loaded from disk with key: 2
        missed in cache, loaded from disk with key: 3
        missed in cache, loaded from disk with key: 4
        hit in cache with key: 2
        hit in cache with key: 3
        missed in cache, loaded from disk with key: 5
        missed in cache, loaded from disk with key: 6
        cached full, remove tail element with key: 1
        hit in cache with key: 2
        missed in cache, loaded from disk with key: 1
        */
    }
}
