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

void insertionSort(int*ptr,int size)
{   

    int i,j,temp;

     for (i=1;i<size;i++)
     {
         temp=*(ptr+i);// sahruaat ma srek round mate temp n check mate assign krvu  pdse jem k first
         // time temp=1 and 0 mate second time temp=2 and 1,0 mate third time temp=3 and 2,1,0...
         j=i-1;
         while(j>=0&&temp <= *(ptr+j)) // left side sorted area ma conditon check
         //e.g. temp=5 jo hoy to 4>=temp 3>=temp 2>=temp 1>=temp 0>=temp e rite check thse
         {
            *(ptr+j+1)=*(ptr+j); // 3 moto hoy to ene 4 ni jgyaye set kri 4 ne pchi 2 sathe.. 1 sathe.. and 0 sathe... compare kri
            // eni jagyey nki kri ene set krvu
            j--;
         }

        *(ptr+j+1)=temp;// compare and swapp pchi temp vala n to kya mukso ?? 
        //atle sorted side ma eni jagiya gotvani ky rite ?? j-- krine and jo na mle to means k sauthi nano element hse atle 
        //0 index pr ave a mate aa line muki che km k j=-1 hse (loop exit) ptr=0 hse atle ptr+(-1)+1 = ptr + 0 = element
     }  

}
int main()
{
    int array[10]={10,99,88,6,8,451,23,77,70,100};
    insertionSort(array,10);
    showArray(array,10);
    return 0;
}