#include <stdio.h>
#include <stdbool.h>

bool path_okay(int f, int n, int m, int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && f == 0)
        return true;
    return false;
}

int get_path(int A[], int i, int j, int n, int m, int k, int l, int path [][2], int count){
    int x = i;
    int y = j;
    if (x == k && y == l){
        path[count][0] = x; path[count][1] = y;
        return 1;
        }
    if (path_okay(A[x*m + y], n, m, x , y) == true){
        path[count][0] = x; path[count][1] = y;
        A[x*m + y] = 2;
        count = count + 1;
        if (get_path(A, x, y+1, n ,m, k, l, path, count) > 0){
            return 1;
            }
        if (get_path(A, x-1, y, n ,m, k, l, path, count) > 0){
            return 1;
            }
        if (get_path(A, x+1, y, n ,m, k, l, path, count) > 0){
            return 1;
            }
        if (get_path(A, x, y-1, n ,m, k, l, path, count) > 0){
            return 1;
            }
        path[count][0] = 0; path[count][1] = 0;
        count = count - 1;
        A[(path[count][0]*m) + (path[count][1])] = 0;
        if (count >= 0)
            (get_path(A, path[count][0], path[count][1], n ,m, k, l, path, count));
            return 1;
        return 0;
    }
    return 0;
}

int find_path(int n, int m, int A[], int i, int j, int k, int l, int path [][2]){
    int length = 1;
    int count = 0;
    if (A[i*m + j]==1 || A[k*m + l]==1){
        return -1;
    }
    if (i<0 || i >= n){
        return -2;
    }
    if (j<0 || j>=m){
        return -3;
    }
    if (i == k && j ==l){
        if (A[i*n + j] == 0){
            length = 1;
            path[0][0] = i;
            path[0][1] = j;
            return length;
        }
    }
    else{
        get_path(A, i, j, n, m, k, l, path, count);
        for (int u=0; (path[u][0] != k && path[u][1] != l); u++){
            length++;
        }
        for (int q=0; q < n*m; q++){
            if (A[q] == 2){
                A[q] = 0;
            }
        }
        return length+1;
    }
}