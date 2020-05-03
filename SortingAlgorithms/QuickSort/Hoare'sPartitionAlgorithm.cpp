int partition(int arr[],int low,int high)
{
  int pivot=arr[low];
  int i=low-1,j=high+1;
  
  while(true){
   //Find leftmost element greater than or equal to pivot
   do{i++};
   while(arr[i]<pivot)
   
   //Find rightmost element smaller than or equal to pivot
   do{j--};
   while(arr[j]>pivot)
   
   //if 2 pointers meet
   if(i>=j)
   return j;
   swap(arr[i],arr[j]);
  }

}
