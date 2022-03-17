#include <iostream>
using namespace std;
int maximum(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
	if (arr[i] > mx)
	mx = arr[i];
	return mx;
}
void counting(int arr[], int n, int exp)
{
	int output[n]; 
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
	count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
	count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) 
    {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
	arr[i] = output[i];
}
void radix(int arr[], int n)
{
	int m = maximum(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
	counting(arr, n, exp);
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	cout << arr[i] << " - ";
}
int main()
{
	int n,i,arr[50];
    cout<<"**************************************\n";
	cout<<"       *****Radix Sort*****\n";
    cout<<"**************************************\n";
    cout<<"Enter Total No. of Elements ";
    cin>>n;
    cout<<"\nEnter "<<n<<" Number of Elements:\n";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
	radix(arr, n);
    cout<<"**************************************\n";
    cout<<"Sorted Array is:-\n";
	print(arr, n);
    cout<<"\n*******************************************\n";
	return 0;
}
