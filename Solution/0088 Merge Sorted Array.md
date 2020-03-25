### 题目描述
### 题目描述：
> 原题目Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

>Note:
>- The number of elements initialized in nums1 and nums2 are m and n respectively.
>- You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

> Example:
```
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]
```



一言以蔽之，就是给你两个排序好的数组和它们各自的数量m和n，其中一个数组的长度比较长。你需要做的事情就是把短的插到长的里面，而且还要排好序哦。



### 思路：
符合直觉的操作是将nums2插入到nums1后，然后再进行排序。但是出题人给了各自的长度m和n，上述解法甚至不需要这两个变量。显然这不是出题人的意图。

题目的设定中，nums1的后端是有给nums2预留的位置的，而且长度是刚刚好的。因此我们可以从右往左比较，即用题目给的m,n标记两个数组正在比较的位置，而后再设定一个current指针指向长数组的最后一位。

具体操作流程为：
1. 比较nums1和nums2最最右边的元素，将比较大的放置到current位置，然后current左移
2. 第一步中较大的数可以视为已经被挑走，此时将其往左移动一个位置（可以理解为最右边的数字更新了）。
3. 然后继续比较两个数组最右边的数字，重复。


### 解法：

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int current = m + n - 1;
        while (current >= 0) {
            if (n == 0) return;
            if (m < 1) {
                nums1[current--] = nums2[--n];
                continue;
            }
            if (n < 1) {
                nums1[current--] = nums1[--m];
                continue;
            }
            if (nums1[m - 1] > nums2[n - 1]) nums1[current--] = nums1[--m];
            else nums1[current--] = nums2[--n];
        }
    }
};
```
### Note:

暂无
