package com.java.app;

interface Solution {
    public int rob(int[] nums);
}

class Solution1 implements Solution {
    private static final int INT_MIN = -2147483648;
    private int[] nums;

    private int adjustIdx(int idx) {
        return idx < 0
            ? (this.nums.length - 1) - ((-idx - 1) % this.nums.length)
            : idx % this.nums.length;
    }

    public int rob(int[] nums) {
        this.nums = nums;

        int max = INT_MIN;
        for (int i = 0; i < nums.length; i++) {
            max = nums.length < 4
                ? Math.max(max, nums[i])
                : Math.max(max, this.seqRob(i + 2, i - 2) + nums[i]);
        }

        return max;
    }

    private int seqRob(int begin, int end) {
        begin = this.adjustIdx(begin);
        end = this.adjustIdx(end);
        int[] cache = new int[this.nums.length];
        cache[begin] = this.nums[begin];

        for (int i = this.adjustIdx(begin + 1); i != this.adjustIdx(end + 1); i = this.adjustIdx(i + 1)) {
            cache[i] = Math.max(cache[this.adjustIdx(i - 2)] + this.nums[i], cache[this.adjustIdx(i - 1)]);
        }

        return cache[end];
    }
}

class Solution2 implements Solution {
    private static final int INT_MIN = -2147483648;

    public int rob(int[] nums) {
        // Filtering
        if (nums.length < 4) {
            int max = INT_MIN;
            for (int num : nums) {
                max = Math.max(max, num);
            }
            return max;
        }

        // Sequesntial robbery
        int[] seqCache = new int[nums.length];
        seqCache[0] = nums[0];
        seqCache[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            seqCache[i] = Math.max(seqCache[i - 1], seqCache[i - 2] + nums[i]);
        }

        // wtf
        int[] rotCache = new int[nums.length];
        rotCache[0] = nums[1];
        rotCache[1] = Math.max(nums[1], nums[2]);
        for (int i = 2; i < nums.length - 1; i++) {
            rotCache[i] = Math.max(rotCache[i - 1], nums[i + 1] + rotCache[i - 2]);
        }

        return Math.max(seqCache[nums.length - 2], rotCache[nums.length - 2]);
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

public class L213_House_Robber_II {
    public static void main(String[] args) {
        int[][] numses = {
            {2,3,2},
            {1,2,3,1},
            {1,2,3},
        };

        Testing[] tcases = {
            new Testing(numses[0], 3),
            new Testing(numses[1], 4),
            new Testing(numses[2], 3),
        };

        Solution solutions[] = {
            new Solution1(),
            new Solution2(),
        };

        for (Testing t : tcases) {
            for (Solution s : solutions) {
                if (!t.test(s.rob(t.nums))) {
                    System.err.println("FAIL");
                }
            }
        }

        System.out.println("ok");
    }
}
