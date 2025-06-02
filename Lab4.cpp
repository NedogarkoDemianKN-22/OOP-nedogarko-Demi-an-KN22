#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Абстракції телефонів і планшетів
class Phone {
public:
    virtual void showPrice() const = 0;
    virtual void showInfo() const = 0;
    virtual shared_ptr<Phone> clone() const = 0;
    virtual ~Phone() = default;
};

class Nokia : public Phone {
private:
    string brand;
    string model;
    string description;

public:
    Nokia() : brand("Nokia"), model("3310"), description("Легендарна живуча модель як вражає і  сьогодні своєю довговічнісьтю.") {}

    void showPrice() const override {
        cout << "Ціна Nokia 3310: $12.99" << endl;
    }

    void showInfo() const override {
        cout << "Бренд: " << brand << "\n Модель: " << model << "\n Опис: " << description << endl;
        showPrice();
    }

    shared_ptr<Phone> clone() const override {
        return make_shared<Nokia>(*this);
    }
};

class Iphone : public Phone {
private:
    string brand;
    string model;
    string description;

public:
    Iphone() : brand("Apple"), model("iPhone XR"), description("Смартфон із якісною камерою, пердовим дизайном та iOS.") {}

    void showPrice() const override {
        cout << "Ціна iPhone XR: $299.99" << endl;
    }

    void showInfo() const override {
        cout << "Бренд: " << brand << "\n Модель: " << model << "\n Опис: " << description << endl;
        showPrice();
    }

    shared_ptr<Phone> clone() const override {
        return make_shared<Iphone>(*this);
    }
};

class Tablet {
public:
    virtual void showPrice() const = 0;
    virtual void showInfo() const = 0;
    virtual shared_ptr<Tablet> clone() const = 0;
    virtual ~Tablet() = default;
};

class AppleTablet : public Tablet {
private:
    string brand;
    string model;
    string description;

public:
    AppleTablet() : brand("Apple"), model("iPad"), description("Планшет для роботи, навчання та розваг.") {}

    void showPrice() const override {
        cout << "Ціна Apple iPad: $599.99" << endl;
    }

    void showInfo() const override {
        cout << "Бренд: " << brand << "\n Модель: " << model << "\n Опис: " << description << endl;
        showPrice();
    }

    shared_ptr<Tablet> clone() const override {
        return make_shared<AppleTablet>(*this);
    }
};

class GoogleTablet : public Tablet {
private:
    string brand;
    string model;
    string description;

public:
    GoogleTablet() : brand("Google"), model("Pixel 5s"), description("Планшет на Chrome OS , ну не знаю шо ше написати , бажаю удачі власнику.") {}

    void showPrice() const override {
        cout << "Ціна Google Pixel 5s: $899.99" << endl;
    }

    void showInfo() const override {
        cout << "Бренд: " << brand << "\nМодель: " << model << "\nОпис: " << description << endl;
        showPrice();
    }

    shared_ptr<Tablet> clone() const override {
        return make_shared<GoogleTablet>(*this);
    }
};

class SamsungTablet : public Tablet {
private:
    string brand;
    string model;
    string description;

public:
    SamsungTablet() : brand("Samsung"), model("Galaxy Tab"), description("Планшет на Android з великим дисплеєм , якщо ваам байдуже на свою дитину \n то рекомендую купити для дитини , великий екран на довго затяне вашу дитину \n як то кажуть чим би дитина не бавилась аби не плакала.") {}

    void showPrice() const override {
        cout << "Ціна Samsung Galaxy Tab: $299.99" << endl;
    }

    void showInfo() const override {
        cout << "Бренд: " << brand << "\nМодель: " << model << "\nОпис: " << description << endl;
        showPrice();
    }

    shared_ptr<Tablet> clone() const override {
        return make_shared<SamsungTablet>(*this);
    }
};






// Composite Pattern
class ProductComponent {
public:
    virtual void show() const = 0;
    virtual ~ProductComponent() = default;
};

class PhoneProduct : public ProductComponent {
    shared_ptr<Phone> phone;
public:
    PhoneProduct(shared_ptr<Phone> p) : phone(p) {}
    void show() const override {
        phone->showInfo();
    }
};

class TabletProduct : public ProductComponent {
    shared_ptr<Tablet> tablet;
public:
    TabletProduct(shared_ptr<Tablet> t) : tablet(t) {}
    void show() const override {
        tablet->showInfo();
    }
};

class Category : public ProductComponent {
    string name;
    vector<shared_ptr<ProductComponent>> children;
public:
    Category(const string& n) : name(n) {}

    void add(const shared_ptr<ProductComponent>& child) {
        children.push_back(child);
    }

    void show() const override {
        cout << "\n--- Категорія: " << name << " ---" << endl;
        for (const auto& child : children) {
            child->show();
            cout << endl;
        }
    }
};



// Facade Pattern
class ShopFacade {
public:
    void showPhonesAndClones() {
        auto phoneCategory = make_shared<Category>("Смартфони");

        auto iphone = make_shared<Iphone>();
        auto nokia = make_shared<Nokia>();

        phoneCategory->add(make_shared<PhoneProduct>(iphone));
        phoneCategory->add(make_shared<PhoneProduct>(nokia));

        cout << "\n Оригінали:" << endl;
        phoneCategory->show();

        cout << "\n Клон iPhone XR:" << endl;
        auto clonedIphone = iphone->clone();
        clonedIphone->showInfo();

          cout << "\n Клон Nokia 3310:" << endl;
        auto clonedNokia = nokia->clone();
        clonedNokia->showInfo();


    }

    void showTablets() {
        auto tabletCategory = make_shared<Category>("Планшети");

        tabletCategory->add(make_shared<TabletProduct>(make_shared<AppleTablet>()));
        tabletCategory->add(make_shared<TabletProduct>(make_shared<GoogleTablet>()));
        tabletCategory->add(make_shared<TabletProduct>(make_shared<SamsungTablet>()));

        tabletCategory->show();
    }
};

// головне меню програми
int main() {
    ShopFacade shop;
    int c;

    for (int i = 0; i < 4; i++) {
        cout << "\n  Привіт! вас  вітає магазин смартфонів та планшетів" << endl;
        cout << "Меню:\n" << endl;
        cout << "1 - Подивитися ціни на смартфони" << endl;
        cout << "2 - Подивитися ціни на планшети" << endl;
        cout << "\n Ваш вибір: ";
        cin >> c;

        switch (c) {
        case 1:
            shop.showPhonesAndClones();
            break;
        case 2:
            shop.showTablets();
            break;
        default:
            cout << "Невірне значення.\n";
        }
    }

    return 0;
}

