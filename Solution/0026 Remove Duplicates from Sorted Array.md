### 题目描述：
> 原题目：

> Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

> Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

> Example 1:

```
Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
```
> Example 2

```
Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
```

题目给出一个已经排序好的数组，然后要你返回剔除了重复元素的数组，题目要求不能额外使用内存空间。

### 思路：
我们马上想到用一个计数器统计不重的数。顺着这个思路拓展，我们先设置一个==标记i==用来遍历数组，==num表示不重复数的数量==。然后根据实际情况考虑如何继续完善。

情况1 : [0,0,1]。

当 i = 0 时num = 1；

当 i = 1 时num = 1；

当 i = 2 时num = 2；

可以看到当遍历的元素和上一个元素相同时num不发生改变。因此我们再设置一个变量OG，用来暂存上一个被遍历的数字。

那么按照此时的想法，当i移动时，OG是否每次都要更新值呢？答案是否定的，因为题目已经告诉我们这个数组是按顺序排列好了。OG发生改变的时机应该是和num一致的。

现在要如何修改数组呢？我们先考虑一种完美情况，即没有一个重复的数，此时输出的长度和原长度是一致的。除此之外，输出的最终长度都会比原来的要小，这是由于重复的数字会占用额外的空间，那么这部分额外的空间便是我们可以用来修改数组的位置。

举个例子，[0,0,0,1,2]，我们可以只保留第一个出现的0，并记录下第一次出现重复的位置（即i=1），这个位置将用来放置下一个不重复的数字。可以看到当i=3时终于出现了一个和0不相同的数，1。此时这个1应该要放到哪里呢？答案就是i=1的那个位置。那么i=4时得到的2应该放哪里呢？因为此时第二个位置已经被1占用，因此2顺位排在1后面。

说了这么多，其实关键点就在于重复的元素会占用多余的位置，由于已经排好序，那么我们只要把后面不重复的元素直接覆盖到多余的位置上即可

### 解法：

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        
        int targetIndex = 1;
        int OG = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (nums[i] != OG){
                OG = nums[i];
                nums[targetIndex] = nums[i];
                targetIndex++;
            }
        }
        return targetIndex;
    }
    
};
```





