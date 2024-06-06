#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//this is a tutorial to teach dynamic programming
/*
Dynamic Programming: solving problems by combining the solutions to subproblems,
it applies when the subproblems overlap. A dynamic-programming algorithm solves
each subsubproblem just once and then saves its answer in a table, avoid computing
the subsubproblems again and again!
*/


/*
Question: Cutting a Rod
Given a rod of length n inches and an array of prices that includes prices of
all pieces of size smaller than n. Determine the maximum value obtainable by
cutting up the rod and selling the pieces
*/



//if we simply use the recursive method to do it
Cut-Rod(p, n){//p is the price array
    if(n==0){
        return 0;//it checks if the length of the rod(n) is zero, 0 indicates that no further cuts can be made, it is the base case for recursion
    }
    q = negative infinity;//initialize the maximum revenue
    for i = 1 to n:
        q = max(q, p[i] + Cut-Rod(p, n-i))//use recursive method to get the maximum revenue q
    return q;
}//the time complexity is O(2^n)


/*
but the above method is wasting the time, it calculates the subsubproblems repeatedly
*/
//so we use the dynamic programming: Top-Down Cut-Rod method
memoized-cut-rod(p, n){
    let r[0,...,n] be a new array//it is an auxiliary array that used to store and retrieve prviously computed revenue for different rod lengths
    for i = 0 to n:
        r[i] = negative infinity;//initialize the r array
    return memoized-cut-rod-aux(p, n, r);
}
memoized-cut-rod-aux(p, n, r){
    if r[n] >= 0://checks if r[n] >= 0 (line 1), it is checking if the maximum revenue for rod length n has already been computed 
        return r[n];// to check if the value for rod length n has already been computed and stored
    if n == 0://to check if there is no more rod to cut
        q = 0//so assign the revenue to be 0
    else:
        q = negative infinity;//initialize the revenue q
        for i = 1 to n:
            q = max(q, p[i] + memoized-cut-rod-aux(p, n-i, r))//recursively call the function
    r[n] = q;//update the r[n], because we want to find the max.revenue when length is n, so we return r[n]
    return q;//return the maximum revenue
}

//another dynamic programming: bottom-up-cut-rod method
bottom-up-cut-rod(p, n){
    let r[0,...,n] be a new array;//it is an auxiliary array that store the max.revenue of each length of rod
    r[0] = 0
    for j = 1 to n:
        q = nagative infinity;//initialize the revenue q
        for i = 1 to j:
            q = max(q, p[i]+r[j-i])//recursively call the function
        r[j] = q;//update the r[j]
    return r[n];
}