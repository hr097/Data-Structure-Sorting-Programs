#include<stdio.h>

// OMG 

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

void QUICK(int *arr,int size,int beg,int end,int *indx)
{

    int L=beg,R=end,temp;
    *(indx) = beg;
    
    while(1)
    {
    //step2 : LEFT PROCEDURE

    while(*(arr+*(indx))<=*(arr+R) && *(indx)!=R) ///indx is pointer bcz we need that updated location in quickSort function
    {
        R--; // we search min element in  array from right to left till we reach loc==R
    }

    if(*(indx)==R)  //IF THAT HAPPENS IT MEANS OUR SEARCHING AREA IS FINISHED
    {return;}

    if(*(arr+ *(indx)) > *(arr+R)) // IF VALUES FOUND MEANS... 45 97 86 23 HERE 23 IS BIGGER THAN 45 SO WE NEED TO SWAP 23 AND 45 AND UPDATE LOC WITH 45'S INDEX
    {
        temp =  *(arr+*(indx));
        *(arr+*(indx)) = *(arr+R);
        *(arr+R) = temp;
        *indx = R;
    }
    
    // RIGHT PROCEDURE

    while(*(arr+L) < *(arr+*(indx)) && L!= *(indx))
    {
        L++;
    }
    if(*(indx) == L)
    {
        return;
    }
    if(*(arr+L)>*(arr+*(indx)))
    {
        temp = *(arr+L);
        *(arr+L) = *(arr+ *(indx));
        *(arr+ *(indx)) = temp;
        *(indx) = L;
    }
    //goto step2;

    }

}

void quickSort(int *ptr,int size)
{
 int top=-1,UPPER[10],LOWER[10],beg,end,indx;
 if(size>1) // INTIAL STAKE SET UP 
 {
    top++;
    LOWER[top] = 0;
    UPPER[top] = (size-1); 
 }

 while(top!=-1) // LEFT SUBLIST WILL INPUT FIRST AND SOLVED AT LAST RIGHT SUBLIST WILL INSERT LAST AND SOLVED FIRST
 {
    beg = LOWER[top];
    end = UPPER[top];
    top--;  // POP() PROCESS
    QUICK(ptr,size,beg,end,&indx); // EACH TIME QUICK CALLED AND IT GIVES TWO SUBLIST FOR SOLVING
    
    if(beg<indx-1) // PUSHING LEFT SUBLIST IF THERE IS MORE THAN 1 ELEMENT
    {   
        top++;
        LOWER[top] = beg;
        UPPER[top] = (indx-1);
    }
    if(indx+1<end) //PUSHING RIGHT SUBLIST IF THERE IS MORE THAN 1 ELEMENT
    {
     top++;
     LOWER[top] = indx + 1;
     UPPER[top] = end;
    }

 }


}

int main()
{
    int array[10]={10,99,88,6,126,451,23,77,70,100};
    quickSort(array,10);
    showArray(array,10);
}