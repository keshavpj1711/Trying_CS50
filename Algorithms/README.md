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

## Binary Searching

Used to find the position of a target value within a sorted array.

### Process

- Divide the search space into two halves by finding the middle index “mid”.
![](./images/image.png)
- Compare with the middle element.
- if num found return 1
- if not choose which side to work on left or right and then find its middle element 
- and repeat the above two steps till you get your element that is to be found