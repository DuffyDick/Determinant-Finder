//program to find the detereminant of a square matrix

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int show_matrix(int A[50][50],int i){
    int j = -1;
    for (int k = 0; k < i; k++){
        for (int h = 0; h < i; h++){
            j += 1;
            if (j % i == 0)
                printf("\n");
            printf("%d ",A[k][h]);
        }
    }
    printf("\n\n");
}


int take_matrix(int A[50][50],int i){
    for (int k = 0 ; k < i; k++){
        for (int h = 0 ; h < i ; h++){
            show_matrix(A,i);
            printf("inserire A[%d][%d]: ",k,h);
            scanf("%d",&A[k][h]);
        }
    }
}


int check(int A[50][50],int i){
    int det = 0;
    if (i == 2){
        det = detereminant_2x2(A);
    }else if (i == 1){
        det = A[0][0];
    }

    return det;
}

int dim_count(int A[50][50],int i){
    int count = 0;
    while (i != 0){
        count++;
        i--;
    }
    return count;
}


int detereminant_2x2(int A[50][50]){
    return (A[0][0]*A[1][1]) - (A[0][1]*A[1][0]);
}


int find_submatrix(int A[50][50],int B[50][50],int max ,int line, int rem){
    int i = 0, j = 0;
    for (i = 0; i < rem; i++){
        for (j = 0; j < rem; j++){
            B[i][j] = A[i][j];
        }
        for (j = rem+1; j < max; j++){
            B[i][j-1] = A[i][j];
        }
    }

    for (i = rem+1; i < max; i++){
         for (j = 0; j < rem; j++){
            B[i-1][j] = A[i][j];
        }
        for (j = rem+1; j < max; j++){
            B[i-1][j-1] = A[i][j];
        }
    }
}


int algebric_complement(int A[50][50],int min,int i, int j){
    int alg = 0;
    alg = pow(-1,i+j) * min;
    return alg;
}


int main(){
    int B[50][50];
    int A[50][50];
    int i = 0, dim = 0, det = 0;
    printf("Inserire dimensione matrice: ");
    scanf("%d",&i);
    take_matrix(A,i);
    printf("\e[1;1H\e[2J");
    show_matrix(A,i);
    det = check(A,i);
    



    find_submatrix(A,B,i,1);
    dim = dim_count(B,i-1);
    
    if (dim == 2){
        det = detereminant_2x2(B,dim);
    }else{
        while(dim > 2){
            find_submatrix(B,B,dim,1);

        }

    }

    for (i = 1; ;){
        for (j = 0; j < i; j++){
            find_submatrix(A,B,dim,1,j);

        }
    }
        
    return 0;
}