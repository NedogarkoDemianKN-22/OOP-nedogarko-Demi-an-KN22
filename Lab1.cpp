#include <iostream>
#include <vector>
#include <memory>
using namespace std;


////////////////////////////////
// Абстрактний клас Transport і чисто віртуальний метод ruh()
class Transport {
public:
    virtual void ruh() const = 0;

    void info() const {
        cout << "Це транспорт" << endl;
    }

    virtual ~Transport() = default;
};




/////////////////////////////////
///Успадкування	Car і Rover наслідують Transport
//Інкапсуляція	Приватні поля brand, year у класах Car і Rover
class Car : public Transport {
    string brand;
    int year;
public:
    Car(const string& b, int y) : brand(b), year(y) {}

    void ruh() const override {
        cout << brand << "Щоб поіхати треба мати права" << endl;
    }
};



/////////////////////////////////

///клас Rover наслідує абстрактний клас транспорт
class Rover : public Transport {
    string brand;
    int year;
public:
    Rover(const string& b, int y) : brand(b), year(y) {}

    void ruh() const override {
        cout << brand << "Щоб поїхати треба крутити педалі" << endl;
    }
};



//////////////////////////////////////

int main() {
    vector<shared_ptr<Transport>> transport = {
        make_shared<Car>(" Машина :  Таврія  ", 1999),
        make_shared<Rover>("Ровер :  Україна  ", 1990)
    };

    for (const auto& v : transport) {
        v->info();
        v->ruh();
        //Поліморфізм Віртуальний виклик v->ruh() через вказівник на базовий клас
        cout << "-----" << endl;
    }

   
}