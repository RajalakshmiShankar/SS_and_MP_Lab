#include<stdio.h>

int main() {
    int n, m, i, j, k;

    // Get number of processes and resources from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];

    // Get allocation matrix from the user
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Get maximum matrix from the user
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Get available resources from the user
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    int f[n], ans[n], ind = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(f[j]==0)
            {
                int flag=0;
                for(k=0;k<m;k++)
                {
                    if(need[j][k]>avail[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[ind++]=j;
                    for(y=0;y<m;y++)
                    {
                        avail[y]+=alloc[j][y];
                    }
                    f[j]=1;
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The following system is not safe\n");
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }

    return 0;
}