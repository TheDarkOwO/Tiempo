#include "Fecha.h"
Fecha SetValuesDate();
void Menu(), PrintDates(Fecha, Fecha);
using namespace std;

/* cin.ignore();
cin.get();
system("cls");
*/

int main()
{
    Fecha Date1, Date2;
    char Option = '0'; bool Check = false;
    while (Option != '4')
    {
        Menu();
        cin >> Option;
        system("cls");
        switch (Option)
        {
            case '1':
            {
                Date1 = SetValuesDate();
                cout << "\nFirst Date complete, proceeding with the second date, input something to continue.\n";
                cin.ignore();
                cin.get();
                system("cls");
                Date2 = SetValuesDate();
                system("cls");
                Check = true;
                break;
            }
            case '2':
            {
                if (Check)
                {
                    PrintDates(Date1, Date2); cout << "\n\n";
                    cout << "\nInput something to continue.\n";
                    cin.ignore();
                    cin.get();
                    system("cls ");
                }
                else
                {
                    cout << "You need to fill the dates before doing this"; cout << "\n\n";
                    cout << "\nInput something to continue.\n";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                break;
            }
            case '3':
            {
                if (Check)
                {
                    
                }
                else
                {
                    cout << "You need to fill the dates before doing this"; cout << "\n\n";
                    cout << "\nInput something to continue.\n";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                break;
            }
            default:
            {
                cout << "Invalid option\n";
                cout << "Returning to menu....\n";
                cout << "Input something to continue.\n";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
        }
    }
    return 0;
}


void Menu()
{
    cout << "   ||||Calendar menu||||   \n";
    cout << "\n1. Create or change two dates.";
    cout << "\n2. Print dates.";
    cout << "\n3. Addition between dates.";
    cout << "\n4. Substraction between.";
    cout << "\n5. End program.\n";
    cout << "\nWhat do you want to do? ";
};


Fecha SetValuesDate()
{
    int D, M, Y;
    cout << "   |||Creation menu|||   \n";
    cout << "\nWrite certain date you want to create \n";
    cout << "Write the day  " << ": ";
    cin >> D;
    cout << "Write the month  " << ": ";
    cin >> M;
    cout << "Write the year  " << ": ";
    cin >> Y;
    Fecha AuxDate(M, D, Y);
    return AuxDate;
}

void PrintDates(Fecha Date1Aux, Fecha Date2Aux) 
{
    cout << "   |||Print menu|||   \n\n";
    cout << "First date: " << Date1Aux;
    cout << "\n";
    cout << "Second date: " << Date2Aux;
}