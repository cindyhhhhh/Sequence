# Sequence

Problem Description:

Given N segment sets, each of them is located between [0, M ]. The i-th segment set can be represented by (Li, Ri, Wi), indicating that there are Wi segments covering the range [Li, Ri].
For any chosen subset of the segments and a real number x, we define the function f(x) as the number of chosen segments that cover the position x. Your goal is to pick a subset S containing at most K segments that maximizes
V = min f(x). 0≤x≤M


Input:

The first line contains three space-separated integers N,M and K, which represent the number of segment sets, the range of the segments, and the number of segments you can select respectively.
Each of the following N lines contains three space-separated integers Li,Ri, and Wi, indicating the location of the segments and the number of segments in the i-th segment set.

• 0≤K≤􏰂Wi
• 1 ≤ N, M ≤ 2 × 10^5
• 0≤Li <Ri ≤M 
• 1 ≤ Wi ≤ 3 × 10^13


Output:

In the first line of the output, print an integer indicating the maximum V .
In the second line, print N integers, where the i-th integer represents the number of segments you
selected in the i-th segment set. If there are many possible answers, you can print any of them.
