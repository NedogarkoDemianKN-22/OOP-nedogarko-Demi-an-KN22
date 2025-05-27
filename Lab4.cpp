#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// -------------------- Абстракції телефонів і планшетів --------------------
class Phone {
public:
    virtual void showPrice() const = 0;
    virtual shared_ptr<Phone> clone() const = 0;
    virtual ~Phone() = default;
};

class Nokia : public Phone {
public:
    void showPrice() const override {
        cout << "Ціна  Nokia 3310: $12.99" << endl;
    }
    shared_ptr<Phone> clone() const override {
        return make_shared<Nokia>(*this);
    }
};

class Iphone : public Phone {
public:
    void showPrice() const override {
        cout << "Ціна  Iphone Xr : $299.99" << endl;
    }
    shared_ptr<Phone> clone() const override {
        return make_shared<Iphone>(*this);
    }
};

class Tablet {
public:
    virtual void showPrice() const = 0;
    virtual shared_ptr<Tablet> clone() const = 0;
    virtual ~Tablet() = default;
};

class AppleTablet : public Tablet {
public:
    void showPrice() const override {
        cout << "Ціна Apple iPad : $599.99" << endl;
    }
    shared_ptr<Tablet> clone() const override {
        return make_shared<AppleTablet>(*this);
    }
};

class GoogleTablet : public Tablet {
public:
    void showPrice() const override {
        cout << "Ціна Googletablet : $899.99" << endl;
    }
    shared_ptr<Tablet> clone() const override {
        return make_shared<GoogleTablet>(*this);
    }
};

class SamsungTablet : public Tablet {
public:
    void showPrice() const override {
        cout << "Ціна Samsung Galaxy Tab : $299.99" << endl;
    }
    shared_ptr<Tablet> clone() const override {
        return make_shared<SamsungTablet>(*this);
    }
};

// -------------------- Composite Pattern --------------------

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
        phone->showPrice();
    }
};

class TabletProduct : public ProductComponent {
    shared_ptr<Tablet> tablet;
public:
    TabletProduct(shared_ptr<Tablet> t) : tablet(t) {}
    void show() const override {
        tablet->showPrice();
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
        cout << "--- Категорія: " << name << " ---" << endl;
        for (const auto& child : children) {
            child->show();
        }
    }
};

// -------------------- Facade Pattern --------------------

class ShopFacade {
public:
    void showPhonesAndClones() {
        auto phoneCategory = make_shared<Category>("Смартфони");

        auto iphone = make_shared<Iphone>();
        auto nokia = make_shared<Nokia>();

        phoneCategory->add(make_shared<PhoneProduct>(iphone));
        phoneCategory->add(make_shared<PhoneProduct>(nokia));

        cout << "Оригінали:" << endl;
        phoneCategory->show();

        cout << "Клони:" << endl;
        auto clonedIphone = iphone->clone();
        auto clonedNokia = nokia->clone();
        clonedIphone->showPrice();
        clonedNokia->showPrice();
    }

    void showTablets() {
        auto tabletCategory = make_shared<Category>("Планшети");

        tabletCategory->add(make_shared<TabletProduct>(make_shared<AppleTablet>()));
        tabletCategory->add(make_shared<TabletProduct>(make_shared<GoogleTablet>()));
        tabletCategory->add(make_shared<TabletProduct>(make_shared<SamsungTablet>()));

        tabletCategory->show();
    }
};

// -------------------- Головна функція --------------------

int main() {
    ShopFacade shop;
    int c;

    for (int i = 0; i < 4; i++) {
           
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
}