/***
 * You have been given an empty array(ARR) and its size N. The only input taken from the user will be N and you need not worry about the array.
 * 
 * Your task is to populate the array using the integer values in the range 1 to N(both inclusive) in the order - 1,3,.......4,2.
 ***/
void arrange(int *arr, int n)
{
    int i = 1;
    int j = 0;
    // Adding odd numbers first
    while(i <= n) {
        arr[j++] = i;
        i += 2;
    }
    // Adding even numbers in reverse order
    if(n % 2 == 1)
        i = n - 1;
    else
        i = n;
    
    while(i >= 2) {
        arr[j++] = i;
        i -= 2;
    }
}