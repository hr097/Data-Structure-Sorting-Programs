#include<stdio.h>
#include<stdlib.h>

//suppose this is a max heap

struct Heap
{
    int *array;
    int indxOfArray;
    int sizeOfArray;   
};


void printHeap(struct Heap *heap,int indx)
{  
  if(indx<heap->sizeOfArray)  
  printf("\nelement : %d",*(heap->array+indx));
}

void showHeap(struct Heap *heap)
{

printf("\n");

 int i=0;

 while(i< (heap->sizeOfArray))
 {  
    printHeap(heap,i);
    printHeap(heap,i+1);
    printHeap(heap,i+2);
    i = i+3;
 }
 
}


void heapify(struct Heap *heap,int indx_check)
{
  if(indx_check != 0)
  {     
        int pos;

            pos = (indx_check-1) / 2;
            while(*(heap->array+pos) < *(heap->array+indx_check))
            {
                int temp = *(heap->array+pos);
                *(heap->array+pos) = *(heap->array+indx_check);
                *(heap->array+indx_check) = temp;

                indx_check = pos ;
                pos = (indx_check-1) / 2;
                //showHeap(heap);
            }        
  }
}

void heapify2(struct Heap *heap,int max)
{
  int indx_check = 0;
  if(indx_check >= 0 && indx_check < heap->indxOfArray)
  {     
         
         int temp;
         
         while(*(heap->array+indx_check) < *(heap->array+(indx_check * 2 + 1)) || *(heap->array+indx_check) < *(heap->array+((indx_check * 2 + 1)+1)))
         {
         //printf("\n\n root : %d \t left : %d \t right : %d",*(heap->array+indx_check),*(heap->array+(indx_check * 2 + 1)),*(heap->array+((indx_check * 2 + 1)+1)) );  
         //printf("\n\n left indx : %d \t right indx : %d",(indx_check * 2 + 1),(indx_check * 2 + 1)+1);

         if((indx_check * 2 + 1) >= max ||((indx_check * 2 + 1)+1) >= max)
         break;
         
         if(*(heap->array + (indx_check * 2 + 1)) > *(heap->array + (indx_check * 2 + 1)+1))
         {
             temp = *(heap->array + indx_check); 
             *(heap->array + indx_check) = *(heap->array + (indx_check * 2 + 1));
             *(heap->array + (indx_check * 2 + 1)) = temp;
             indx_check = (indx_check * 2 + 1);
         }
         else
         {
             temp = *(heap->array + indx_check); 
             *(heap->array + indx_check) = *(heap->array + (indx_check * 2 + 1)+1);
             *(heap->array + (indx_check * 2 + 1)+1) = temp;
             indx_check  = ((indx_check * 2 + 1)+1);
         }
          //  printf("\n\n INX_check : %d ",indx_check);
        }
      
  }
}

void insertHeap(struct Heap *heap,int *ptr,int size)
{
    int i=0;
    while(i<size)
    {
        //printf("\n element %d :%d ",i,*(ptr+i));
        *(heap->array+i) = *(ptr+i);
        ++(heap->indxOfArray);
        heapify(heap,i);
        i++;
    }

}

void heapSort(struct Heap *heap)
{   
    int i=(heap->indxOfArray-1),temp;
    while(i>=0)
    {
    // printf("\n before delete : ");
    // showHeap(heap);
    temp = *(heap->array+0);
    *(heap->array+0) = *(heap->array+i);
    *(heap->array+i) = temp;
    // printf("\n after shifting : ");
    // showHeap(heap);
    if(i==2) break; // bcz atlast root and left and right will be sorted so no need to do anything more
    heapify2(heap,--(heap->indxOfArray));
    // printf("\n after heapify2: ");
    // showHeap(heap);  
    i--;
    }

}
struct Heap* createHeap(int SIZE)
{   
    
    struct Heap *heap = (struct Heap*)malloc(sizeof(struct Heap));

    heap->array = (int*)malloc(sizeof(int)*SIZE);
    
    heap->indxOfArray = 0;
    heap->sizeOfArray = SIZE;
    
    return(heap);

}
int main()
{   
    int array[]={7,44,114,22,32,0,45,114,88,99,100,2,5,7,28,36,261};
    struct Heap *heap = createHeap((sizeof(array)/4));
    
    insertHeap(heap,array,(sizeof(array)/4));
    heapSort(heap);
    showHeap(heap);
    
}