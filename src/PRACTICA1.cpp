#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  #define PREMI 64
  #define VALORMAX 1000
  #define VALORMIN 0
  
  int preu = 1;
  int b = 0; //balanç
  int numSecret;
  int numTriat;
  bool encertat = false;
  char jugar;
  
  srand (time(NULL));
  
  printf("Vols jugar? (y/n) ");
  scanf(" %c", &jugar);
  
  while (jugar != 'n' && jugar != 'N')
  { 
    if (jugar == 'y' || jugar == 'Y')
    {
      encertat = false;
      numTriat = 0;
      preu = 1;
      //Donem un valor inicial a aquestes variables per poder jugar cada ronda sense problemes.
      
      numSecret = rand () % (VALORMAX + 1) + VALORMIN; //rang [0, 1000]
      
      while (!encertat && numTriat != -1 && preu < PREMI)
      {
        printf("Per %i€, quin creus que és el número secret? (escriu '-1' per sortir) ", preu);
        scanf("%i", &numTriat);
        
        //INICI DELS DIFERENTS CASOS PEL NÚMERO TRIAT
        if (numTriat <= VALORMAX && numTriat >= VALORMIN)
        {
          b = b - preu;
          
          if (numTriat == numSecret)
          {
            b = b + PREMI;
            encertat = true;
            printf("  HAS ENCERTAT!\n");
            printf(" •El teu balanç actual és de %i€\n", b);
            printf(" •El número secret era el %i\n", numSecret);
          }
          
          else if (numTriat < numSecret)
          {
            printf(" •El número secret és MAJOR que %i\n", numTriat);
            printf(" •El teu balanç actual és de %i€\n", b);
            preu = preu * 2;
          }
          
          else if (numTriat > numSecret && numTriat)
          {
            printf(" •El número secret és MENOR que %i\n", numTriat);
            printf(" •El teu balanç actual és de %i€\n", b);
            preu = preu * 2;
          }
        }
        
        else if (numTriat == -1)
        {
          printf(" •El número secret era el %i\n", numSecret);
          printf(" •El teu balanç actual és de %i€\n", b);
        }
        
        else
        {
          printf(" •El número triat està FORA DE RANG\n");
          printf(" •El teu balanç actual és de %i€\n", b);
        }
        //FI DELS DIFERENTS CASOS PEL NÚMERO TRIAT
      }
        
      if (preu >= PREMI)
      {
        printf("Per %i€... no et compensa continuar la ronda\n", preu);
        printf(" •El número secret era el %i\n", numSecret);
        printf(" •El teu balanç actual és de %i€\n", b);
      }
      
      printf("Vols tornar a jugar? (y/n) ");
      scanf(" %c", &jugar);
      
    }
    
    else
    {
      fprintf(stderr, "Error, torna-ho a probar\n");
      printf("Vols jugar? (y/n) ");
      scanf(" %c", &jugar);
    }
  }
  
  printf("Fins aviat!\n");
  return 0;
  
}