/*Write a program to sort the elements of an array using the Bubble sort technique. 
Bubble sort should be implemented using a function.*/
#include <stdio.h>
void bubblesort(long list[], long n)
{
  long c, d, t;
  for (c = 0; c < n - 1; c++)
  {
    for (d = 0; d < n - c - 1; d++)
    {
      if (list[d] > list[d + 1])
      {
        t = list[d];
        list[d] = list[d + 1];
        list[d + 1] = t;
      }
    }
  }
}
int main()
{
  printf("\nProgrammer: Ujjawal Soni, SAP ID:1000014658");
  long array[1000], n, c;

  printf("\nEnter number of elements=");
  scanf("%ld", &n);

  printf("Enter %ld integers=", n);

  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);

  bubblesort(array, n);

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
    printf("%ld\n", array[c]);

  return 0;
}
