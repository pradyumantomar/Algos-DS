
//https://www.codingninjas.com/codestudio/problems/sort-0-1_624379?leftPanelTab=0

#define swap(i,j) swap(arr[i],arr[j])

void sortZeroesAndOne(int *arr, int size)
{
    if(size<=1){
        return ;
    }
    
    int low = 0;
    int high = size-1;
    while(low<=high){
        while(arr[low]==0 and low<=high){
            low++;
        }
        while(arr[high]==1 and low<=high){
            high--;
        }
        if(low<=high){
        swap(low,high);
        low++;
        high--;
                    }
    }
}