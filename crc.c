#include <stdio.h>

void division(int temp[], int gen[], int n, int r)
{
    for(int i = 0; i < n; i++)
    {
        if (gen[0] == temp[i])
        {
            for(int j = 0, k = i; j < r + 1; j++, k++)
            {
                temp[k] = temp[k] ^ gen[j];
            }       
        } 
    }
}


int main()
{
    int n, r, message[50], gen[50], temp[50];
 
    printf("Enter the number of frame bits : ");
    scanf("%d", &n);
    printf("Enter the frame : ");
    for(int i = 0; i < n; i++)
        scanf("%d", &message[i]);
    printf("Enter the number of generator bits : ");
    scanf("%d", &r);
 
    printf("Enter the generator : ");
    for(int i = 0; i < r; i++)
        scanf("%d", &gen[i]);
    r--; // Reduce generator size for CRC calculation
    
    // Append r zeros to the original message
    for(int i = 0; i < r; i++)
        message[n + i] = 0;
    
    // Copy original message to temp for CRC calculation
    for(int i = 0; i < n + r; i++)
        temp[i] = message[i];
    
    // Calculate CRC
    division(temp, gen, n, r);
    
    // Display CRC remainder
    printf("CRC : ");
    for(int i = 0; i < r; i++)
    {
        printf("%d ", temp[n + i]);
        message[n + i] = temp[n + i]; // Store CRC in the message
    }
    
    // Transmitted message (original message + CRC remainder)
    printf("\nTransmitted Message : ");
    for(int i = 0; i < n + r; i++)
        printf("%d ", message[i]);
    
    // Decoding process
    for(int i = 0; i < n + r; i++)
        temp[i] = message[i];
    
    division(temp, gen, n, r);
    
    // Check for errors in the received message
    for(int i = 0; i < r; i++)
    {
        if(temp[n + i]) // If any bit of the CRC remainder is non-zero, an error is detected
        {
            printf("Error detected in received message.");
            return 0;
        }
    }
    
    printf("\nNo error in received Message.");
    printf("\nAfter decoding crc is ");
    for(int i = 0; i < r; i++)
    {
        printf("%d ", temp[n + i]);
    }
    
    // Received message without CRC
    printf("\nReceived Message : ");
    for(int i = 0; i < n; i++)
        printf("%d ", message[i]);
    
    return 0;
}


