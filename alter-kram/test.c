#include<stdio.h>


void main()
{   
   char eingabe;

   do {
      printf("Bitte ein Zeichen eingeben: ");
      scanf("%c", &eingabe);
      while ( (getchar() ) != '\n');

      printf("######################################\n");
      printf("\nDie Eingabe lautet: %c\n", eingabe);
   }
   while (eingabe != 'x');
}


//int main() {
//	printf("short:       %2d Bit\n", sizeof(short)*8);
//	printf("int:         %2d Bit\n", sizeof(int)*8);
//	printf("long:        %2d Bit\n", sizeof(long)*8);
//	printf("long long:   %2d Bit\n", sizeof(long long)*8);
//	return 0;
//}
