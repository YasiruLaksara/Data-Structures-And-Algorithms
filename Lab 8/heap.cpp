#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify

    int maximum=root;
    int left = (2*root)+1;
    int right = (2*root);

    if (left<n && arr[left]> arr[maximum]){  //checking whether left child is greater than the root
        maximum = left;
    }

    if (right<n  && arr[right] > arr[maximum]){  //checking whether right child is greater than the root
        maximum= right;
    }

    if(maximum != root){      //checking whether the root is largest or not
        swap(arr[root],arr[maximum]);
        heapify( arr , n, maximum);
    }
   
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap

    for(int i =n/2 -1 ; i>=0; i--){
        heapify( arr , n, i);

    }

    // extracting elements from heap one by one
    for (int i=n-1; i>=0 ;i--){
        swap(arr[0],arr[i]);

        heapify( arr , i, 0);
    }

     
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int n;  

    //creating an input array consisting with random values which are input by the user
    cout<<"Enter the number of elements to be included in the input array = ";

    cin>>n;  //Taking number of elements to be entered in the array by user(array size)

    int heap_arr[n];

    cout <<"Enter "<<n<<" numbers to be included in the array : ";

    for(int j=0;j<n;j++){  //Taking user inputs as space separated
        cin>>heap_arr[j];
    }
   
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}