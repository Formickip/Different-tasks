#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

void SetCP1250()
{
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    setlocale(LC_ALL, "1250");
}

void szyfrowanie(string tab[])
{
    string linia;
    string linia2;
    string tekst;
    string tekst_nowy; //po zmianaach
    int n = 0; //licznik do do re mi fa
    fstream plik1("C:\\Users\\Lenovo\\Desktop\\test.txt");
    system("cls");
    cout<<"TEKST DO ZASZYFROWANIA"<<endl;
    cout <<"****************************************************"<<endl;
    if(plik1)
    {
     while(getline(plik1,linia))
     {
         cout<<linia;
         tekst+=linia;
     }
    }
    else
    {
        cout<<"Blad odczytywanie pliku test.txt"<<endl;
    }
    cout<<endl<<endl;
    system("PAUSE");
    for(int i=0;i<tekst.length();i++)
    {
        if(n==8)
        {
            n=0;
        }
        if(i%3==0)
        {
            tekst_nowy=tekst_nowy+tab[n]+tekst[i];
            n++;
        }
        else
        {
            tekst_nowy+=tekst[i];
        }
    }
ofstream plik("C:\\Users\\Lenovo\\Desktop\\test2.txt");
plik<<tekst_nowy;
if(plik)
{
    cout<<"Udalo sie zapisac dane do test2.txt"<<endl;
}
else
{
    cout<<"Nie udalo sie zapisac pliku test2.txt"<<endl;
}
    ifstream plik2("C:\\Users\\Lenovo\\Desktop\\test2.txt");
    system("cls");
    cout << "ZASZYFROWANY TEKST:"<<endl;
    cout <<"****************************************************"<<endl;
    if(plik2)
    {
     while(getline(plik2,linia2))
     {
         cout<<linia2;
     }
    }
    else
    {
        cout<<"Blad odczytywanie pliku test3.txt"<<endl;
    }
}


void deszyfrowanie(string tab[])
{
    string linia;
    string linia2;
    string tekst;
    int n = 0; //licznik do do re mi fa
    int i = 0;
    fstream plik1("C:\\Users\\Lenovo\\Desktop\\test2.txt");
    if(plik1)
    {
     while(getline(plik1,linia))
     {
        tekst+=linia;
     }
    }
    else
    {
        cout<<"Blad odczytywanie pliku test2.txt"<<endl;
    }
        if((tekst[0]=='d')&&(tekst[1]=='o')&&(tekst[2]=='\''))
        {
            while(i<tekst.length())
            {
                if((n%3==0))
                   {
                        tekst.erase(n,3);
                        n++;
                   }
                else
                    {
                        n++;
                    }
                i++;
            }
            ofstream plik("C:\\Users\\Lenovo\\Desktop\\test3.txt");
            plik<<tekst;
            if(plik)
            {
                cout<<"Udalo sie zapisac dane do test3.txt"<<endl;
            }
            else
            {
                cout<<"Nie udalo sie zapisac pliku test3.txt"<<endl;
            }
        }
        else
        {
            cout<<"Tekst nie jest zaszyfrowany moim kodem"<<endl;
        }
    ifstream plik2("C:\\Users\\Lenovo\\Desktop\\test3.txt");
    system("cls");
    cout << "ODSZYFROWANY TEKST:"<<endl;
    cout <<"****************************************************"<<endl;
    if(plik2)
    {
     while(getline(plik2,linia2))
     {
         cout<<linia2;
     }
    }
    else
    {
        cout<<"Blad odczytywanie pliku test3.txt"<<endl;
    }

}

int main()
{
setlocale(LC_ALL,"");
string tab[8];
tab[0]="do'";
tab[1]="re'";
tab[2]="mi'";
tab[3]="fa'";
tab[4]="so'";
tab[5]="la'";
tab[6]="si'";
tab[7]="do'";
int wybor;
cout<<"Projekt kryptografia 2 - autor Patryk Formicki"<<endl;
cout<<"***************************************************************"<<endl;
cout<<"Co chcesz zrobic ?"<<endl;
cout<<"1, aby zaszyfrowac"<<endl;
cout<<"2, aby zdeszyfrowac"<<endl;
cin>>wybor;
while(wybor>2 || wybor<1)
{
    system("cls");
    cout<<"Projekt kryptografia 2 - autor Patryk Formicki"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"Podaj liczbe 1, aby zaszyfrowac"<<endl;
    cout<<"Podaj liczbe 2, aby zdeszyfrowac"<<endl;
    cin>>wybor;
}
switch(wybor)
{
case 1:
    {
        system("cls");
        cout<<"Projekt kryptografia 2 - autor Patryk Formicki"<<endl;
        cout<<"***************************************************************"<<endl;
        cout<<"Wybrales szyfrowanie"<<endl;
        szyfrowanie(tab);
        break;
    }
case 2:
    {
        system("cls");
        cout<<"Projekt kryptografia 2 - autor Patryk Formicki"<<endl;
        cout<<"***************************************************************"<<endl;
        cout<<"Wybrales deszyfrowanie"<<endl;
        deszyfrowanie(tab);
        break;
    }
}

    return 0;
}
