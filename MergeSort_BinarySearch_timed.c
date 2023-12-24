#include <stdio.h>
#include <time.h>

void input(int*);
void iterate(int [],int);
void fill(int [],int);
int search(int [],int,int,int*);
void sorting(int [],int);

int main(){
	clock_t start,end;
	double cpu_time;
	int size,nb,indice,isThere;
	
	input(&size);
	int array[size];
	fill(array,size);
	
	start=clock();
	
	sorting(array,size);
	
	end=clock();
	cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Sorting Time: %f seconds\n", cpu_time);

	
    iterate(array,size);
	input(&nb);
	

	start=clock();
	
	isThere = search(array,size,nb,&indice);
	
	end=clock();
	cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Search Time: %f nano seconds\n", cpu_time);
	

	if(isThere==1){
		printf("%d exists in the array having, its the element number %d in the sorted array.\n",nb,indice);
	}else{
		printf("%d does not exist in the array.\n",nb);
	}
	return 0;
}




int search(int tab[],int n,int x,int* i){
	int right=n-1,left=0,mid=(n-1)/2;
	while(left<=right){
		mid=left+(right-left)/2;
		if(x==tab[mid]){
			*i=mid;
			return 1;
		}
		else if(x>tab[mid]){
			left=mid+1;
			
		}else{
			right=mid-1;
		}
		
	}
	return 0;
}




void merge(int tab[],int left,int mid,int right){
	int i,j,k;
	int size_left=mid-left+1;
	int size_right=right-mid;
	int arrLeft[size_left],arrRight[size_right];
	for(i=0;i<size_left;i++){
		arrLeft[i]=tab[left+i];
	}
	for(j=0;j<size_right;j++){
		arrRight[j]=tab[mid+j+1];
	}
	i=0;j=0;k=left;
	while(i<size_left && j<size_right){
		if(arrLeft[i]<arrRight[j]){
			tab[k]=arrLeft[i];
			i++;
		}else{
			tab[k]=arrRight[j];
			j++;
		}
		k++;
	}
	while(i<size_left){
		tab[k]=arrLeft[i];
		i++;k++;
	}
	while(j<size_right){
		tab[k]=arrRight[j];
		j++;k++;
	}
}
void sorting(int tab[],int n){
	int curr_size,left,right,mid;
	for(curr_size=1;curr_size<n;curr_size=2*curr_size){
		for(left=0;left<n-1;left= left+ 2*curr_size){
			mid=left+curr_size-1;
			right=(left+ 2*curr_size -1)<(n-1) ? (left+ 2*curr_size -1) : (n-1);
			merge(tab,left,mid,right);
		}
	}
}
void input(int* n){
	do{
		printf("Enter number : ");
		scanf("%d",n);
	}while(*n<1);
}
void fill(int* tab,int n){
	for(int i=0;i<n;i++){
		printf("Enter element number %d : ",i+1);
		scanf("%d",tab+i);
	}
}
void iterate(int tab[],int n){
	for(int i=0;i<n;i++){
		printf("element %d is : %d \n",i+1,tab[i]);
	}
}