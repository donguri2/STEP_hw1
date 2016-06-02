#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 2000000      //辞書の数
#define WORD 275          //文字の数

typedef struct _data{
  int num;
  char *word;
}data;

data table[SIZE];

int n;                  //データの数

//データを追加
void insert_end(int x, char* str){
  if(n < SIZE -1){
    table[n+1].num = x;
    table[n+1].word = str;
    n++;
  }else{
    printf("テーブルが一杯です\n");
    exit(1);
  }
}

void read_file(char *filename){
  FILE *file;
  char *dicword;
  int r;

  file = fopen(filename,"r");
  if(file == NULL){
    printf("ファイル%sが見つかりません\n",filename);
    exit(1);
  }
  while(1){
    dicword = (char*)malloc(WORD);
    r = fscanf(file,"%s",dicword);
    if(r == EOF){
      fclose(file);
      return;
    }else if(strlen(dicword)<=16)
      insert_end(strlen(dicword),dicword);
  }
}


void write_file(char *filename){
  FILE *file;
  int i;

  file = fopen(filename,"w");
  for(i=1;i<= n;i++){
    fprintf(file,"%s\n",table[i].word);
  }
}
    
void swap(int p,int q){
  data tmp;

  tmp.num = table[p].num;
  tmp.word = table[p].word;
  table[p].num = table[q].num;
  table[p].word = table[q].word;
  table[q].num = tmp.num;
  table[q].word = tmp.word;

}
  
void sort(int left,int right){
  int i,j;
  int pivot;
  if(left<right){
    pivot = table[(left + right) / 2].num;
    i = left;
    j = right;
    while(i <= j){
      while(table[i].num > pivot)
	i++;
      while(table[j].num < pivot)
	j--;
      if(i <= j){
	swap(i,j);
	i++;
	j--;
      }
    }
    sort(left,j);
    sort(i,right);
  }
}

void quicksort(){
  sort(1,n);
}

int main(void){
  n =0;
  read_file("/usr/share/dict/words");
  quicksort();
  write_file("sorted_dict.txt");
}
