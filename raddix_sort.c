#include<stdio.h>
#include<stdlib.h>



int getMax(int *ptr,int size) // to get max element so that we can get round 
{ 
    int max=*(ptr),i=0; //everytime max will get new starting element as so indx 

    while (i!=size)
    {
        if(max < *(ptr+i))
        {
          max = *(ptr+i);
        }
        i++;
    }
    return(max);
}

void showArray(int *ptr,int size)
{

printf("\n");

 int i=0;
 while (i<size)
 {
     printf("\n element %d :%d ",i,*(ptr+i));
     i++;
 }
 
}

void radixSort(int *ptr,int size)
{
    int maxElem  = getMax(ptr,size); // means radix sort will have to perform X round according to element 
    //e.g. 451 = 3 digit value 100->10->1  (right to left)
    int round,i=0,rem;


    for(round=1;maxElem/round>0;round*=10) // to decided round 3 digit max number means 3 time raddix sort
    {   
        int count[10]={0},result[size]; // re intialized for each round
        while(i<size)
        {result[i]=0;
        i++;}

        printf("\n\n pass : %d \n",round);

        for(i=0;i<size;i++) // for getting remainder and set count array if rem is 0 then count[0] increases
                            // again  rem 0 then again count[0] which is 0 then now it is 1 just like frequesncy count
        {                   // maximum 0-9 digits posibilities so count array(bucket) should be 10 size in which frequency will be counted
            rem = ((*(ptr+i)/round) % 10);
            //printf("\n rem : %d",rem);
            ++count[rem];
            //showArray(count,10);
        }
       
        for(i=1;i<10;i++) // this round start from index 1 of count it will add prev + cur and save in it cur //(counting sort properties)
        {   

           // printf("\n\n before round : %d",i);
           // showArray(count,10);
            count[i] = count[i] + count[i-1];
            //printf("\n\n after round : %d",i);
           // showArray(count,10);
        }
       
        for(i=(size-1);i>=0;i--) // this loop sets data to their proper position [***for each round 1->10->100...***] 
        {                        // seeks postion from count array and each time count will pop() like stake in its each cout[index]
          //printf("\n\n before round : %d",i);
          //showArray(count,10);

          int temp =  --count[ ((*(ptr+i)/round) % 10) ];

          //printf("\n\n after round : %d",i);
          //showArray(count,size);

          result[temp] = *(ptr+i); // transfer to temp array

          //showArray(result,size);

          //printf("\n temp : %d \t result :%d",temp,result[temp]);

          if(i==0) // this is for error stopping in each round final result will be
          {             // in result and it will no be ready for next round(1->10) here 1's output will b input for 10
          //  so we will copying that result array to original ptr at last step (i= 0) in each round so that
          // it can qualify as next round input 
              //showArray(result,size);
              int j=0;
              while(j!=size)
              {
                  *(ptr+j) = result[ j ];
                  j++;
              }

          }

          //printf("\n\n start back temp %d : %d",temp,result[temp]);
          //showArray(result,size);
        }
    }
   
}

int main()
{
    int array[]={10,99,88,6,126,451,23,77,70,100,1500,1,8,7,26,758,8,456,1089,1356,5000,2,9};
    radixSort(array,(sizeof(array)/4));
    showArray(array,(sizeof(array)/4));
}