<h2><a href="https://www.geeksforgeeks.org/problems/pick-values4112/1?page=1&category=Dynamic%20Programming&sortBy=difficulty">Pick Values</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>arr[]</strong> of <strong>N</strong> positive integers. Select&nbsp;values from the array such that their sum is minimum. You must pick at least 1 value from each group of 4 consecutive elements.&nbsp;</span><br>
<br>
<br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
Arr[] = {1, 2, 3, 1, 2}
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 2 groups of 4
in the given array. The 1st group is
[1 2 3 1] and 2nd is [2 3 1 2].
Selecting the 4th element in the 
array will give the least sum as 
it belongs to both groups.
</span></pre>

<p><br>
<br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 6
Arr[] = {8, 6, 9, 10, 6, 7}
<strong>Output:</strong> 9
<strong>Explanation:</strong>&nbsp;There are 3 groups of 4
consecutive elements. 9 at index 2 
is the smallest element that is 
present in all 3 groups. 
</span>

</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>pickValues()</strong>&nbsp;which takes the array of integers&nbsp;<strong>arr[]&nbsp;</strong>and its size&nbsp;<strong>n&nbsp;</strong>as input parameters and returns an integer denoting the minimum sum.</span></p>

<p><br>
<br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><br>
<br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N<strong> </strong>≤ 10<sup>5</sup><br>
1 ≤ Arr[i]<strong> </strong>≤ 10<sup>3</sup></span></p>

<p>&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;