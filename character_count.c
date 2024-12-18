#include<stdio.h>
#include<string.h>

void main() {
    struct frame {
        int c;
        char s[100];
    } f[100];

    int n, i, j = 0, sum = 0, k, l;
    char str[100];
    
    printf("Enter the string:\n");
    scanf("%s", str);
    l = strlen(str);
    
    printf("Enter the number of frames:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the frame count:\n");
        scanf("%d", &f[i].c);
        sum += f[i].c;

        // Warn if total frame counts exceed the string length
        if (sum > l) {
            printf("Error: Total frame counts exceed string length.\n");
            return;
        }
    }
    j=0;
    sum = 0;  // Reset sum for processing
    for(i = 0; i < n; i++) {
        k = 0;
        while(j < sum + f[i].c && j < l) {
            f[i].s[k++] = str[j++];
        }
        f[i].s[k] = '\0';  // Null-terminate the string
        sum += f[i].c;
    }

    for(i = 0; i < n; i++) {
        printf("Frame %d: %s\n", i + 1, f[i].s);
    }
}
