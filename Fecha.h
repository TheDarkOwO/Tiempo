#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;

class Fecha {

    friend ostream& operator<<(ostream&, const Fecha&);

public:
    Fecha(int m = 1, int d = 1, int y = 1900);
    void estableceFecha(int, int, int);

    Fecha& operator++(); //preincremento
    Fecha operator++(int); //postincremento
    Fecha operator+(Fecha Aux);
    Fecha operator-(Fecha Aux);
    const Fecha& operator+=(int); //suma dÌas

    bool anioBisiesto(int) const;
    bool finDeMes(int) const;

private:
    int mes;
    int dia;
    int anio;

    static const int dias[];
    void ayudaIncremento();
};

#endif // FECHA_H
