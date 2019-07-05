void printVector(int *v, int n);

int * allocVector(int n);

void freeVector(int *v);

void copy(int *original, int* cp, int n);

void bubbleSort(int *v, int n);

void insertionSort(int *v, int n);

void selectionSort(int *v, int n);

void heapSort(int *v, int n);

#define FATHER(i) ((i - 1)/2)

#define LEFT_CHILD(i) (2*i + 1)

#define RIGHT_CHILD(i) (2*i + 2)