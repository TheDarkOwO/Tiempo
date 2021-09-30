#include "Fecha.h"

const int Fecha::dias[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Fecha::Fecha(int m, int d, int a)
{
    estableceFecha(m, d, a);
}

void Fecha::estableceFecha(int mm, int dd, int aa)
{
    mes = (mm >= 1 && mm <= 12) ? mm : 1;
    anio = (aa >= 1000 && aa <= 5000) ? aa : 1000;

    if (mes == 2 && anioBisiesto(anio))
        dia = (dd >= 1 && dd <= 29) ? dd : 1;
    else
        dia = (dd >= 1 && dd <= dias[mes]) ? dd : 1;
}

Fecha& Fecha::operator++()
{
    ayudaIncremento();
    return *this;
}

Fecha Fecha::operator++(int)
{
    Fecha temp = *this;
    ayudaIncremento();
    return temp;
}

const Fecha& Fecha::operator+=(int diasAdicionales)
{
    for (int i = 0; i < diasAdicionales; i++)
        ayudaIncremento();

    return *this;
}

bool Fecha::anioBisiesto(int verificaAnio) const
{
    if (verificaAnio % 400 == (verificaAnio % 100 != 0 && verificaAnio % 4 == 0))
        return true;
    else
        return false;
}

bool Fecha::finDeMes(int verificaDia) const
{
    if (mes == 2 && anioBisiesto(anio))
        return verificaDia == 29;
    else
        return verificaDia == dias[mes];
}

void Fecha::ayudaIncremento()
{
    if (!finDeMes(dia))
        ++dia;
    else
        if (mes < 12) {
            ++mes;
            dia = 1;
        }
        else {
            ++anio;
            mes = 1;
            dia = 1;
        }

}

ostream& operator<<(ostream& salida, const Fecha& d)
{
    string nombreMes[13] = { "","Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic" };

    salida << nombreMes[d.mes] << " " << d.dia << ", " << d.anio;

    return salida;
}

Fecha Fecha::operator+(Fecha Other)
{
    Fecha Total;
    Total = Other;
    Total.anio = Total.anio + anio;
    Total.mes = Total.mes + mes;
    if (Total.mes > 12)
    {
        ++Total.anio;
        Total.mes = Total.mes - 12;
    }
    for (int i = 0; i < dia; i++)
    {
        if (!finDeMes(Total.dia))
        {
            ++Total.dia;
        }
        else
        {
            if (Total.mes < 12)
            {
                ++Total.mes;
                Total.dia = 1;
            }
            else
            {
                ++Total.anio;
                Total.mes = 1;
                Total.dia = 1;
            }
        }
    }
    return Total;
}

Fecha Fecha::operator-(Fecha Aux)
{
    Fecha Total(1,1,1000);
    if (anio > Aux.anio)
    {
        Total.anio = anio - Aux.anio;
        Total.mes = mes - Aux.mes;
        Total.dia = dia;
        if (Total.mes < 1)
        {
            --Total.anio;
            Total.mes = 12 - Total.mes;
        }
        for (int i = 0; i < Aux.dia; i++)
        {
            if (!(Total.dia < 2))
            {
                --Total.dia;
            }
            else
            {
                if (Total.mes == 2 && anioBisiesto(anio))
                {

                    --Total.mes;
                    Total.dia = 29;
                }
                else
                {
                    if (!(Total.mes < 2))
                    {
                        --Total.mes;
                        Total.dia = dias[Total.mes];
                    }
                    else
                    {
                        Total.mes = 12;
                        Total.dia = 31;
                    }
                }
            }
        }
        return Total;
    }
    else
    {
        cout << "The operation cannot be done the year that you want to substrat is lower th\n";
        cout << "The year that you want to substrat is lower than the substractor\n";
        cout << "Returning to menu....\n";
        cout << "Input something to continue.\n";
        cin.ignore();
        cin.get();
        system("clear");
        return Total;
    }
}
