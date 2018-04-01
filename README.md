# UVa_Solutions

This repository provides the implementations for UVa questions.

Here is the UVa online judge link: https://uva.onlinejudge.org

## Erdos Number
### Here are brief steps:
- For one scenario, the algorithm reads description of papers and stores the names into a `vector< vector<string> > `
which is a two dimensional array. 
- The algorithm processes the names to construct an edge list, which is stored using `map< string, set<string> >`, 
a two dimensional red-black tree. 
- A BFS is performed to calculate the Erdos number for every person. 
- the Erdos number for required people are printed. Suppose there are N people and P papers. 
So there are at most `N2` relations. 
### Time complexity:
- The time took to construct the two dimensional tree is `O(PN2logN)`. 
- The time took for calculating the Erdos number is then `O(NlogN)`

## Distinct subsequence
### Here are brief steps:
- For string S and its subsequence T, the size of S is supposed to be n and the size of T to be m. 
Also, the number of distinct `T` in `S` is assumed to be `num(S[n], T[m])`. 
- The following recurrence equation is calculated. 
If the last character of S equals to the last character of `T`, then
```
num(S[n], T[m]) = num(S[n-1], T[m-1]) + num(S[n-1], T[m])
```
Else,
	num(S[n], T[m]) = num(S[n-1], T[m])
then it is solved by dynamic programming. 
### Time complexity and Space complexity:
The time complexity for the algorithm is `O(nm)`. Space complexity is `O(m+n)`.
