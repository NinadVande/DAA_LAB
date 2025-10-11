<<<<<<< HEAD
#include <stdio.h>
#include <limits.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int constraint;
    printf("Enter the maximum sum constraint: ");
    scanf("%d", &constraint);

    int max_sum = INT_MIN;
    int current_sum = 0;
   
    int start_index = -1;
    int end_index = -1;
   
    int current_start = 0;

    for (int i = 0; i < size; i++) {
        current_sum += arr[i];

        if (current_sum > constraint) {
            current_sum = 0;
            current_start = i + 1;
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start_index = current_start;
            end_index = i;
        }
    }
   
    if (max_sum == INT_MIN) {
      max_sum = INT_MIN;
      start_index = -1;
      end_index = -1;
     
      for(int i = 0; i < size; i++) {
        if(arr[i] <= constraint && arr[i] > max_sum) {
            max_sum = arr[i];
            start_index = i;
            end_index = i;
        }
      }
    }

    if (max_sum == INT_MIN) {
        printf("No feasible subarray found within the given constraint.\n");
    } else {
        printf("The maximum sum of a subarray that does not exceed the constraint is: %d\n", max_sum);
       
        printf("The elements of this subarray are: ");
        for (int i = start_index; i <= end_index; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
=======
#include <stdio.h>
#include <limits.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int constraint;
    printf("Enter the maximum sum constraint: ");
    scanf("%d", &constraint);

    int max_sum = INT_MIN;
    int current_sum = 0;
   
    int start_index = -1;
    int end_index = -1;
   
    int current_start = 0;

    for (int i = 0; i < size; i++) {
        current_sum += arr[i];

        if (current_sum > constraint) {
            current_sum = 0;
            current_start = i + 1;
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start_index = current_start;
            end_index = i;
        }
    }
   
    if (max_sum == INT_MIN) {
      max_sum = INT_MIN;
      start_index = -1;
      end_index = -1;
     
      for(int i = 0; i < size; i++) {
        if(arr[i] <= constraint && arr[i] > max_sum) {
            max_sum = arr[i];
            start_index = i;
            end_index = i;
        }
      }
    }

    if (max_sum == INT_MIN) {
        printf("No feasible subarray found within the given constraint.\n");
    } else {
        printf("The maximum sum of a subarray that does not exceed the constraint is: %d\n", max_sum);
       
        printf("The elements of this subarray are: ");
        for (int i = start_index; i <= end_index; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
>>>>>>> 92a73d4 (Practical 4(Max sum subarray) is Executed)
}