Problem H. Subpermutation
Input file: standard input
Output file: standard output
Memory limit: 256 megabytes

A permutation of n is a sequence of length n in which each number from 1 to n appears exactly once. A fullpermutation of n is a sequence that connects all permutations of n into one sequence in lexicographical order. Sequence p_1, p_2, . . . , p_n is lexicographically smaller than q_1, q_2, . . . , q_n if p_i < q_i where i is the minimum index satisfying pi 6= qi.

Here are some symbols used in this problem:

| Symbol | Definition | Example |
| p_n | the full-permutation of n | p_3 = {1, 2, 3, 1, 3, 2, 2, 1, 3, 2, 3, 1, 3, 1, 2, 3, 2, 1} |
| S_n | the set of all permutations of n | S_3 = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}} |
| f(s, t) | the number of contiguous subsequences in s that are equal to t | f({1, 2, 12, 1, 2}, {1, 2}) = 2 |

Now given n and m, please calculate \sum_{t \in S_m} f(p_n, t) modulo 10^9 + 7.

Input
The first line contains one integer T (1 ≤ T ≤ 10^5), indicating the number of test cases. The only line for each case contains two integers n (1 ≤ n ≤ 10^6) and m (1 ≤ m ≤ n), as described in the description

Output
For each test case, output a single integer \sum_{t \in S_m} f(p_n, t) modulo 10^9 + 7.
