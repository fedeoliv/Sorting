#include<stdio.h>
#define MAXM 4
#define MAXN 5
/*  Common element in all rows of a given row-wise sorted matrix.

    Input: mat[4][5] = {{1, 2, 3, 4, 5}, {2, 4, 5, 8, 10},
                        {3, 5, 7, 9, 11}, {1, 3, 5, 7, 9}};
    Output: 5 */

/*  Returns common element in all rows of mat[M][N]. If there is no
    common element, then -1 is returned */
int findCommon(int mat[MAXM][MAXN]) {
    /* An array to store indexes of current last column */
    int column[MAXM];
    int min_row;

    for(int i = 0; i < MAXM; i++) column[i] = MAXN-1;

    min_row = 0; /* Initialize min_row as first row */

    /*  Keep finding min_row in current last column, till either
    all elements of last column become same or we hit first column. */
    while(column[min_row] >= 0) {
        /* Find minimum in current last column */
        for (i = 0; i < MAXM; i++) {
            if(mat[i][column[i]] < mat[min_row][column[min_row]])
            min_row = i;
        }

        /* eq_count is count of elements equal to minimum in current last column. */
        int eq_count = 0;

        // Travers current last column elements again to update it
        for(i = 0; i < MAXM; i++) {
            /* Decrease last column index of a row whose value is more than minimum. */
            if(mat[i][column[i]] > mat[min_row][column[min_row]]) {
                if(column[i] == 0) return -1;
                column[i] -= 1; /* Reduce last column index by 1 */
            } else eq_count++;
        }

        /* If equal count becomes M, return the value */
        if(eq_count == MAXM)
            return mat[min_row][column[min_row]];
    }
    return -1;
}

int main() {
    int mat[MAXM][MAXN] = {{1, 2, 3, 4, 5}, {2, 4, 5, 8, 10}, {3, 5, 7, 9, 11}, {1, 3, 5, 7, 9}};

    int result = findCommon(mat);
    if(result == -1) printf("Not found.\n");
    else printf("%d\n", result);
    return 0;
}
