# Searching 

## Linear Searching

Most commonly used one and the most basic one basically searches from one of end to other end one by one.
```c
int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return 1; // If its present return 1
    return 0; // If not than return 0
}
```
