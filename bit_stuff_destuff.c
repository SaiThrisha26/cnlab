#include<stdio.h> 
void main(){ 
    int f[8]={0,1,1,1,1,1,1,0}; 
    int arr[100],n,brr[100],j=0,c=0; 
    printf("Enter Size of array:"); 
    scanf("%d",&n); 
    printf("Enter the bits in array:"); 
    for(int i=0;i<n;i++){ 
        scanf("%d",&arr[i]); 
    } 
    for(int i=0;i<8;i++){ 
        brr[j]=f[i]; 
        j++; 
    } 
    for(int i=0;i<n;i++){ 
        if(arr[i]==1) 
            c++; 
        else 
            c=0; 
        brr[j]=arr[i]; 
        j=j+1; 
        if(c==5){ 
            brr[j]=0; 
            j=j+1; 
            c=0; 
        } 
         
    } 
    for(int i=0;i<8;i++){ 
        brr[j]=f[i]; 
        j++; 
    } 
    for(int i=0;i<j;i++){ 
        printf("%d",brr[i]); 
    } 
    printf("\nDestuffing:"); 
    int crr[100],k=0; 
    c=0; 
    for(int i=8;i<j-8;i++){ 
       if(brr[i]==1) 
           c=c+1; 
        else 
            c=0; 
        crr[k]=brr[i]; 
        k++; 
        if(c==5 && brr[i+1]==0){ 
            c=0; 
            i=i+1; 
        } 
    } 
    for(int i=0;i<n;i++){ 
        printf("%d",crr[i]); 
    } 
} 
