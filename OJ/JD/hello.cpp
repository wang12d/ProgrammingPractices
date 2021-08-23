#include <iostream>

class B
{
public:
    B() {
        print();
    }
    virtual void print() {
        printf("%d", 1);
    }
    void callPrint() {
        print();
    }
    virtual ~B() {
        print();
    }
};

class D: public B
{
public:
    D() {
        print();
    }
    virtual void print() {
        printf("%d", 2);
    }
    virtual ~D() {
        print();
    }
};

int
main()
{
    int a[2][3] = {1, 2, 3, 4, 5, 6}; 
    int* p = (int*) (&a + 1);
    printf("%p %p %lu\n", a, p, *(&a[0]+1));
    B* b = new(D);
    b->callPrint();
    delete b;
    printf("\n");
}