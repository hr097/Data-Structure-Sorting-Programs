
#include<stdio.h>
#include<stdlib.h>

// jenny's logic work perfect in ONLINE GDB compiler

void showArray(int *ptr,int size)
{
    int j=0;
    printf("\n");

    while(j<size)
    {
        printf("\n element %d : %d ",j, *(ptr+j) );
        j++;
    }
 
}

void mergeSortedArray(int array[],int min,int mid,int max)
{
   int a=min,b=(mid+1),c=min;
   int result[max]; //c for new array storing  a for first sublist b for second sublist
   
   while(a<=mid&&b<=max)
   {
       if(array[a]>=array[b])
       {
           result[c]=array[b];
           b++;
       }
       else
       {
           result[c]=array[a];
           a++;
       }
       c++;
   }

   if(a>mid)
   {
    while(b<=max)
    {
        result[c]=array[b];
        c++;
        b++;
    }
   }
   else
   {
     while(a<=mid)
     {
         result[c]=array[a];
         c++;
         a++;
     }
           
   }
  
   //showArray(result,max+1);
   //printf("\n\n\n merge list : \n");
   
   
   for(c=min;c<=max;c++)
   {   
       //printf("\n  first : %d  \tsecond : %d",array[i],result[i]);
       array[c] = result[c];
       //printf("\n element : %d",result[i]);
   }
   
   //showArray(array,max);
   
}

void mergeSort(int array[],int min_indx,int max_indx)
{   
 static int var=0;
 var++;

 if(min_indx < max_indx)
 {
     int mid_indx = (int) ( (min_indx+max_indx) / 2 );
     //printf("\n\n call %d para : min : %d mid : %d max : %d \n",var,min_indx,mid_indx,max_indx);
     mergeSort(array,min_indx,mid_indx);
    // printf("\n\n second call %d para : min : %d mid : %d max : %d \n",var,min_indx,mid_indx+1,max_indx);
     mergeSort(array,(mid_indx + 1),max_indx);
   //  printf("\n\n final call %d para : min : %d mid : %d max : %d \n",var,min_indx,mid_indx,max_indx);
     mergeSortedArray(array,min_indx,mid_indx,max_indx);
 }
 var--;
}

int main()
{
    int array[]={10,99,88,6,126,451,23,77,70,100};
    mergeSort(array,0,((sizeof(array)/4)-1));
    showArray(array,(sizeof(array)/4));
    return 0;
}