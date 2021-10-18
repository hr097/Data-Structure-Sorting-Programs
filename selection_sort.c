#include<stdio.h>

void showArray(int *ptr,int size)
{

printf("\n");

 int i=0;
 while (size>0)
 {
     printf("\n element :%d ",*(ptr+i));
     size--;
     i++;
 }
 
}
int min(int *ptr,int start,int size)
{
    int min=*(ptr+start),indx=start; //everytime min will get new starting element as so indx 

    while (start!=size)
    {
        if(min > *(ptr+start))
        {
          min = *(ptr+start);
          indx = start;
        }
        start++;
    }
    return(indx);
}

void selectionSort(int*ptr,int size)
{   
    int temp,min_indx,i;
    for(i=0;i<size;i++)
    {    
        
         min_indx = min(ptr,i,size); // i is 1,2,3,4 ... means everytime array will decresed from front by 1 e.g. 2 to 10 , 3 to 10 , 4 to 10 ... and so goes on 
    

         if(*(ptr+i) >= *(ptr+min_indx))
         {
             temp = *(ptr+i);
             *(ptr+i) = *(ptr+min_indx);
             *(ptr+min_indx) = temp;
         }  

    }
}
int main()
{
    int array[10]={10,99,88,6,126,451,23,77,70,100};
    selectionSort(array,10);
    showArray(array,10);
    return 0;
}