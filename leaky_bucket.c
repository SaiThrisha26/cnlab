#include <stdio.h> 
struct packet 
{ 
     int time; 
     int size; 
}p[50]; 
int main()  
{ 
    int n,m,i,k=0; 
    int bsize,outrate,bfilled; 
    printf("Enter number of packets "); 
    scanf("%d",&n); 
    printf("Enter packets in the order of their arrival time\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("Enter time and size : "); 
        scanf("%d%d",&p[i].time,&p[i].size); 
    } 
    printf("Enter size of the bucket "); 
    scanf("%d",&bsize); 
    printf("Enter outrate of bucket "); 
    scanf("%d",&outrate); 
    m=p[n-1].time; 
    i=1;//tracks time 
    k=0;//tracks size 
    bfilled=0;//no.of packets remaining in bucket after outrate 
    while(i<=m || bfilled!=0) 
    { 
        printf("\n\nAt time %d ",i); 
        if(p[k].time==i) 
        { 
            if(bsize>=bfilled+p[k].size) 
            { 
                bfilled=bfilled+p[k].size; 
                printf("\n%d byte packet is inserted",p[k].size); 
                k=k+1; 
            } 
            else 
            { 
                printf("\n%d byte packet is discarded ",p[k].size); 
               k=k+1; 
            } 
        } 
        if(bfilled==0) 
        { 
            printf("\n No packets to transmit"); 
        } 
        else if(bfilled >=outrate) 
        { 
            bfilled=bfilled-outrate; 
            printf("\n%d bytes transfered",outrate); 
         } 
         else 
         { 
            printf("\n%d bytes transfered",bfilled); 
            bfilled=0; 
         } 
        printf("\n packets in the bucket %d byte",bfilled); 
        i++; 
    } 
    return 0; 
} 
