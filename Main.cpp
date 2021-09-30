#include "Fecha.h"
Fecha SetValuesDate();
void Menu(), PrintDates(Fecha, Fecha), PrintAdd(Fecha, Fecha, Fecha), PrintSub(Fecha Result, Fecha DateA, Fecha DateB), MenuSub();
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
        system("clear");
        switch (Option)
        {
            case '1':
            {
                Date1 = SetValuesDate();
                cout << "\nFirst Date complete, proceeding with the second date, input something to continue.\n";
                cin.ignore();
                cin.get();
                system("clear");
                Date2 = SetValuesDate();
                system("clear");
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
                    system("clear");
                }
                else
                {
                    cout << "You need to fill the dates before doing this"; cout << "\n\n";
                    cout << "\nInput something to continue.\n";
                    cin.ignore();
                    cin.get();
                    system("clear");
                }
                break;
            }
            case '3':
            {
                if (Check)
                {
                    Fecha Date3 = Date1 + Date2;
                    PrintAdd(Date3,Date1,Date2);
                }
                else
                {
                    cout << "You need to fill the dates before doing this"; cout << "\n\n";
                    cout << "\nInput something to continue.\n";
                    cin.ignore();
                    cin.get();
                    system("clear");
                }
                break;
            }
            case '4':
            {
                if (Check)
                {
                    char SubOp = '0';
                    while (SubOp != '3')
                    {
                        MenuSub();
                        cin >> SubOp;
                        system("clear");
                        switch (SubOp)
                        {
                        case '1':
                        {
                            Fecha Date4 = Date1 - Date2;
                            PrintAdd(Date4, Date1, Date2);
                            cin.ignore();
                            cin.get();
                            system("clear");
                            break;
                        }
                        case '2':
                        {
                            Fecha Date4 = Date2 - Date1;
                            PrintAdd(Date4, Date1, Date2);
                            cin.ignore();
                            cin.get();
                            system("clear");
                            break;
                        }
                        default:
                        {
                            cout << "Invalid option\n";
                            cout << "Returning to menu....\n";
                            cout << "Input something to continue.\n";
                            cin.ignore();
                            cin.get();
                            system("clear");
                            break;
                        }
                        }
                    }
                }
                else
                {
                    cout << "You need to fill the dates before doing this"; cout << "\n\n";
                    cout << "\nInput something to continue.\n";
                    cin.ignore();
                    cin.get();
                    system("clear");
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
                system("clear");
                break;
            }
        }
    }
    return 0;
}


void Menu()
{
    cout << "     ||||Calendar menu||||   \n";
    cout << "\n1. Create or change two dates.";
    cout << "\n2. Print dates.";
    cout << "\n3. Addition between dates.";
    cout << "\n4. Substraction between.";
    cout << "\n5. End program.\n";
    cout << "\nWhat do you want to do? ";
}


Fecha SetValuesDate()
{
    int D, M, Y;
    cout << "         |||Creation menu|||   \n";
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
    cout << "     |||Print menu|||   \n\n";
    cout << "First date: " << Date1Aux;
    cout << "\n";
    cout << "Second date: " << Date2Aux;
}

void PrintAdd(Fecha Result, Fecha DateA, Fecha DateB)
{
    cout << "     |||Adition results menu|||   \n\n";
    cout << "The adition between [" << DateA << "] and [" << DateB << "] Gives: ["<< Result <<"]";
    cout << "\n\nInput something to continue.\n";
    cin.ignore();
    cin.get();
    system("clear");
}

void MenuSub()
{
    cout << "     ||||Substraction menu||||   \n";
    cout << "\n1. Date 1 - Date 2.";
    cout << "\n2. Date 2 - Date 1.";
    cout << "\n5. Go back.\n";
    cout << "\nWhat do you want to do? ";
}
void PrintSub(Fecha Result, Fecha DateA, Fecha DateB)
{
    cout << "     |||Substraction results menu|||   \n\n";
    cout << "The substraction between [" << DateA << "] and [" << DateB << "] Gives: [" << Result << "]";
    cout << "\n\nInput something to continue.\n";
    cin.ignore();
    cin.get();
    system("clear");
}
