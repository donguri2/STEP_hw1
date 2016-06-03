#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 17

char* sort(char ret[]){      //文字をソートする関数
  int i,j;
  int len = strlen(ret);
  char tmp[1];
  for(i=0;i<len;i++){
    for(j=i;j<len;j++){
      if(ret[i]>ret[j]){
	tmp[0] = ret[i];
	ret[i] = ret[j];
	ret[j] = tmp[0];
      }
    }
  }
  return ret;
}


int main(void){
  char str1[NUM];      //辞書の言葉
  char str2[NUM];      //辞書でソート済みの言葉
  char str3[NUM];      //userの言葉 
  int len,i,j,flag=0;
  FILE* fp = fopen("sorted_dict.txt","r");

  //ファイル開く
  if(fp == NULL){
    printf("ファイルが開けませんでした\n");
    return 1;
    }
  
  //userから文字を受け取る
  printf("16文字入力してください:");
  scanf("%s",str3);
  if((len=strlen(str3))>NUM){
    printf("文字列が%dより大きいです。",NUM-1);
    exit(EXIT_FAILURE);
  }
  sort(str3);

  //文字がないか調べる
  while(fgets(str1,NUM,fp) != NULL){
    strtok(str1,"\n");
    strcpy(str2,str1);
    sort(str2);
    i = 0;
    j = 0;
    //printf("%s,%s",str2,str2);
    while(j < len){
      if(str2[i] == str3[j]){
	i++;
	j++;
      }else
	j++;
      if(i >= strlen(str1)){
	flag = 1;
	break;
      }
    }
    if(flag)
      break;
  }
  
  if(flag)
    printf("%s\n",str1);
  else
    printf("見つかりません.i=%d j=%d\n",i,j);   
  
  //ファイルクローズ
  fclose(fp);
}
