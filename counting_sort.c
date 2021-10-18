#include<stdio.h>
#include<stdlib.h>

void showArray(int *ptr,int size) //show array
{

printf("\n");

 int i=0;
 while (i<size)
 {
     printf("\n element %d :%d ",i,*(ptr+i));
     i++;
 }
 
}

void showArrayCount(int (*arr)[2],int size) //count array show 2D array
{


 int i=0;
 while (i<size&&arr[i][1]!=0)
 {
    printf("\n element %d :%d  %d",i,arr[i][0],arr[i][1]);
    i++;
 }
 
}

int checkDuplicate(int element,int (*arr)[2],int size) //checking duplicate values
{
    int i=0,flag=1;
    while(i<size)
    {
       if(arr[i][0]==element)
       { 
           flag=0;break;
       }
       i++;
    }
     return(flag);
}

void countingSort(int a[],int size)
{   

    int count[size][2],i=0,j=0,result[size];

    while(i<size) //
    {   
       // printf("\n check : %d ",check(a[i],count,i));
        if(checkDuplicate(a[i],count,i)) // for checking duplicate values if found then we won't store that in count
        {
        count[j][0] = a[i]; // values
        count[j][1] = 0;    // frequency
        j++;
        }
        i++;
    }
    for(j=0;j<size;j++) //couting the frequency of element
    {

       // printf("\n\n round : %d\n ",j);
        for(i=0;i<size;i++)
        {   
           // printf("\n content : %d\t contnet 2 : %d",count[i][0],a[i]);
            if(count[i][0]==a[j])
            { 
                ++count[i][1];
                //printf("\n incr : %d ",count[i][1]);
            } 
        }

        
    }
   // showArrayCount(count,size); 

    // setting up all required position e.g. 1 space + 2 space = 3 space now..
    // 3 space + 4 space = 7 space at last total space required is == to size
    for(j=1;count[j][1]!=0;j++) 
    {
        count[j][1] = count[j][1] + count[j-1][1];
    }
   printf("\n");
   //showArrayCount(count,size);

   for(i=(size-1);i>=0;i--) // setting up original array
   {    
        int find = a[i];
         j=0;
         while(count[j][1]!=0) // extra setp bcz we have to find indx  in count for element of original 
         //array and then after its frequency we will get on that indx
         {
           if(find==count[j][0])
           {   
               //printf("\n found on %d \telement:%d ",j,find);
               break;
           }  
           j++;
         }
        result[--count[j][1]] =  a[i]; // find e.g.45 into count and if found then j=8 index is storing that(45) 
        //so 1 decrement  frequency suppose 3  then 3-1=2 in and 
        //we got position of that element in original array
        
        //showArray(result,i);
        if(i==0) // copy to original array at last round(i==0) bcz at that time all data available in result
        {    
            j=0;
            while(j!=size)
            {
                a[j]= result[ j ];
                j++;
            }
        }
   }
}

int main()
{   
    //10,99,8,6,6,6,6,80,451,23,77,70,100,99,77,8,10,99
    int array[]={1,2,3,4,1,5,6,7,1,8,9};
    //printf("\n  max : %d",getMax(array,(sizeof(array)/4)));
    countingSort(array,(sizeof(array)/4));
    showArray(array,(sizeof(array)/4));
    return 0;
}