# UVa_Solutions

## Erdos Number

For one scenario, the algorithm first reads description of papers and stores the names into a `vector< vector<string> > `
which is a two dimensional array. 
Then, the algorithm process the names to construct an edge list, which is stored using `map< string, set<string> >`, 
a two dimensional red-black tree. 
Then a BFS is performed to calculate the Erdos number for every person. 
Finally, the Erdos number for required people are printed. Suppose there are N people and P papers. 
So there are at most `N2` relations. 
The time took to construct the two dimensional tree is `O(PN2logN)`. 
The time took for calculating the Erdos number is then `O(NlogN)`

## Distinct subsequence

For string S and its subsequence T, we suppose the size of S is n and the size of T is m. 
Also, we assume the number of distinct `T` in `S` is `num(S[n], T[m])`. 
Then we have the following recurrence equation. 
If the last character of S equals to the last character of `T`, then
```
num(S[n], T[m]) = num(S[n-1], T[m-1]) + num(S[n-1], T[m])
```
Else,
	num(S[n], T[m]) = num(S[n-1], T[m])
We can then solve it by dynamic programming. 
The time complexity for the algorithm is `O(nm)`. Space complexity is `O(m+n)`.
