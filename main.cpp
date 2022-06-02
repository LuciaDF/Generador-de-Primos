

#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>


using namespace boost::multiprecision;
using namespace std;

int128_t RANDOMBITS(int b);

int128_t Exponenciacion(int128_t a,int128_t x);

bool MillerRabin(int128_t n,int s);

void EnemenosUNo(int128_t n,int128_t *u,int128_t *t);

bool Es_Compuesto(int128_t a,int128_t n,int128_t u,int128_t t);

int128_t EXPOMR(int128_t a,int128_t x,int128_t n);

int128_t RANDOMGEN_PRIMOS(int b,int s);


void PrimosNB();

void Menu();
int main(int argc, const char * argv[])
{
    Menu();
}

void Menu()
{
    int op;
    cout<<"-------MENU--------"<<endl;
    cout<<"1.- Primos de (16/32/64) bits."<<endl;
    cout<<"2.- Salir."<<endl;
    cout<<"Opcion?: ";cin>>op;
    
    if(op>=2 or op<=0)
    {
        exit(1);
    }
    PrimosNB();
    
}

int128_t Exponenciacion(int128_t a, int128_t x)
{
    int128_t t1,t2;
    if(x==0)
    {
        return 1;
    }
    else if(x%2!=0)
    {
        t1=Exponenciacion(a, x-1);
        return(t1*a);
    }
    else
    {
        t2=Exponenciacion(a, x/2);
        return (t2*t2);
    }
}

int128_t RANDOMBITS(int b)
{
    int128_t n,m;
    n=rand()%(Exponenciacion(2, b)-1);
    m=Exponenciacion(2, b-1)+1;
    n=n | m;
    
    return n;
}


void EnemenosUNo(int128_t n,int128_t *u,int128_t *t)
{
    
    *t=0;
    *u=n-1;
    while((*u&1)==0) 
    {
        (*u)>>=1;
        (*t)++;
    }
}


int128_t EXPOMR(int128_t a,int128_t x,int128_t n)
{
    int128_t r1,r2,a1;
    if (x==0)
    {
        return 1;
    }
    else if(x%2==0)
    {
        r1=EXPOMR(a, x/2, n)%n;
        return(r1*r1)%n;
    }
    else
    {
        r2=EXPOMR(a,x- 1, n)%n;
        a1=a%n;
        return (r2*a1)%n;
    }
}

bool Es_Compuesto(int128_t a,int128_t n,int128_t u,int128_t t)
{
    int128_t a1;
    if(n==0 or n==1)
    {
        return 3;
    }
    if(n==2 || n==3)
    {
        return 0;
    }
    a1=EXPOMR(a, u, n);
    if(a1==1 or a1==n-1)
    {
        return 0;
    }
    for(int64_t i=1;i<t;i++)
    {
        a1=(a1*a1)%n;
        if(a1==n-1)
        {
            return 0;
        }
    }
    
    return 1;
}

bool MillerRabin(int128_t n,int s)
{
    if(n==0 or n==1)
    {
        return 3;
    }
    if(n>=2 and n<4)
    {
        return 1;
    }
    int128_t u,t,a=0;
    EnemenosUNo(n, &u, &t);
    for(int j=1;j<s;j++)
    {
        if(n>4)
        {
            a=2 + rand() % (n-3);
        }
        if(Es_Compuesto(a, n, u, t))
        {
            return 0;
        }
    }
    return 1;
}


int128_t RANDOMGEN_PRIMOS(int b,int s)
{
    int128_t n=RANDOMBITS(b);
    while(!MillerRabin(n, s))
    {
        n=n+2;
    }
    return n;
}


void PrimosNB()
{
    int n,s;
    cout<<"Nro de bits (16/32/64): ";cin>>n;
    
    if(n==16)
    {
        s=2;
    }
    else if(n==32)
    {
        s=3;
    }
    else if (n==64)
    {
        s=5;
    }
    else
    {
        exit(1);
    }
    cout<<"------PRIMOS N DIGITOS-----"<<endl;
    
    for(int i=0;i<10;i++)
    {
        cout<<"Primo "<<i+1<<": "<<RANDOMGEN_PRIMOS(n,s)<<endl;
    }
    cout<<endl<<"----------------------------"<<endl;
    
    Menu();
}


