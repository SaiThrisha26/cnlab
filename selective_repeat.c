#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int f, N;

    // Get the number of bits for the sequence number
    printf("Enter the no. of bits for the sequence no. : ");
    scanf("%d", &N);

    // Calculate the total number of frames based on sequence bits
    f = pow(2, N - 1);

    // Sending frames
    for (int j = 0; j < f; j++) {
        printf("\nSENDER : Frame %d is sent ", j);
    }

    // Receiving frames
    for (int i = 0; i < f; i++) {
        printf("\n");
        int flag = rand() % 2; // Randomly simulate acknowledgment loss

        if (!flag) {
            printf("RECEIVER: Frame %d received correctly\n(acknowledgment %d received)\n", i, i);
        } else {
            printf("RECEIVER: Frame %d received correctly\n(acknowledgment %d lost)\n", i, i);
            printf("(sender timeouts --> Resend the frame)\n");
        }
    }

    printf("\nWant to continue");
    return 0;
}
