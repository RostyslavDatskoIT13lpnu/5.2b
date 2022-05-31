#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

struct Student
{
    char lname[100];
    int kurs;
    Spec spec;
    int physics;
    int math;
    union {
        int progr;
        int numb;
        int ped;
    };
};


void print(string name);    //вивід
void create(string name);   //ввід
void print2(string name);   //вивід тих, в кого фізика 5 або 4
bool check(Student a);      //перевірка на відмінника
double amount();            //відсоток відмінників

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    bool e;

    cout << "Load(0)  Create(1)"; cin >> e;

    if (e) {
        create("File.txt");
    }

    print("File.txt");
    print2("File.txt");
    cout << "Percent: " << amount();
}

void print(string name) {
    ifstream f(name, ios::binary);
    Student s;
    int i = 0;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;

    f.read((char*)&s, sizeof(s));
    while (!f.eof()) {
        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s.lname;
        cout << "| " << setw(5) << right << s.kurs;
        cout << "| " << setw(23) << left << strSpec[s.spec]; ;//strSpec[s[i].spec]
        cout << "| " << setw(7) << s.physics;
        cout << "| " << setw(11) << right << s.math;

        if (s.spec == 0) {
            cout << "| " << setw(14) << right << s.progr
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s.spec == 1) {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << s.numb
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << s.ped << "| ";
        }
        cout << endl;
        f.read((char*)&s, sizeof(s));
        i++;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;



}

void create(string name) {
    ofstream f(name, ios::binary | ios::trunc | ios::out);
    int Wn;
    Student s;
    int sp;

    cout << "n: "; cin >> Wn;

    for (int i = 0; i < Wn; i++) {
        cout << "Student " << i + 1 << endl;

        cout << "Name: "; cin >> s.lname;

        cout << "Curs: "; cin >> s.kurs;

        cout << "Spec: "; cin >> sp; s.spec = (Spec)sp;

        cout << "Fis: "; cin >> s.physics;

        cout << "Math: "; cin >> s.math;

        if (sp == 0) {
            cout << "Prog: "; cin >> s.progr;
        }
        else if (sp == 1) {
            cout << "Numer: "; cin >> s.numb;
        }
        else {
            cout << "Pedag: "; cin >> s.numb;
        }
        f.write((char*)&s, sizeof(s));
    }
}

void print2(string name) {

    ifstream f(name, ios::binary);
    Student s;
    int i = 0;

    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    f.read((char*)&s, sizeof(s));
    while (!f.eof()) {

        i++;
        if (s.physics > 3) {
            cout << "| " << setw(2) << right << i << "";

            cout << "| " << setw(14) << left << s.lname;

            cout << "| " << setw(5) << right << s.kurs;

            cout << "| " << setw(23) << left << strSpec[s.spec]; ;

            cout << "| " << setw(7) << s.physics;

            cout << "| " << setw(11) << right << s.math;

            if (s.spec == 0) {
                cout << "| " << setw(14) << right << s.progr
                    << "| " << setw(16) << right << " "
                    << "| " << setw(11) << right << " " << "| ";
            }
            else if (s.spec == 1) {
                cout << "| " << setw(14) << right << " "
                    << "| " << setw(16) << right << s.numb
                    << "| " << setw(11) << right << " " << "| ";
            }
            else {
                cout << "| " << setw(14) << right << " "
                    << "| " << setw(16) << right << " "
                    << "| " << setw(11) << right << s.ped << "| ";
            }
            cout << endl;
        }
        f.read((char*)&s, sizeof(s));

    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;



}

bool check(Student a) {
    if (a.math > 3 && a.physics > 3 && (a.numb > 3 || a.progr > 3 || a.ped > 3)) {
        return true;
    }
    else {
        return false;
    }


}

double amount() {
    ifstream f("File.txt", ios::binary);
    Student s;
    int k = 0;
    double w = 0;
    f.read((char*)&s, sizeof(s));
    while (!f.eof()) {
        if (check(s)) {
            k++;
        }
        w++;
        f.read((char*)&s, sizeof(s));
    }
    return (double)k / w;
}
