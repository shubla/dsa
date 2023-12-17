#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
 
int partition(int arr[], int low, int high) {
    
    int pivot = arr[low];
    int i = low;
    int j=high;  
     
     while(i<j)
{
    while(arr[i]<=pivot && i<=high-1)
    {
        i++;
    }
        while(arr[j]>pivot && j>=low+1)
    {
        j--;
    }
    if(i<j)
    {
      int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    }
}
int t = arr[low];
    arr[low] = arr[j];
    arr[j] = t;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
     int choice, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nSorting:\n");
        printf("1. Insertion Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionSort(arr, n);
                printf(" Sorted Array:\n");
                break;
            case 2:
                mergeSort(arr, 0, n - 1);
                printf("Sorted Array:\n");
                break;
            case 3:
                quickSort(arr, 0, n - 1);
                printf("Sorted Array:\n");
                break;
            case 4:
              return 0;
                break;
            default:
                printf("Enter the correct choice\n");
        }

            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        

    } while (choice != 4);

    return 0;
}
