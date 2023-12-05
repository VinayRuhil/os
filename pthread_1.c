#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000

// Structure to pass data to the thread
struct ThreadData {
    int *array;
    int start;
    int end;
    int sum;
};

// Function to calculate the sum of a sublist
void *sumSublist(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;

    // Calculate the sum of the sublist
    for (int i = data->start; i < data->end; ++i) {
        data->sum += data->array[i];
    }

    return NULL;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid input for the number of elements.\n");
        return 1;
    }

    int array[MAX_SIZE];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    // Create thread data structures
    pthread_t thread1, thread2;
    struct ThreadData data1, data2;

    // Divide the array into two equal parts
    int mid = n / 2;

    // Assign data to the first thread
    data1.array = array;
    data1.start = 0;
    data1.end = mid;
    data1.sum = 0;

    // Assign data to the second thread
    data2.array = array;
    data2.start = mid;
    data2.end = n;
    data2.sum = 0;

    // Create threads
    pthread_create(&thread1, NULL, sumSublist, &data1);
    pthread_create(&thread2, NULL, sumSublist, &data2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Calculate the final sum
    int totalSum = data1.sum + data2.sum;

    // Print the result
    printf("The sum of the elements is: %d\n", totalSum);

    return 0;
}
