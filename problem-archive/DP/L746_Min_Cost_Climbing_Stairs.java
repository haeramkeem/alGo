package com.java.app;

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] cache = new int[cost.length + 1];
        for (int i = 2; i < cache.length; i++) {
            cache[i] = Math.min(cost[i - 1] + cache[i - 1], cost[i - 2] + cache[i - 2]);
        }
        return cache[cache.length - 1];
    }
}

class Testing {
    public int[] cost;
    private int output;

    public Testing(int[] cost, int output) {
        this.cost = cost;
        this.output = output;
    }

    public boolean test(int output) {
        return this.output == output;
    }
}

public class L746_Min_Cost_Climbing_Stairs {
    public static void main(String[] args) {
        int[][] costs = {
            {10,15,20},
            {1,100,1,1,1,100,1,1,100,1},
        };

        Testing[] tcases = {
            new Testing(costs[0], 15),
            new Testing(costs[1], 6),
        };

        Solution s = new Solution();

        for (Testing t : tcases) {
            if (!t.test(s.minCostClimbingStairs(t.cost))) {
                System.err.println("FAIL");
                return;
            }
        }

        System.out.println("ok");
    }
}
