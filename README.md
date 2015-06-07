# LeetCode-Solution
my first solution of LeetCode
2015-5-7  Problem 95,98(80 already!)



题型一：经典暴力递归：（里面涉及到重复不重复的时候，需要注意该如何处理！）
模板都是一样的
039：Combination Sum
040：Combination Sum II
046：Permutations
047：Permutations II
051：N-Queens
052：N-Queens II
071: Letter Combinations of a Phone Number 
093：Restore IP Addresses

题型二：动态规划
053：最大字串之和
055：method1 O(n * n),设置访问数组，保存每个元素是否可达端点。这样对每个元素，都需要遍历它后面的元素。并且空间复杂度：O(n)
     method2 O(n),O(1) 保存当前能访问的最大长度。
	 如果当前元素能达到的长度比curMax长，那么更新；如果不能，则什么也不干；如果当前元素的index == curMax,也就是说已经达到了巅峰，并且arr[index] = 0,那么代表无可救药，返回false.
097：也可以算是二维DP，不过我只用了记忆数组，还没有改成迭代，有时间改进一下。
二维动态规划：
这种类型的题目只需注意构造中间结果的顺序即可，无他。
中间结果的构造依赖于最优子结构，如果f(x) = optical(上，中，下),那么在处理f(x)的时候就要已经构造好上中下。
像下面这几道题，都不需要刻意找构造方向，直接二层循环即可。因为都是依赖上，坐，如064；或者上、左、对角线。如072
063：Unique Paths II
064：Minimum Path Sum（如果行走方向可以是四面八方，而不是只能两个方向，那怎么办？感觉这种方法不能generalize...）
072: Edit Distance 

题型三：数组(sorting, sorting思想的变形)
041：Solution is in the source code.

解体心得：
很多时候，一个序列，如果对其排序，会好处理很多。
Example: 
049：Anagrams  


题型四；链表
用一个tail指针的思想就可以把问题变得很简单，不用考虑很多case.
比如merge list.
024:Swap Nodes in Pairs 
025:Reverse Nodes in k-Group 

不会做的题：
076：Minimum Window Substring 
这道题完全不知道从何下手。听说暴力搜索O(n2),可是我怎么发现不了呢？
