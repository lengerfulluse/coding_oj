package me.hengwei.interview;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.ListIterator;

/**
 * Least Recent Used cache example.
 */
public class LRUCache {
    class CacheItem {
        public String key;
        public Object data;
        public CacheItem(String key, Object data) {
            this.key = key;
            this.data = data;
        }
    }
    private final int MAX_SIZE = 5;
    private HashMap<String, ListIterator<CacheItem>> pageReference = new HashMap<>();
    private LinkedList<CacheItem> pageObjects = new LinkedList<>();

    /**
     * get a cache object specified by a key. Loaded from disk if not exist, add
     * add it to cache.
     */
    public Object get(String key) {
        if(pageReference.containsKey(key)) {
            System.out.println("hitted in cache with key: " + key);
            ListIterator<CacheItem> iter = pageReference.get(key);
            CacheItem cacheItem = iter.next();
            /* remove the current one, and add the latest used to queue */
            iter.remove();
            pageObjects.addLast(cacheItem);
            pageReference.put(key, pageObjects.listIterator(pageObjects.size()-1));
            return cacheItem.data;

        } else {
            /* simulate to load object from disk here */
            System.out.println("missed in cached, loaded from disk with key: " + key);
            if(pageReference.size() == MAX_SIZE) {
                System.out.println("exceed the max cache size, remove first ..");
                /* remove the least recent used object from queue and hash map */
                CacheItem first = pageObjects.getFirst();
                System.out.println("remove from cached with key: " + first.key);
                pageObjects.removeFirst();
                pageReference.remove(first.key, first.data);
            }
            /* add the new loaded element */
            Object object = new Object();
            CacheItem cacheItem = new CacheItem(key, object);
            pageObjects.addLast(cacheItem);
            pageReference.put(key, pageObjects.listIterator(pageObjects.size()-1));
            return object;
        }
    }

    public static void main(String[] args) {
        LRUCache lruCache = new LRUCache();
        /* example with sequence of 1, 2, 3, 4, 2, 3, 5, 6; */
        lruCache.get("1");
        lruCache.get("2");
        lruCache.get("3");
        lruCache.get("4");
        lruCache.get("2");
        lruCache.get("3");
        lruCache.get("5");
        lruCache.get("6");
    }
}
