#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 16

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
  char str4[NUM];      //userの言葉をソート済み
  int len,i=0,j=0,flag=0;
  FILE* fp = fopen("/usr/share/dict/words","r");

  //ファイル開く
  if(fp == NULL){
    printf("ファイルが開けませんでした\n");
    return 1;
    }
  
  //userから文字を受け取る
  printf("文字を入力してください:");
  scanf("%s",str3);
  if((len=strlen(str3))>NUM){
    printf("文字列が%dより大きいです。",NUM);
    exit(EXIT_FAILURE);
  }
  strcpy(str4,sort(str3));


  //文字がないか調べる
  while(fgets(str1,NUM,fp) != NULL){
    str1[strlen(str1)-1] = '\0';
    strcpy(str2,sort(str1));
    i = 0;
    j = 0;
    while(i < strlen(str2)){
      if(str2[i] == str4[j]){
	i++;
      }
      j++;
      if(j >= len)
	break;
    }
    if(i >= strlen(str2)){
      flag = 1;
      break;
    }
  }
    
  
  if(flag)
    printf("最終的に%s\n",str1);
  else
    printf("見つかりません\n");
  
  
  //ファイルクローズ
  fclose(fp);
  
}
