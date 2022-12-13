#include <stdio.h>
#include <string.h>

void unionI(char*,char*,char*);
void intersectionI(char*,char*,char*);
void differenceI(char*,char*,char*);

void main() {
  char s1[20],s2[20],s3[20];
  printf("Enter the first bit string : ");
  scanf("%s",s1);
  printf("Enter the Second bit string : ");
  scanf("%s",s2);
  unionI(s1,s2,s3);
  printf("\nThe union of the strings is : %s\n",s3);
  intersectionI(s1,s2,s3);
  printf("\nThe intersection of the strings is : %s\n",s3);
  differenceI(s1,s2,s3);
  printf("\nThe Difference of the strings is : %s\n",s3);
 }
 
 void unionI(char *s1, char *s2,char *s3){
  int i,l;
  l=strlen(s1);
  for(i=0;i<l;i++){
    if (s1[i] == '1' || s2[i]=='1')
      s3[i]='1';
    else
      s3[i]='0';
  }
  s3[i]='\0';
 }
 
 void intersectionI(char *s1, char* s2,char* s3){
  int i,l;
  l=strlen(s1);
  for(i=0;i<l;i++){
    if (s1[i] == '1' && s2[i]=='1')
      s3[i]='1';
    else
      s3[i]='0';
  }
  s3[i]='\0';
 }
 
 void differenceI(char *s1, char* s2,char* s3){
  int i,l;
  l=strlen(s1);
  for(i=0;i<l;i++){
    if (s1[i] == '1' && s2[i]=='0')
      s3[i]='1';
    else
      s3[i]='0';
  }
  s3[i]='\0';
 }
  
