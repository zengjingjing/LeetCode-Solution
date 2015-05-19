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

题型二：动态规划
055：method1 O(n * n),设置访问数组，保存每个元素是否可达端点。这样对每个元素，都需要遍历它后面的元素。并且空间复杂度：O(n)
     method2 O(n),O(1) 保存当前能访问的最大长度。
	 如果当前元素能达到的长度比curMax长，那么更新；如果不能，则什么也不干；如果当前元素的index == curMax,也就是说已经达到了巅峰，并且arr[index] = 0,那么代表无可救药，返回false.





解体心得：
很多时候，一个序列，如果对其排序，会好处理很多。
Example: 
049：Anagrams  

