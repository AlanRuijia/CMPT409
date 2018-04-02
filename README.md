# UVa_Solutions

This repository provides the implementations for UVa questions.

Here is the UVa online judge link: https://uva.onlinejudge.org

## Erdos Number
### Brief steps:
- For each scenario, the algorithm reads description of papers and stores the names of authors into a `vector< vector<string> > `
which is a two dimensional array.
- The algorithm processes the names of authors to construct an edge list, which is stored using `map< string, set<string> >`,
a two dimensional red-black tree.
- A BFS(Breadth-First Search) is performed to calculate the Erdos number for every person.
- The Erdos number for required people are printed. if there are N people and P papers, there are at most `N2` relations.
### Time complexity:
- The time took to construct the two dimensional tree is `O(PN2logN)`.
- The time took to calculate the Erdos number is `O(NlogN)`

## Distinct Subsequence
### Brief steps:
- For string S and its subsequence T, the size of S is supposed to be n and the size of T to be m.
The number of distinct `T` in `S` is assumed to be `num(S[n], T[m])`.
- The following recurrence equation is calculated.<br>
If the last character of S equals to the last character of `T`, then
	```
	num(S[n], T[m]) = num(S[n-1], T[m-1]) + num(S[n-1], T[m])
	```
	Else,
	num(S[n], T[m]) = num(S[n-1], T[m])
then it is solved by dynamic programming.
### Time complexity and Space complexity:
The time complexity for the algorithm is `O(nm)`. Space complexity is `O(m+n)`.
