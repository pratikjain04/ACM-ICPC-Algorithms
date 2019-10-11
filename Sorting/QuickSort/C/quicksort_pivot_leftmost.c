#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
void printarr(int arr[], int low, int high) {
  for (int i = low; i < high; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int partition(int arr[], int low, int high) {
  int pivotIndex = low;
  int storeIndex = pivotIndex + 1;

  for (int i = pivotIndex + 1; i < high; i++) {
    if (arr[i] < arr[pivotIndex]) {
      swap(&arr[i], &arr[storeIndex]);
      storeIndex++;
      printarr(arr, low, high);
    }
  }
  swap(&arr[pivotIndex], &arr[storeIndex - 1]);
  printarr(arr, low, high);
  return storeIndex;
}

void Quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    Quicksort(arr, low, pi - 1);
    Quicksort(arr, pi, high);
  }
}

signed main(void) {
  int n;
  scanf("%d", &n);
  int a[n];

  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  Quicksort(a, 0, n);

  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}
