#include<stdio.h>
#include<stdlib.h>

int main() {

    int i, j, k;

    /*一维数组的动态开辟和销毁*/
    puts("+----------一维数组的动态开辟和销毁------------+");
    int *arr1 = malloc(sizeof(int) * 3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    for (i = 0; i < 3; i++) {

        printf("arr1[%d] = %d\n", i, arr1[i]);
    }

    free(arr1);

    /*二维数组的动态开辟和销毁*/
    puts("\n+----------二维数组的动态开辟和销毁------------+");
    puts("方式一：使用指针的指针");
    int **arr2 = malloc(sizeof(int) * 3);
    arr2[0] = malloc(sizeof(int) * 2);
    arr2[1] = malloc(sizeof(int) * 2);
    arr2[2] = malloc(sizeof(int) * 2);

    arr2[0][0] = 1;
    arr2[0][1] = 2;
    arr2[1][0] = 3;
    arr2[1][1] = 4;
    arr2[2][1] = 5;
    arr2[2][0] = 6;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr2[%d][%d] = %d\t", i, j, arr2[i][j]);
        }
        putchar('\n');
    }

    free(arr2[0]);
    free(arr2[1]);
    free(arr2[2]);
    free(arr2);

    puts("方式二：使用数组指针");
    int (*arr3)[2] = malloc(sizeof(int) * 3 * 2);
    arr3[0][0] = 1;
    arr3[0][1] = 2;
    arr3[1][0] = 3;
    arr3[1][1] = 4;
    arr3[2][1] = 5;
    arr3[2][0] = 6;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("arr3[%d][%d] = %d\t", i, j, arr3[i][j]);
        }
        putchar('\n');
    }
    free(arr3);

    /*三维数组的动态开辟和销毁*/
    puts("\n+----------三维数组的动态开辟和销毁------------+");
    int ***arr4 = malloc(sizeof(int) * 2);

    arr4[0] = malloc(sizeof(int) * 3);
    arr4[1] = malloc(sizeof(int) * 3);

    arr4[0][0] = malloc(sizeof(int) * 2);
    arr4[0][1] = malloc(sizeof(int) * 2);
    arr4[0][2] = malloc(sizeof(int) * 2);
    arr4[1][0] = malloc(sizeof(int) * 2);
    arr4[1][1] = malloc(sizeof(int) * 2);
    arr4[1][2] = malloc(sizeof(int) * 2);

    arr4[0][0][0] = 1;
    arr4[0][0][1] = 2;
    arr4[0][1][0] = 3;
    arr4[0][1][1] = 4;
    arr4[0][2][0] = 5;
    arr4[0][2][1] = 6;

    arr4[1][0][0] = 7;
    arr4[1][0][1] = 8;
    arr4[1][1][0] = 9;
    arr4[1][1][1] = 10;
    arr4[1][2][0] = 11;
    arr4[1][2][1] = 12;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 2; k++) {
                printf("arr4[%d][%d][%d] = %d\t", i, j, k, arr4[i][j][k]);
            }
            putchar('\n');
        }
        putchar('\n');
    }

    free(arr4[0][0]);
    free(arr4[0][1]);
    free(arr4[0][2]);
    free(arr4[1][0]);
    free(arr4[1][1]);
    free(arr4[1][2]);
    free(arr4[0]);
    free(arr4[1]);
    free(arr4);

/*
  	这里的三维数组开辟和销毁都是可以的，赋值后输出也是可以的，但是会崩溃，如果你不信，可以试一下~ 
    int (**arr5)[2] = malloc(sizeof(int) * 2 * 3 * 2);
    arr5[0][0][0] = 1;
    arr5[0][0][1] = 2;
    arr5[0][1][0] = 3;
    arr5[0][1][1] = 4;
    arr5[0][2][0] = 5;
    arr5[0][2][1] = 6;

    arr5[1][0][0] = 7;
    arr5[1][0][1] = 8;
    arr5[1][1][0] = 9;
    arr5[1][1][1] = 10;
    arr5[1][2][0] = 11;
    arr5[1][2][1] = 12;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 2; k++) {
                printf("arr5[%d][%d][%d] = %d\t", i, j, k, arr5[i][j][k]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    free(arr5);
*/
   
    return 0;
}
