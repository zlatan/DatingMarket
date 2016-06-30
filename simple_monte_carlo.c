#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#define N 60000

int main(void)
{
  int M[N];
  int F[N];
  int D[N];
  int MM[10];
  int MF[10];
  int tradedown=2;
  
  int i=0;
  int total=0;
   
   for(i=0;i<10;i++)
   {
    MF[i]=0;
    MM[i]=0;
   }

  for(i=0;i<N;i++)
  {
  M[i]=arc4random_uniform(10);
  F[i]=arc4random_uniform(10);
  D[i]=M[i]-F[i];
   
    if( D[i] >= 0 && D[i] <= tradedown )
     {
      total++;
      MM[M[i]]++; 
      MF[F[i]]++; 
     }
  }
  
   for(i=0;i<10;i++)
   {
    printf("M%i: %f\n",i,( (double) MM[i]*100)/total);
    printf("F%i: %f\n",i,( (double) MF[i]*100)/total);
   }

return 0;
}
