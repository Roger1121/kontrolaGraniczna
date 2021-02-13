#include<bits/stdc++.h>
using namespace std;

struct kam_p
{
    int typ;
    string tablica;
    long long predkosc;
    long double czas;
    long double czas2;
    bool used;
};

struct kam_t
{
    int typ;
    string tablica;
    long double czas;
    bool used;
};

int comp(string a, string b)
{
    int wynik=0;
    int x=min(a.size(), b.size());
    for(int i=0; i<x; i++)
    {
        if(a[i]!=b[i]) wynik++;
    }
    return wynik;
}



int n, odl, r, f;
char temp;
kam_p auta[2000006];
kam_t auta2[2000006];

void Qsort(int l, int p)
{
    int n=l;
    for(int i=l+1; i<=p; i++)
    {
        if(auta[i].czas2<=auta[l].czas2)
        {
            n++;
            swap(auta[n], auta[i]);
        }
    }swap(auta[l], auta[n]);
    if(n-l>=2) Qsort(l, n-1);
    if(p-n>=2) Qsort(n+1, p);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>odl; n*=2;

    for(int i=1; i<=n; i++)
    {
        cin>>temp;
        if(temp=='R')
        {
            cin>>auta2[++r].typ;
            cin>>auta2[r].tablica;
            auta2[r].used=false;
        }
        else
        {
            cin>>auta[++f].typ;
            cin>>auta[f].tablica;
            cin>>auta[f].predkosc;
            cin>>auta[f].czas;
            auta[f].used=false;
            auta[f].czas*=1.0;
        }
    }
    for(int i=1; i<=f; i++)
    {
        auta[i].czas2=(1.0*3600*odl/auta[i].predkosc)+auta[i].czas;
    }
    Qsort(1, f);
    for(int i=1; i<=f; i++)
    {
        for(int j=1; j<=r; j++)
        {
            if(auta[i].tablica==auta2[j].tablica&&auta[i].used==false&&auta2[j].used==false)
            {
                if(auta[i].typ==1) cout<<"DOKLADNE DOPASOWANIE (OSOBOWY): "<<auta[i].tablica<<" - "<<auta2[j].tablica<<"\n";
                else cout<<"DOKLADNE DOPASOWANIE (CIEZAROWY): "<<auta[i].tablica<<" - "<<auta2[j].tablica<<"\n";
                auta[i].used=true;
                auta2[j].used=true;
            }
        }
    }
    for(int k=1; k<=7; k++)
    {
        for(int i=1; i<=f; i++)
        {
            if(auta[i].typ==2||auta[i].used==true) continue;
            for(int j=1; j<=r; j++)
            {
                if(auta2[j].typ==2||auta2[j].used==true) continue;
                if(comp(auta[i].tablica, auta2[j].tablica)==k)
                {
                    cout<<"PRAWDOPODOBNE DOPASOWANIE (OSOBOWY): "<<auta[i].tablica<<" - "<<auta2[j].tablica<<"\n";
                    auta[i].used=true;
                    auta2[j].used=true;
                    break;
                }
            }
        }
    }
    for(int i=1; i<=f; i++)
    {
        if(auta[i].used==true) continue;
        for(int j=1; j<=r; j++)
        {
            if(auta2[j].used==true) continue;
            cout<<"PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): "<<auta[i].tablica<<" - "<<auta2[j].tablica<<"\n";
            auta[i].used=true;
            auta2[j].used=true;
            break;
        }
    }
}
