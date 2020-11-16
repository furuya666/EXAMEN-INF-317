#include <iostream>
#include <omp.h>

using namespace std;

int main(){
     short int fa,ca,fb,cb,i,j,k,x;
     cout <<"Numero de Filas de A: ";
     cin>>fa;

     cout <<"Numero de Columnas de A: ";
     cin>>ca;

     cout <<"Numero de Filas de B: ";
     cin>>fb;

     cout <<"Numero de Columnas de B: ";
     cin>>cb;
    
     int A[fa][ca],B[fb][cb],C[fa][cb];

     if(ca==fb){
         cout<<"introduzca los datos de A"<<endl;
         #pragma omp parallel for private(A[fa],[ca])
         {
            for(i=0;i<fa;i++){
            for(j=0;j<ca;j++){
                cout <<"A["<<i<<"]["<<j<<"]:";
                cin>> A[i][j];
            }
           }

         }
       
         cout <<"Ingrese el valor de X:  ";
          cin>> x;
          cout<<"\nintroduzca los datos de B"<<endl;
          #pragma omp parallel for private(B[fb],[cb])
          {
             for(i=0;i<fb;i++){
            for(j=0;j<cb;j++){
                cout <<"B["<<i<<"]["<<j<<"]:";
                cin>> B[i][j];
                B[i][j]=B[i][j]*x;
               }
             }
          }
       #pragma omp parallel for private(C[fa],[cb])
       {
            for(i=0;i<fa;i++){
            for(j=0;j<cb;j++){
                C[i][j]=0;
                for (k=0;k<ca;k++){
                   C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }


       }
           
          
         cout<<endl;

          for(i=0;i<fa;i++){
            for(j=0;j<cb;j++){
               cout<<"["<<C[i][j]<<"]";
            }
            cout<<endl;
        }



     }else
     {
        cout <<"La multiplicacion de matrices no se puede realizar";
        
     }
     
    system("pause");
    return 0;
}