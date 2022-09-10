#include <iostream>

using namespace std;

void llena_matriz (int(*a) [3][3]){
    int* p = **(a);
    int* s = **(a+1);
    int* t = **(a+2);

    for (int i = 1; i<=18; i++){
        if (i%2 == 0){
            *p = i;
            p++;
        }
        else{
            *s = i;
            s++;
        }
        if (i <= 9){
            *t = 0;
            t++;
        }
    }
}

void print_matriz (int(*a)[3][3]){
    for (int (*p)[3][3]=a; p<a+3; p++){
        for (int (*f)[3]=*p;f<*(p+1);f++){
            for (int *r = *f; r< *(f+1);r++){
                cout<< *r <<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    } 
}

void multip (int(*a)[3][3]){

    int* t = **(a+2);
    int salt = 3;
    int res = 0;
    
    //cout <<*s<<endl;
    for (int i = 0; i< 3;i++){
        {
            int* p = *(*(a)+i);
            
            for (int j = 0; j<3;j++)
            {
                int* s = **(a+1)+j;
                res = *(p+0) * *(s+0)+ *(p+1) * *(s+3) +*(p+2) * *(s+6);
                *t = res;
                t++;
                res=0;
            }
        }
    }
    


}

int main() {
    int A[3][3][3];
    print_matriz(A);
    llena_matriz(A);
    print_matriz(A);
    multip (A);
    print_matriz(A);
    return 0;
}