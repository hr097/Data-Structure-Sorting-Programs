
/*----------------------------------------------------------------

harshil sort 

TimeComplexcity : Approximatley half or less than 50%  rather than usual liner search in data duplications case

In best case : O( n log n);// input are most similar * frequency
In average case : O(n^2);    // input are average similar * frequency 
worst case : O(n)       // input are  so different input * frequency which is 1 
e.g. in some cases data is in fix range ----> like students marks 0 to 100
                            best example ----> attendence of students only data is A/P

 here we can see duplication of so much data of marks 
 ....like wise 10 students got 95 marks
 ....like wise 5 students got 100 marks
 like wise 3 students got 33 marks

 here if we want to sort stundents data according to marks then there is two cases...

 1) normally you have to compare each 10 or 5 or 3 stundents  10 to rest 9 / 5 to rest 4 / and 3 to rest 2 / 3

 so here number of comparisons are in each case 4  +  3  +  2  = 9 comparisons
 
 and obviously they will be also compared to others like 

 95 marks of 10 students will be compared to 33 marks of 3 studrnts 10 * 3 =  30 comparisons
 95 marks of 10 students will be compared to 100 marks of 5 studrnts 10 * 5 = 50 comparisons

 33 marks of 3 students will be compared to 100 marks of 5 studrnts 3 * 5 =  15 comparisons

 means total:~ 104 comparisons
 
 2) in my harshil sort case ...

 duplications will be deleted..!

 so internal comparisons will be not required e.g. 100 marks of 1 students to other students who got also 100 marks of 5 students
 95 marks of 1 students (insted of 10) will be compared to 33 marks of 1(insted of 3) students 10 * 3 =  1 comparisons
 95 marks of 1 students (insted of 10) will be compared to 100 marks of 1(insted of 5) students 10 * 3 =  1 comparisons
 33 marks of 1(insted of 3) students will be compared to 100 marks of 1(insted of 5) students 3 * 5 =  1 comparisons

 means total:~  just 3 comparisons  and place will be decided and data is sorted by marks


I HOPE THIS IS USEFULL

~ by harshil ramani & viraj tavaviya
----------------------------------------------------------------*/



#include<stdio.h>
#include<stdlib.h>

void showArray(int *ptr,int size) // show simple 1-d array
{
printf("\n");
 int i=0;
 while (i<size)
 {
     printf("\n element %d :%d ",i,*(ptr+i));
     i++;
 }
}

void showArrayCount(int (*arr)[2],int size) // show simple 2-d array
{
 int i=0;
 while (i<size&&arr[i][1]!=0)
 {
    printf("\n element %d :%d  %d",i,arr[i][0],arr[i][1]);
    i++;
 }
}
  
int checkDuplicate(int element,int (*arr)[2],int size) //return 0 if duplicate already exist else 1
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

int findMin(int (*arr)[2],int start) // finding minimum element in count[data] and returning its index
{
    int min=arr[start][0],indx=start; //everytime min will get new starting element as so indx 

    while(arr[start][1]!=0)
    {
        if(min > arr[start][0])
        {
          min = arr[start][0];
          indx = start;
        }
        start++;
    }
    return(indx);
}

void harshilSort(int a[],int size)
{   

    int count[size][2],i=0,j=0,result[size]; // count[data][frequency];

    while(i<size)
    {   
       // printf("\n check : %d ",check(a[i],count,i));
        if(checkDuplicate(a[i],count,i)) // if duplicate found means e.g. if onr time 34 is stored count[data] then no need to create another space for 34
        {
        count[j][0] = a[i]; //data copying
        count[j][1] = 0; // intially frequency is 0
        j++;
        }
        i++;
    }

    for(j=0;j<size;j++) // setting frequency for each element of a which we are comparing to count[data] and according to that set the frequency 
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

   for(i=0;count[i][1]!=0;i++) //selection sort  little bit
   {   
       //printf("\n");

       int setInd = findMin(count,i); // getting position of min data in count so that we can shift it to forward in sorted order
       // here also each time array is decresed by 1 because left side elements are sorting in each iteration
       //printf("\nmin element position : %d ",findMin(count,i));

       int data = count[setInd][0]; // data back
       int frequency = count[setInd][1]; // frequency back up

       //printf("\n setInd : %d data : %d\t  fre : %d \n",setInd,data,frequency);
       
       int temp =  count[i][0]; // swap logic of data
       count[i][0] = data; 
       count[setInd][0] = temp;

       temp =  count[i][1]; // swap logic of frequency
       count[i][1] = frequency; 
       count[setInd][1] = temp;

       //showArrayCount(count,size);
       // printf("\n");
   }


      j=0;
      for(i=0;i<size;i++) // just putting back sorted data to original array
      {   
          
          while(count[i][1]!=0) 
          {
              a[j]=count[i][0]; // here j is working like static variable //e.g. suppose count[data][frequency] ---> count[23][3] like that is so  j will 3 times incresed so 3 times we will put 23 in original array
              count[i][1]--; 
              j++;
          }
          
      }
  
}

int main()
{   

    int array[]={10,99,8,6,6,6,6,80,451,23,77,70,100,99,77,3,10,99,1,3,5,2,4,6,8,7,10};
    harshilSort(array,(sizeof(array)/4));
    showArray(array,(sizeof(array)/4));
    return 0;
}
