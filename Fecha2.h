#pragma on/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fecha.h
 * Author: babel
 *
 * Created on 1 de septiembre de 2017, 02:09 PM
 */

#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;

float dias[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class fecha
{
    friend ostream& operator<<(ostream&, const fecha&);
    friend istream& operator>>(istream&, fecha&);

public:
    fecha();
    int bisiesto();
    void edad(fecha&) const;
    /*int anios(fecha &) const;
    int meses(fecha &) const;
    int dias(fecha &) const;*/

private:
    float dia, mes, anio;
};

fecha::fecha() {
    dia = 1;
    mes = 1;
    anio = 1000;
}

istream& operator>>(istream& entrada, fecha& a)
{
    do {
        cout << "\nDigite anio (minimo 1000): ";
        entrada >> a.anio;
    } while (a.anio < 1000);

    do {
        cout << "\nDigite numero del mes (1 - 12): ";
        entrada >> a.mes;
    } while (a.mes < 1 || a.mes > 12);

    if (a.mes == 2 && a.bisiesto())
        do {
            cout << "\nDigite dia (1 - 29): ";
            entrada >> a.dia;
        } while (a.dia < 1 || a.dia > 29);
    else
        do {
            cout << "\nDigite dia (1 - " << dias[(int)a.mes] << "): ";
            entrada >> a.dia;
        } while (a.dia < 1 || a.dia > dias[(int)a.mes]);

        return entrada;
}

int fecha::bisiesto()
{
    if ((int)anio % 4 == 0 && ((int)anio % 100 != 0 || (int)anio % 400 == 0))
        return 1;
    return 0;
}

void fecha::edad(fecha& n) const
{
    float ahoyd, aNacd, mhoyd, mNacd, dhoy, dNac;
    float edadDias, edadAnios, Resulta1, edadMes;
    int Eanios, Emeses = 0, Edias = 0, ParaRestar1, ParaRestar2;

    ahoyd = anio * 365.242189;
    aNacd = n.anio * 365.242189;
    mhoyd = mes * 30.416667;
    mNacd = n.mes * 30.416667;
    dhoy = ahoyd + mhoyd + mes;
    dNac = aNacd + mNacd + n.mes;

    edadDias = dhoy - dNac;
    edadAnios = edadDias / 365.242189;
    Eanios = (int)edadAnios;
    ParaRestar1 = Eanios * 365.242189;

    if (ParaRestar1 != (int)edadDias)
    {
        Resulta1 = edadDias - (float)ParaRestar1;
        edadMes = Resulta1 / 30.416667;
        Emeses = (int)edadMes;
        ParaRestar2 = Emeses * 30.416667;

        if (ParaRestar2 != (int)Resulta1)
            Edias = (int)Resulta1 - ParaRestar2;

    }

    cout << "\n\n\tEdad en dias -> " << edadDias;
    cout << "\n\n\tSu edad -> " << Eanios << " anios ";
    cout << Emeses << " meses ";
    cout << Edias << " dias ";
    cout << "\n\n";
}

/*int fecha::anios(fecha &n) const
{

}

int fecha::meses(fecha &n) const
{


}

int fecha::dias(fecha &n) const
{


}*/



#endif /* FECHA_H */

ce
