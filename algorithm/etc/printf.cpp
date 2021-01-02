#include <iostream>
#include "pthread/pthread.h"

using namespace std;

class A{
    public:
        A(){};
        ~A(){};
        
        static void * process(void* data);
        void asd();
        void sdf();
        int num() const;
    private:
        int a;
};
int A::num() const{
    printf("%d\n", a);
}
void A::asd(){

    pthread_t t;
    pthread_create(&t, NULL, process, (void*) this);
    pthread_detach(t);
    
    pthread_t t1;
    A* b = new A;
    pthread_create(&t1, NULL, process, (void*) b);
    pthread_detach(t1);
}
void A::sdf(){
    printf("123\n");
    num();
}
void * A::process(void* data){
    int temp =1 ;

    A* d = (A*)data;
    
    while(1){
        d->a = temp;
        temp++;
        d->sdf();
    }
        
}
int main() {
    A* a = new A ;
    a->sdf();
    a->asd();
    while(1){

    }
}