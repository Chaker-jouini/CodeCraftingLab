#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char *ch,int start,int end,char **list,int *j){
    if(start==end){
        list[*j]=strdup(ch);
        (*j)++;
    }
    else{
        for(int i=start;i<=end;i++){
            swap(ch+start,ch+i);
            permute(ch,start+1,end,list,j);
            swap(ch+start,ch+i);
        }
    }
}
int fact(int x){
    if(x==0){
        return 1;
    }
    else{
        return x*fact(x-1);
    }
}
int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
int main(){
    char *ch=malloc(101 * sizeof(char));
    printf("Donner chaine : ");
    fgets(ch,101,stdin);
    int size = stringLength(ch);
    if (size > 0 && ch[size - 1] == '\n') // Remove newline character if present
        ch[--size] = '\0';
    int max = fact(size);
    printf("Nombre de permutations : %d\n",max);
    printf("Les permutations : \n");
    char **list = (char **)malloc(max * sizeof(char *)); 
    for (int i=0;i<max;i++) {
        list[i] = (char *)malloc((size + 1)*sizeof(char));
    }
    int compteur=0;
    permute(ch,0,size-1,list,&compteur);
    for (int i=0;i<max;i++) {
        printf("%s\n", list[i]);
        free(list[i]);
    }
    free(ch);
    free(list); 
    return 0;
}