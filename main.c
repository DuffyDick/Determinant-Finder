//program to find the detereminant of a square matrix

#include <stdio.h>
#include <stdlib.h>

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

int detereminant_2x2(int A[50][50]){
    return (A[0][0]*A[1][1]) - (A[0][1]*A[1][0]);
}

int find_submatrix(int A[50][50],int B[50][50],int max ,int rem){
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

int algebric_complement(int A[50][50],int i){
    
}

int main(){
    int B[50][50];
    int A[50][50];
    int i = 0, j = 0, det = 0;
    printf("Inserire dimensione matrice: ");
    scanf("%d",&i);
    take_matrix(A,i);
    printf("\e[1;1H\e[2J");
    show_matrix(A,i);
    det = detereminant_2x2(A);
    printf("il detereminante e': %d\n\n",det);
    find_submatrix(A,B,i,1);
    show_matrix(B,i-1);
    return 0;
}