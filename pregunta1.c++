#include<iostream>
#include<cstring>
#include<omp.h>
using namespace std ;
int main(){
  
 char p[50];
 
 char alf[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 cout<<"ingrese nombre "<<endl;
 gets(p);
 int j;
 
 #pragma omp parallel for
 {
 for(int i=0;i<strlen(p);i++){
  j=0;
  #pragma omp parallel for
  {
  while(j<52){
   if(p[i]==alf[j] && (j<23||(j>=26 &&j<49))){
    p[i]=alf[j+3];
    j=52;
      }
   if(p[i]==alf[j] && (j>=23 && j<26)){
       if(p[i]=='x'){
        p[i]='a';
    }
    if(p[i]=='y'){
        p[i]='b';
    }
    if(p[i]=='z'){
        p[i]='c';
    }
    j=52;
   }
   if(p[i]==alf[j] && (j>=49 && j<52)){
       if(p[i]=='X'){
        p[i]='A';
    }
    if(p[i]=='Y'){
        p[i]='B';
    }
    if(p[i]=='Z'){
        p[i]='C';
    }
    j=52;
   }
      j++;
  }
 }
 }
 }
 cout<<p<<endl;
 system("PAUSE");
 return 0;
}