// Modul2/U10_pointer.c
#include <stdio.h>

int main()
{
    int* ptr_a;
    int a = 10;
    ptr_a = &a;
    
    printf("Adresse von a: %p\n", ptr_a);
    printf("Inhalt von a: %d\n", *ptr_a);
    printf("Inhalt von a: %d\n", a);
    
    *ptr_a += 10;
    printf("Adresse von a: %p\n", ptr_a);
    printf("Inhalt von a: %d\n", *ptr_a);
    printf("Inhalt von a: %d\n", a);
    
    a +=20;
    printf("Adresse von a: %p\n", ptr_a);
    printf("Inhalt von a: %d\n", *ptr_a);
    printf("Inhalt von a: %d\n", a);

    return 0;
}



