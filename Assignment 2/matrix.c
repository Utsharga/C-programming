int is_same_diagonals ( int n, int a[]){
    for(int rowNum=0; rowNum<n-1; rowNum++){
        for(int colNum=0; colNum<n-1; colNum++){
            if(a[rowNum*n + colNum] != a[rowNum*n+colNum+n+1]){
                return 0;
            }
        }
    }
    printf("Okay\n");  
    return 1;
}