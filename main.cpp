#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "Farbe.h"

//
//Vincent Musch
//Spielfeld Qwikle (1)
//15.02.2012

//prototyp
void ZeigeSpielfeld();
void Feldauswahl();
//void darfsetzen(int x, int y, int farbe, int form);

using namespace std;

//Variablen Deklarieren
 int x = 0;
 int y = 0;

char cBewegung;
int Punkte;
bool cansetr1 = true;
bool cansetr2 = true;
bool cansetr3 = true;
bool cansetr4 = true;
bool cansetr5 = true;

bool cansetb1 = true;
bool cansetb2 = true;
bool cansetb3 = true;
bool cansetb4 = true;
bool cansetb5 = true;

bool cansetg1 = true;
bool cansetg2 = true;
bool cansetg3 = true;
bool cansetg4 = true;
bool cansetg5 = true;

bool cansetge1 = true;
bool cansetge2 = true;
bool cansetge3 = true;
bool cansetge4 = true;
bool cansetge5 = true;

bool cansetp1 = true;
bool cansetp2 = true;
bool cansetp3 = true;
bool cansetp4 = true;
bool cansetp5 = true;

#define FarbeBlau    1
#define FarbeRot     2
#define Form1        1

struct Spielstein
{
       int farbe;
       char form;
       
       };

//Variablen mit "Eigenschaften"
struct S_Feld
{
       bool Besetzt;
       bool Ausgeweahlt;
       bool punkterechnung;
       
       Spielstein spielstein;
       
};


//Unveränderbare variablen
const int iBreite = 15;
const int iHoehe = 15;


//Arrar
//fürs spielfeld
S_Feld Spielfeld[iBreite][iHoehe];


//für ausgewähltes feld
S_Feld Ausgewaehlt[iBreite][iHoehe];





int main(int argc, char *argv[])
{
    //Lokale Variable
    char chauswahl;
  do{   
    
    cout<<"Feld Anzeigen(1)"<<endl;
    cout<<"Feld Besetzten(2)"<<endl;
    cout<<"Spiel Beenden(3)"<<endl;
    chauswahl = getch();
    

    if(chauswahl == '1')
    {
          ZeigeSpielfeld();
    }
    else if(chauswahl == '2')
    {    
          ZeigeSpielfeld();
          Feldauswahl();
          //darfsetzen();

        
    }
    
    else if(chauswahl == '3')
    {
         cout<<"Programm wird Beendet!"<<endl;
         
         return 0;
    }
    else
    {
        cout<<"Falsche Eingabe!"<<endl;
    }
 }while ((chauswahl != 1)||(chauswahl != 2));
 

}

void ZeigeSpielfeld()
{
      system("cls");
     
     cout<<x<<endl;
     cout<<y<<endl;
     cout<<Punkte<<endl;
     cout<<cansetr1<<endl;
      cout<<cansetr2<<endl;

     for (int y=0; y<iHoehe; y++)
         {
             for (int x=0; x<iBreite; x++)
             {         
                                
                     //besetzt von curser
                     if(Spielfeld[x][y].Besetzt == true)
                     {   
                         cout<<"() ";
                     }

                     else if(Spielfeld[x][y].Besetzt == true)
                     {    
                          Farbe(Spielfeld[x][y].spielstein.farbe,0); 
                          cout<<" ";
                          cout<<Spielfeld[x][y].spielstein.form;
                          cout<<" ";
                          Farbe(15,0);
                     }
                    
                     else
                     {
                          cout<<"[] ";
                     }
             }
             
             cout<<endl;
        
         }
}



void Feldauswahl()
{
     
      
      //alle felder = 0 setzen
      for (int yi=0; yi<iHoehe; yi++)
      {
             for (int xi=0; xi<iBreite; xi++)
             {
                 //Spielfeld[xi][yi].Besetzt = false;
             }
      }
     
     do{
     cBewegung = getch();
     }while(cBewegung<0); //behebt Bug bei drücken von Pfeiltasten
     
     if((cBewegung == 72))
     {
          //Nach oben Bewegen
          y = y-1;
          //Curser 
         Spielfeld[x][y].Besetzt = true;
     }
     
     else if((cBewegung == 80))
     {
          //Nach unten Bewegen
          y = y+1;
          //Curser 
         Spielfeld[x][y].Besetzt = true;
     }
     
     else if((cBewegung == 77))
     {
          //Nach Rechts
          x = x+1;
          //Curser 
         Spielfeld[x][y].Besetzt = true;
     }
     
     else if((cBewegung == 75))
     {
          //Nach Links
          x = x-1;
         //Curser 
         Spielfeld[x][y].Besetzt = true;

     }
     
     /*
     //fest Besetztn von stein rot 1
     else if((cBewegung == '1')&&(cansetr1 == true))
     {
        Spielfeld[x][y].steinr1 = true;
        Spielfeld[x][y].steinr1punkterechnung = true;

     }
     
     //Stein rot 2
     else if((cBewegung == '2')&&(cansetr2 == true))
     {
        Spielfeld[x][y].steinr2 = true;
        Spielfeld[x][y].steinr2punkterechnung = true;
     }
     //Stein rot 3
     else if((cBewegung == '3')&&(cansetr3 == true))
     {
        Spielfeld[x][y].steinr3 = true;
        Spielfeld[x][y].steinr3punkterechnung = true;
     }
     //Stein rot 4
     else if((cBewegung == '4')&&(cansetr4 == true))
     {
        Spielfeld[x][y].steinr4 = true;
        Spielfeld[x][y].steinr4punkterechnung = true;
     }
     //Stein rot 5
     else if((cBewegung == '5')&&(cansetr5 == true))
     {
        Spielfeld[x][y].steinr5 = true;
        Spielfeld[x][y].steinr5punkterechnung = true;
     }
     
     
     
     //Blaue steine
     //Stein blau 1
     else if((cBewegung == '6')&&(cansetb1 == true))
     {
        Spielfeld[x][y].steinb1 = true;
        Spielfeld[x][y].steinb1punkterechnung = true;
     }
     //Stein blau 2
     else if((cBewegung == '7')&&(cansetb2 == true))
     {
        Spielfeld[x][y].steinb2 = true;
        Spielfeld[x][y].steinb2punkterechnung = true;
     }
     //Stein blau 3
     else if((cBewegung == '8')&&(cansetb3 == true))
     {
        Spielfeld[x][y].steinb3 = true;
        Spielfeld[x][y].steinb3punkterechnung = true;
     }
     //Stein blau 4
     else if((cBewegung == '9')&&(cansetb4 == true))
     {
        Spielfeld[x][y].steinb4 = true;
        Spielfeld[x][y].steinb4punkterechnung = true;
     }
     //Stein blau 4
     else if((cBewegung == '0')&&(cansetb5 == true))
     {
        Spielfeld[x][y].steinb5 = true;
        Spielfeld[x][y].steinb5punkterechnung = true;
        
     }*/
     else{
           Spielstein spielstein;
           spielstein.form = (char)(cBewegung+63);
           //break;
           }
}


bool checkReihe(int Reihe[][2]){
     for(int i;i<iBreite;i++)
     {
             
             }
     }       

bool darfsetzen(int x, int y, int farbe, int form)
{
     if(Spielfeld[x][y].Besetzt == true)return false;
     if(Spielfeld[x+1][y].Besetzt == false && Spielfeld[x-1][y].Besetzt == false && Spielfeld[x][y+1].Besetzt == false && Spielfeld[x][y-1].Besetzt == false)return false;
     
     
     for(int yi=0;yi<iHoehe;yi++){
     for(int xi=0;xi<iBreite;xi++)
     {
             int Reihe[iBreite][2];
             for(int i=0;i<iBreite;i++){
                     Reihe[i][0]=0;
                     Reihe[i][1]=0;
                     }
             int iReihe=0;
             
             if(Spielfeld[xi][yi].Besetzt==true)
             {
             Reihe[iReihe][0] = Spielfeld[xi][yi].spielstein.farbe;
             Reihe[iReihe][1] = Spielfeld[xi][yi].spielstein.form;
             iReihe++;
             }else{
             if(checkReihe(Reihe)==false)return false;
             for(int i=0;i<iBreite;i++){
                     Reihe[i][0]=0;
                     Reihe[i][1]=0;
                     }
             int iReihe=0;
             }
             }
             }
     return true;

}
