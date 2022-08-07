package com.java.app;

class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        int max = -2147483648;
        for (int i = 0; i < len; i++) {
            int b = i > 0 ? nums[i - 1] : 0;
            int bb = i > 1 ? nums[i - 2] : 0;
            nums[i] = Math.max(b, bb + nums[i]);
            max = Math.max(max, nums[i]);
        }
        return max;
    }
}

class Testing {
    public int[] nums;
    private int output;

    public Testing(int[] nums, int output) {
        this.nums = nums;
        this.output = output;
    }

    public boolean test(int output) {
        return this.output == output;
    }
}

public class L198_House_Robber {
    public static void main(String[] args) {
        int[][] numses = {
            {1,2,3,1},
            {2,7,9,3,1},
            {2,1},
            {1},
            {2,1,1,2},
            {1,3,1,3,100},
        };

        Testing[] tcases = {
            new Testing(numses[0], 4),
            new Testing(numses[1], 12),
            new Testing(numses[2], 2),
            new Testing(numses[3], 1),
            new Testing(numses[4], 4),
            new Testing(numses[5], 103),
        };

        Solution s = new Solution();

        for (Testing t : tcases) {
            if (!t.test(s.rob(t.nums))) {
                System.err.println("FAIL");
                return;
            }
        }

        System.out.println("ok");
    }
}
