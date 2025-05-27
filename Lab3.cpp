#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;



// Абстрактний клас для телефонів
class Phone {
public:
    virtual void showPrice() const = 0;
    virtual shared_ptr<Phone> clone() const = 0; // <--- додано
    virtual ~Phone() = default;
};

// Клас Nokia 
class Nokia : public Phone {
public:
    void showPrice() const override {
        cout << "Ціна  Nokia 3310: $12.99" << endl;
    }

    shared_ptr<Phone> clone() const override {
        return make_shared<Nokia>(*this);
    }
};

// Клас Iphone 
class Iphone : public Phone {
public:
    void showPrice() const override {
        cout << "Ціна  Iphone Xr : $299.99" << endl;
    }

    shared_ptr<Phone> clone() const override {
        return make_shared<Iphone>(*this);
    }
};


// Клас, який виводить ціни 
class PriceDisplay {
public:
    void displayAllPrices(const vector<shared_ptr<Phone>>& phones) {
        for (const auto& phone : phones) {
            phone->showPrice();
        }
    }
};













// Абстрактний клас для планшетів
class Tablet 
{
public:
    virtual void showPrice() const = 0; 
    virtual shared_ptr<Tablet> clone() const = 0; // <--- додано
    virtual ~Tablet() = default;
};

// Планшет Apple 
class AppleTablet : public Tablet
{
public:
    void showPrice() const override {
        cout << "Ціна Apple iPad : $599.99" << endl;
    }

     shared_ptr<Tablet> clone() const override {
        return make_shared<AppleTablet>(*this);
    }
};

class GoogleTablet : public Tablet
{
public:
    void showPrice() const override {
        cout << "Ціна Googletablet : $899.99" << endl;
    }

    shared_ptr<Tablet> clone() const override {
        return make_shared<GoogleTablet>(*this);
    }
};

// Планшет Samsung 
class SamsungTablet : public Tablet
{
public:
    void showPrice() const override {
        cout << "Ціна Samsung Galaxy Tab : $299.99" << endl;
    }

    shared_ptr<Tablet> clone() const override {
        return make_shared<SamsungTablet>(*this);
    }
};

// Клас, який виводить ціни на планшети 
class TabletPriceDisplayer 
{
public:
    void displayPrices(const vector<shared_ptr<Tablet>>& tablets) {
        for (const auto& tablet : tablets) {
            tablet->showPrice();
        }
    }
};

// головне меню програми

int main()
 {
    int c;
    for(int i = 0 ; i < 4; i++)
    {
       
    cout << "" << endl;
    cout << "" << endl;
    cout << "Привіт тебе вітає магазин смартфонів та планшетів" << endl;
    cout << "" << endl;
    cout << "Меню:" << endl;
    cout << "" << endl;
    cout << "Щоб глянути ціна на смартфони введіть 1" << endl;
    cout << "Щоб глянути ціна на планшети введіть 2" << endl;
    cout << "" << endl;
    cout << "Введіть число" << endl;
    cin >> c ;



     
     switch (c)
     {
     case 1 :
         {
            vector<shared_ptr<Phone>> phones;
            phones.push_back(make_shared<Nokia>());
            phones.push_back(make_shared<Iphone>());

            PriceDisplay display;
            display.displayAllPrices(phones);
            
            cout << "  " << endl;



            cout << "Клонування " << endl;
                    auto originalPhone = make_shared<Iphone>();
                    auto clonedPhone = originalPhone->clone();
                    clonedPhone->showPrice();
                    
            cout << "Клонування " << endl;
                    auto originalNokia = make_shared<Nokia>();
                    auto clonedNokia = originalNokia->clone();
                    clonedNokia->showPrice();
         }
         break;
     case 2 :
         {
            vector<shared_ptr<Tablet>> tablets;
            tablets.push_back(make_shared<AppleTablet>());
            tablets.push_back(make_shared<SamsungTablet>());
             tablets.push_back(make_shared<GoogleTablet>());


            TabletPriceDisplayer displayer;
            displayer.displayPrices(tablets);
         }
         break;
     }
    
  

   
   }





 }

