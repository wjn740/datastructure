#include <stdio.h>

void qsort(int a[], int low, int high)
{
  int key;
  int i;
  int j;
  int t;
  if (low >= high) {
    return; 
  }
  key = a[low];
  i=low, j=high;
  while (i < j) {
    while (a[j] >= key && i < j) {j--; }
    a[i]=a[j];
    while (a[i] <= key && i < j) {i++; }
    a[j]=a[i];
  }
  a[i]=key;
  qsort(a, low, i-1);
  qsort(a, i+1, high);
}
int quicksort(int array[], int length)
{
  qsort(array, 0, length-1);
  return 0;
}

int
main(int argc, char **argv)
{
  int a[] = {12,31,12,31,44,2,5,2,31,545,435,6244,6,10};
  int i;
  quicksort(a, sizeof(a)/sizeof(a[0]));

  for (i=0; i<sizeof(a)/sizeof(a[0]); i++) {
    printf("%ld\n", a[i]);
  }
	return 0;
}
