# LeetCode-Solution
my first solution of LeetCode
2015-5-7  Problem 95,98(80 already!)

我经常在递归的结束地方忘记return!!!

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
树的遍历问题也可以用这种思想来解释。只不过是特殊的递归而已。（只有两路，不用循环）

题型二：动态规划
053：最大字串之和
121：同上
123：同上
139，140：一维DP，有些小问题要注意的，都在代码里面写了
题解：http://blog.csdn.net/linhuanmars/article/details/23162793， 局部最优和全局最优的思想，非常nice.不直接针对最后的f(n)进行建模。惯性思维就是直接针对f(n)，看能不能找到最优子结构，然后
055：method1 O(n * n),设置访问数组，保存每个元素是否可达端点。这样对每个元素，都需要遍历它后面的元素。并且空间复杂度：O(n)
     method2 O(n),O(1) 保存当前能访问的最大长度。
	 如果当前元素能达到的长度比curMax长，那么更新；如果不能，则什么也不干；如果当前元素的index == curMax,也就是说已经达到了巅峰，并且arr[index] = 0,那么代表无可救药，返回false.
097：也可以算是二维DP，不过我只用了记忆数组，还没有改成迭代，有时间改进一下。

152：Maximum Product Subarray（Maximum  Subarray的变种，局部最优+全局最优 ）
保存当前最小值和最大值就行。(Maximum  Subarray只用保存当前最大值，但乘法和加法不一样，当前一个很小值可能在之后乘以一个负数后变成一个很大的值) 

198,213:House Robber II (简单的一维DP，注意II不是二维DP)
二维动态规划：
这种类型的题目只需注意构造中间结果的顺序即可，无他。
中间结果的构造依赖于最优子结构，如果f(x) = optical(上，中，下),那么在处理f(x)的时候就要已经构造好上中下。
像下面这几道题，都不需要刻意找构造方向，直接二层循环即可。因为都是依赖上，坐，如064；或者上、左、对角线。如072
063：Unique Paths II
064：Minimum Path Sum（如果行走方向可以是四面八方，而不是只能两个方向，那怎么办？感觉这种方法不能generalize...）
072: Edit Distance 

题型三：数组(sorting, sorting思想的变形) 
041：Solution is in the source code.、
Two pointer, 滑动窗口：
209：Minimum Size Subarray Sum
001:two sum

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


135：这道题的思路很稀奇，左右分别扫描一遍，我记得我有道题也采用这种思路，很巧妙。但对这道题，我只能说，我想不上去，只能是看题解来做。其实就是一道数学题。
往右扫描一遍的时候，可以确定每个孩子至少拥有多少candy（满足右边value比左边大的candy大）,然后再往左扫描，调整一下，（满足左边value比右边大的candy大），
从右往左的时候，也不会改变上一次扫描已经满足的性质，这样就满足了比neighbour大（左右两边）的题设条件。



计算几何：
149：这道题要整理，具体原因在cpp中。




Note:
1：有时候在我的机器上可以跑过的case，但在Leetcode上提交的时候会runtime error。
这并不是leetcode的问题，而是我代码的问题，比如我new int[size]，当size == 0时，在我的机器上能过，但在leetcode上不能过；还有可能数组下标访问越界，我的有时候也可以过，但leetcode上不行。

2：在for循环中容易犯的一个错误（207：Course Schedule ）
for(int i = 0; i < numCourses && visited[i] == false; i++)
我一直以为这是在循环中对于visited[i] == true的case跳过，直接i++，继续后面的循环。但其实只要出现visited[i] == true，这个for循环就会终止。