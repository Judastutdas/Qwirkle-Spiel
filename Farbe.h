#ifndef COLOR_H
#define COLOR_H

//Funktion um die Text- und die Hintergrundfarbe zu modifizieren
inline void Farbe(int itext, int ihintergrund)
{
int icolor=itext+16*ihintergrund;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),icolor);
}

#endif
