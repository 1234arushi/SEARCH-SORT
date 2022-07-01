//No. of times a sorted array is rotated
#include<bits/stdc++.h>
using namespace std;
int countrotations(int arr[],int n)
{

    int low=0;
    int high=n-1;
    while(low<=high)
    {

        int mid=(low+high)/2;
        int prev=(mid-1+n)%n;
        int next=(mid+1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
        {

            return mid;
        }
        else if(arr[mid]<=arr[high])
        {
            high=mid-1;
        }
        else if(arr[mid]>=arr[low])
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements for the array:";
    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
    }
    cout<<"No. of times this sorted array is rotated: "<<countrotations(arr,n);

}
