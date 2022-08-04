package com.jalgo.app;

class Solution {
    public int climbStairs(int n) {
        int[] cache = new int[n + 1];
        cache[0] = 1;
        cache[1] = 1;

        for (int idx = 2; idx <= n; idx++) {
            cache[idx] = cache[idx - 1] + cache[idx - 2];
        }

        return cache[n];
    }
}

class Testing {
    public int n;
    private int output;
    public Testing(int n, int output) {
        this.n = n;
        this.output = output;
    }

    public boolean test(int output) {
        return this.output == output;
    }
}

public class App {
    public static void main(String[] args) {
        Testing[] tcases = {
            new Testing(2, 2),
            new Testing(3, 3),
        };

        Solution s = new Solution();

        for (Testing t : tcases) {
            t.test(s.climbStairs(t.n));
        }

        System.out.println("ok");
    }
}
