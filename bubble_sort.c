#include<stdio.h>

// simple sort
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

void bubbleSort(int *ptr,int size) // time consuming
{
    int round,swap,i;

    for(round=1;round<size;round++)// round will be less than size 1,2,3<4  (3 times)
    {
        for(i=0;i<=(size-1)-round;i++)
        {
            if(*(ptr+i) > *(ptr+i+1))
            {
                 swap = *(ptr+i) ;
                *(ptr+i) = *(ptr+i+1) ;
                *(ptr+i+1) = swap ;
            }
        }
    }
    printf("\n%d round scanned in normal bubble sort !",round);
}

void bubbleSort2(int *ptr,int size) // less time consuming than first
{
    int round,swap,i,flag;

    for(round=1;round<size;round++)// round will be less than size 1,2,3<4  (3 times)
    {
        flag=0;
        
        for(i=0;i<=(size-1)-round;i++)
        {
            if(*(ptr+i) > *(ptr+i+1))
            {
                 swap = *(ptr+i) ;
                *(ptr+i) = *(ptr+i+1) ;
                *(ptr+i+1) = swap ;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\n%d round scanned in modified bubble sort!",round);
            return;
        }
    }
}
 //? round 1 inner loop step total N-1-ROUND (10-1-1=9 step)

 // 10 99 
 // 10 88 99
 // 10 88 6 99
 // 10 88 6 99 126
 // 10 88 6 99 126 451
 // 10 88 6 99 126 23 451
 // 10 88 6 99 126 23 77 451
 // 10 88 6 99 126 23 77 70 451
 // 10 88 6 99 126 23 77 70 100 451  // flag 1


//? round 2 inner loop step total N-1-ROUND (10-1-2=8 step)

 // 10 88 
 // 10 6 88
 // 10 6 88 99
 // 10 6 88 99 126
 // 10 6 88 99 23 126
 // 10 6 88 99 23 77 126
 // 10 6 88 99 23 77 70 126
 // 10 6 88 99 23 77 70 100 126 // flag 1


//? round 3 inner loop step total N-1-ROUND (10-1-3=7 step)

 // 6 10
 // 6 10 88
 // 6 10 88 99
 // 6 10 88 23 99
 // 6 10 88 23 77 99
 // 6 10 88 23 77 70 99
 // 6 10 88 23 77 70 99 100 // flag 1

//? round 4 inner loop step total N-1-ROUND (10-1-4=6 step)

 // 6 10
 // 6 10 88
 // 6 10 23 88
 // 6 10 23 77 88
 // 6 10 23 77 70 88
 // 6 10 23 77 70 88 99  // flag 1

//? round 5 inner loop step total N-1-ROUND (10-1-5=5 step)

 // 6 10 
 // 6 10 23 
 // 6 10 23 77 
 // 6 10 23 70 77 
 // 6 10 23 77 77 88  // flag 1 



//? round 6 inner loop step total N-1-ROUND (10-1-6=4 step)
// 6 10 
// 6 10 23 
// 6 10 23 77 
// 6 10 23 70 77  // flag 0 

 //! no need to sort for next round as it is already sorted in round 6

int main()
{

    int array[10]={10,99,88,6,126,451,23,77,70,100};
    bubbleSort2(array,10);
    
    int array2[10]={10,99,88,6,126,451,23,77,70,100};
    bubbleSort(array2,10);

    showArray(array,10);
    showArray(array2,10);


}