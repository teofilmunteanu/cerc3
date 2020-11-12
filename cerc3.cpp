/*
Se consideră pe axa Ox din plan n puncte distincte reprezentând centrele a n cercuri numerotate cu numerele distincte de la 1 la n. 
Pentru fiecare cerc k se cunosc abscisa xk a centrului său şi raza sa rk.

Să se scrie un program care să determine numărul y maxim de cercuri exterioare două câte două dintre cele n.

Citire:
Pe prima linie, o valoare naturală n, reprezentând numărul de cercuri, iar pe următoarele n linii câte două numere naturale, separate printr-un spaţiu, 
care reprezintă abscisa x1 a centrului primului cerc şi raza sa r1,…, abscisa xn a centrului celui de-al n-lea cerc şi raza sa rn.

Afișare:
Va fi scris numărul natural y reprezentând numărul maxim de cercuri exterioare ale căror centre sunt situate pe axa Ox.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct cerc
{
    int x,r,st,dr;
} c[1000];

bool f(cerc a,cerc b)
{
    return a.dr<b.dr;
}

int pivot(int st, int dr)
{
    int i,j,di,dj,aux;
    i=st;j=dr;di=0;dj=1;
    while(i<j)
    {
        if(c[i].dr>c[j].dr)
        {
            di=1-di;
            dj=1-dj;

            aux=c[i].x;
            c[i].x=c[j].x;
            c[j].x=aux;

            aux=c[i].r;
            c[i].r=c[j].r;
            c[j].r=aux;

            aux=c[i].st;
            c[i].st=c[j].st;
            c[j].st=aux;

            aux=c[i].dr;
            c[i].dr=c[j].dr;
            c[j].dr=aux;
        }
        i+=di;
        j-=dj;
    }
    return j;
} 

void QuickSort(int st, int dr)
{
    int p;
    p=pivot(st,dr);
    if(st<dr)
    {
        QuickSort(st,p-1);
        QuickSort(p+1,dr);
    } 
} 

int main()
{
    int n,k=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i].x;
        cin>>c[i].r;
        c[i].dr=c[i].x+c[i].r;
        c[i].st=c[i].x-c[i].r;
    }
    QuickSort(1,n);
    int u=c[1].dr;
    for(int i=2;i<=n;i++)
    {
        if(c[i].st>u)
        {
            k++;
            u=c[i].dr;
        }
    }
    cout<<k+1;
}