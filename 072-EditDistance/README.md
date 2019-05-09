## 072. Edit Distance

For `x[0..m-1], y[0..n-1]`. we define `dist[i][j]` stands for the cost edition operations of  converting `x[0..i-1]`  to `y[0..j-1]`. **Notice** Matrix dist indices start form 1.

###Two Cases

#### 1. Boundary Cases

Converting `x[0..i-1] to ""` will cost `i` operations, vice versa, converting `y[0..j-1] to ""` will cost `j` operations.

```c++
for (i = 0; i <= m; ++i)
    dist[i][0] = i;
for (j = 0; j <= n; ++j) 
    dist[0][j] = j;
```

#### 2. General Cases

For `dist[i][j]` denotes the cost operations of converting `x[0..i-1]` to `y[0..j-1]`

#### Base case

`dist[i][0] = i` , `dist[0][j] = j`, Take it for granted.

There are two subcases to compute `dist[i][j]`.

##### Subcase 1   `x[i - 1] == y[j - 1]`

 If `x[i - 1] == y[j - 1]`. Except previous cost `dist[i - 1][j - 1]`, we don't need any operations for converting. So we have:

````c++
dist[i][j] = dist[i - 1][j - 1]
````

##### Subcase 2  `x[i - 1] != y[j - 1]`

 If `x[i - 1] != y[j - 1]`. Except the previous dist, we definitely need one operation (delete, insertion, subsitution) for converting, And the previous minimum dist comes from `min(dist[i - 1][j - 1], dist[i - 1][j], dist[i][j - 1])`. So we have:

```c++
dist[i][j] = 1 + min(dist[i - 1][j - 1], dist[i - 1][j], dist[i][j - 1])
```

### Implementation 

We have the following code as described above.

```c++
int minDistance(const string &x, const string &y) {
    int m = x.size();
    int n = y.size();
    
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= m; ++i)
        dist[i][0] = i;
    for (int j = 0; j <= n; ++j) 
        dist[0][j] = j;
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <=n; ++j) {
            if (x[i - 1] == y [j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = 1 + min(
                    dist[i - 1][j - 1],
                    min(
                    	dist[i][j - 1],
                        dist[j - 1][i]
                    )
                )
            }
        }
    }
    return dist[m][n];
}
```

### Space Optimization

We cost O(m * n) space for above implementation. We notice that we can only need one column or row and a variable to  store the previous, top, left dist instead of maintaining a matrix.

For column, we use a variable `pre` to store `dist[i - 1][j - 1]`, `cur[i - 1]` to  store `dist[i - 1][j]` and `cur[i]` to store `dist[i][j - 1]`. Because every step, we only need to remeber three variables. So we have the following code.

```c++
int minDistance(const string &x, const string &y) {
    int m = x.size();
    int n = y.size();
    
    vector<int> cur(m + 1);
    
    for (int i = 0; i <= m; ++i)
        cur[i] = i;
    
    for (int j = 1; j <= n; ++j) {
        int pre = cur[0];
        cur[0] = j;
          
        for (int i = 1; i <= m; ++i) {
            int temp = cur[i];
            if (x [i - 1] == y[j - 1]) {
                cur[i] = pre;
            } else {
                cur[i] = 1 + min(pre, min(cur[i - 1], cur[i]));
            }
            pre = temp;
        }
    }
    return cur[m];
}
```

Vice versa for space `O(n)`.
