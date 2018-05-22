## 120. Triangle

### Description

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

### Analysis

From the triangle bottom to top to sum up the minimum total number. The steps are as follows:

1. Init the bottom row as mini vector.
2. loop the remain rows form bottom to top and sum up the new mininum vector.

