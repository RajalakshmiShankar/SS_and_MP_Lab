#include<stdio.h>

int main()   {
    int p[100],a[100],b[100],c[100],t[100],w[100],i,num;
    printf("Enter number of processes: ");
    scanf("%d",&num);
    
    //Processes
    printf("Enter process\n");
    for( i = 0; i < num ; i++ )   {
        scanf("%d",&p[i]);
    }
    
    //Arrival Time
    printf("Enter Arrival Time\n");
    for( i = 0; i < num ; i++ )   {
        scanf("%d",&a[i]);
    }

    //Burst Time
    printf("Enter Burst Time\n");
    for( i = 0; i < num ; i++ )   {
        scanf("%d",&b[i]);
    }

    //Completion Time
    c[0] = b[0] + a[0];
    
    for( i = 1 ; i<num ; i++ )   {
        c[i] = c[i-1] + b[i];
    }
    
    //Turn Around Time
    for( i = 0 ; i < num ; i++ )   {
         t[i] = c[i] - a[i];
    }

    //Waiting Time
    for( i = 0 ; i < num ; i++ )   {
        w[i] = t[i] - b[i];
    }

    //Table
    printf("Process\tArrival Time  Burst Time  Completion Time  TAT  Waiting Time\n");
    for( i = 0; i < num ; i++ )   {
        printf("   %d\t",p[i]);
        printf("     %d\t",a[i]);
        printf("           %d\t",b[i]);
        printf("          %d\t",c[i]);
        printf("    %d\t",t[i]);
        printf("     %d\n",w[i]);
    }  
   
    //Gantt Chart
    printf("\n\n");
    printf("Gantt Chart\n");
    //printf("--------------------\n");
    for( i = 0 ; i < num ; i++ )   {
        printf("    %d\t ",p[i]);
    }
    //printf("%d\t ",p[i]);
    printf("\n");
    printf("%d\t",a[0]);
    for( i = 0 ; i < num ; i++ )   {
        printf("%d\t",c[i]);
    }
    
}
