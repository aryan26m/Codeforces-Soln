#include <stdio.h>
int main(){
    // int arr[size of array];  deccalration of array . .
    // int arr[5]={1,2,3,4,5};
    // arr=
    int n;
    scanf("%d",&n);
    // printf("%d",n);
      int arr[n];
      for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
      }



//  linear search 
//        int target=15;
//       for(int i=0;i<n;i++){
//         if (arr[i]==target)
//         {
//             printf("Element fount at index %d",(+1));
//         }
//       }



///Binary Search

    //    int low=0;
    //    int high=n-1;

    //    while (low<=high)
    //    {
    //       int mid=(low+high)/2;
    //       if (arr[mid]==target){
    //               printf("ELement found %d",(mid+1));
    //               break;
    //       }
    //       else if (arr[mid]>target)
    //       {
    //              high=mid-1;
    //       }
    //       else{
    //         low=mid+1;
    //       }
    //    }
       
    //   if (low>high)
    //   {
    //   printf("NOt found");
    //   }
        //time complexity O(logn) ;


        //sorting

        //bubble sort 
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n-i-1;j++){
        //         if (arr[j]>arr[j+1]){
        //           int temp=arr[j];
        //           arr[j]=arr[j+1];
        //           arr[j+1]=temp;
        //         }
        //     }
        // }

    // selection sort
//   [5, 7, 1, 3, 2];
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[min])
            {
               min=j;
            }
        }
        arr[i]=arr[min];
    }

        
        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
      }
        printf("\n");
 
}
