#include<stdio.h>

int main() {
    int b[3][3] = {0}, i, j, k;

    b[0][1] = 10;
    b[1][2] = 15;
    b[2][0] = 12;

    for(k=0;k<3;k++)
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                if(b[i][k] && b[k][j] && i!=j)
                    if(b[i][k]+b[k][j] < b[i][j] || b[i][j]==0)
                        b[i][j] = b[i][k] + b[k][j];

    for(i=0;i<3;i++){
        printf("Minimum Cost With Respect to Node: %d\n", i);
        for(j=0;j<3;j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    return 0;
}
