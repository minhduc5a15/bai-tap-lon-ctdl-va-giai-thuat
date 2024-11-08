#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

inline string DelBlank_and_ToLowercase(const string &s) {
    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') continue;
        if (s[i] >= 'A' && s[i] <= 'Z') ans += (s[i] + 32);
        else ans += s[i];
    }
    return ans;
}

class Item {
private:
    string id;
    string name, idName;
    int amount;
    double price;

public:
    friend istream &operator>>(istream &in, Item &item) {
        cout << "Nhap id vat pham : ";
        in >> item.id;

        in.ignore();
        cout << "Nhap ten vat pham : ";
        getline(in, item.name);
        item.idName = DelBlank_and_ToLowercase(item.name);

        cout << "Nhap so luong : ";
        in >> item.amount;

        cout << "Nhap gia tien : ";
        in >> item.price;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Item &item) {
        cout << "Id vat pham : ";
        out << item.id << "\n";
        cout << "Ten vat pham : ";
        out << item.name << "\n";
        cout << "So luong : ";
        out << item.amount << "\n";
        cout << "Gia tien : ";
        out << item.price << "\n";
        return out;
    }

    bool operator==(const Item &other) const { return this->price == other.price; }
    bool operator>(const Item &other) const { return this->price > other.price; }
    bool operator<(const Item &other) const { return this->price < other.price; }

    void set_name(const string &s) { name = s; }
    void set_amount(const int a) { amount = a; }
    void set_price(const double p) { price = p; }

    string get_id() { return id; }
    string get_id_name() { return idName; }
    string get_name() { return name; }
    int get_amount() const { return amount; }
    double get_price() const { return price; }
};

#endif
