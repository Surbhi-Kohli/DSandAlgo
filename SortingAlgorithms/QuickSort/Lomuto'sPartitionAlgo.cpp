int partition(int arr[],int low,int high){
int pivot=arr[high];//pivot
int i=low-1;//index of smaller element


for(int j=low;j<=high-1;j++){
//if current element is smaller that or equal to pivot
   if(arr[j]<=pivot){
   i++;
   swap(arr[i],arr[j]);
  }
}
swap(arr[i+1],arr[high]);
return (i+1);

}
