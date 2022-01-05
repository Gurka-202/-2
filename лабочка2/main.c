                                        //Ырср 2222222
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define eps 0.0001

unsigned int method_select (void);
double f(double x);
void print_result(double a, double b, unsigned int n, double I);
double left_rectangle (double a, double b, unsigned int n);
double right_rectangle (double a, double b, unsigned int n);
double trapezoid (double a, double b, unsigned int n );
double simpson (double a, double b, unsigned int n );

int main()
{

unsigned int num_of_method;
    const double a=1;
    const double b=2;
    unsigned int n=10000;
    double I1, I2, I;
    unsigned int N;

    num_of_method  =  method_select();

    if (num_of_method == 1 ){
        I = left_rectangle(a, b, n);
        print_result(a, b, n, I);

 N = 0;
          do{
          N = N + 2;
          I1 = left_rectangle(a, b, N);
          I2 = left_rectangle(a, b, N + 2);
        }
        while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

    }
    if(num_of_method == 2 ){
        I = right_rectangle(a, b, n);
        print_result(a, b, n, I);

 N = 0;
          do{
          N = N + 2;
          I1 = right_rectangle(a, b, N);
          I2 = right_rectangle(a, b, N + 2);
        }
        while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);
    }
    if(num_of_method == 3 ){
        I = trapezoid(a, b, n);
        print_result(a, b, n, I);
        N = 0;
          do{
          N = N + 2;
          I1 = trapezoid(a, b, N);
          I2 = trapezoid(a, b, N + 2);
        }
        while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

    }

  if(num_of_method == 4 ){
        I = simpson(a, b, n);
        print_result(a, b, n, I);
        N = 0;
          do{
          N = N + 2;
          I1 = simpson(a, b, N);
          I2 = simpson(a, b, N + 2);
          }

        while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);


  }

    return 0;

    }
//----------------------------------------------------------------------------------
unsigned int method_select(void)
    {
    unsigned int temp;
    printf("\n\n Choose method:\n1 - left \n2 - right \n3 - trap \n4 - Simpson >");
    scanf("%u", &temp);
    while ( temp<1 || temp>4 ){
            printf("\nInvalid data!!!! Choose method 1, 2, 3 or 4 ");
            scanf("%u", &temp);
    }
     switch(temp){

      case 1:
             printf("\nYou chose Method Of LEFT RECTANGLE");
             break;

      case 2:
             printf("\nYou chose Method Of RIGHT RECTANGLE");
             break;

      case 3:
             printf("\nYou chose Method Of TRAPEZOID");
             break;

      case 4:
             printf("\nYou chose Method Of SIMPSON");
             break;
    }
    return temp;
    }
    //-------------------------------------------------------------------------------
double f( double x )
{
    double y;

    y = exp(pow(x,2))*x;

    return y;
}
//------------------------------------------------------------------------------------
double left_rectangle( double a, double b, unsigned n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h = ( b - a ) / n;
    x = a;
    for ( k = 0; k <= n-1; k++ ){
        sum = sum + f(x);
        x = x + h;

    }
  return sum * h;
}
//-------------------------------------------------------------------------------
void print_result( double a, double b, unsigned int n, double I )
{
    system("cls");
    printf("\n***********************");
    printf("\n*       Results       *");
    printf("\n***********************\n");
    printf("a=%.19f  b=%.19f   n=%u    I = %.86f", a, b, n, I);
}

double right_rectangle( double a, double b, unsigned n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h = ( b - a ) / n;
    x = a;
    for ( k = 1; k <= n; k++ ){
        sum = sum + f(x);
        x = x + h;

    }
  return sum * h;
}
double trapezoid( double a, double b, unsigned n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h = ( b - a ) / n;
    double I1 =  f(a)+f(b) ;
    for (int k=1; k<=n-1; k++){
        I1+=2*f(a+k*h);
    }
    I1*=h/2;
    return I1;

    }


double simpson( double a, double b, unsigned n)
{
    double h;
    unsigned int k;
    double x;
    double I = 0, I1, I2;
    h = ( b - a ) / n;
    x = x + h;

     for(int k=1;k<=n-1;k++){
        if(k%2==1)
            I1 = f(x);
        if(k%2==0)
            I2 = f(x);
            x = h;
    }



    I = h/3*(f(a)+4*I1+2*I2+f(b));
    return I;
}
