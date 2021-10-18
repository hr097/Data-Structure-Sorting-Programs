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

void shellSort(int *ptr,int size)
{
    int i,j,gap,temp;

    for (gap=(size/2);gap>=1;gap/=2) // each gap mate
    {
        for(i=gap;i<size;i++) // each gap ni ander (traversal) index bdlvva 4-8 5-9 6-10 ....aa rite
        {
            for(j=i-gap;j>=0;j-=gap)// j e lower index 0-4 (e.g. 0 find krva)
            { // comparison round each pass  //first time j=4-4=0 atle 0 & 4 cmp //second time j=5-4=1 atle 1 and 5
             // loop ma i=gap valano last round hse tyre j=4 hse atle condtion j-gap=0 atle ek round extra chalse
             // jema 0 and 4 pcha compare thse check krva k first sort tyo e eni psotion(0) pr right che k nhi 4 sathe compare krine
                if(*(ptr+j) >= *(ptr+j+gap))
                {
                    temp = *(ptr+j);
                    *(ptr+j) = *(ptr+j+gap);
                    *(ptr+j+gap) = temp;
                }
            }
        }
    }
}

int main()
{
    int array[10]={10,99,88,6,126,451,23,77,70,100};
    shellSort(array,10);
    showArray(array,10);
}