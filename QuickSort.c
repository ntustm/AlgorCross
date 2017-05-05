// void Swap(int* IntArray,int Pos1,int Pos2);
// void QuickSort(int *IntArray, int n);

void Swap(int* IntArray,int Pos1,int Pos2){
	int tmp=IntArray[Pos1];
	IntArray[Pos1]=IntArray[Pos2];
	IntArray[Pos2]=tmp;
}

void QuickSort(int *IntArray, int n){
    if(n>1){
        int Pivot=0,j;
        for(j=1;j<n;j++)
            if(IntArray[j]<IntArray[0]) 
            	Swap(IntArray,++Pivot,j);
        Swap(IntArray,0,Pivot); 
        QuickSort(IntArray,Pivot); 
        QuickSort(IntArray+Pivot+1,n-Pivot-1);
    }
}