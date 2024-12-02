#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

inline string format(const string &s) {
    string res = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') continue;
        if (s[i] >= 'A' && s[i] <= 'Z') res += (s[i] + 32);
        else res += s[i];
    }
    return res;
}

class Item {
private:
    string id;
    string name, idName;
    int amount;
    double price;

public:
    friend istream &operator>>(istream &in, Item &item) {
        cout << "Nhập ID vật phẩm : ";
        in >> item.id;

        in.ignore();
        cout << "Nhập tên vật phẩm : ";
        getline(in, item.name);
        item.idName = format(item.name);

        cout << "Nhập số lượng vật phẩm : ";
        in >> item.amount;

        cout << "Nhập giá tiền vật phẩm : ";
        in >> item.price;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Item &item) {
        cout << "ID vật phẩm : ";
        out << item.id << "\n";
        cout << "Tên vật phẩm : ";
        out << item.name << "\n";
        cout << "Số lượng : ";
        out << item.amount << "\n";
        cout << "Giá tiền : ";
        out << item.price << "\n";
        return out;
    }

    bool operator==(const Item &other) const { return this->price == other.price; }
    bool operator>(const Item &other) const { return this->price > other.price; }
    bool operator<(const Item &other) const { return this->price < other.price; }

    void set_name(const string &s) { name = s; }
    void set_amount(const int a) { amount = a; }
    void set_price(const double p) { price = p; }

    string get_id() const { return id; }
    string get_id_name() const { return idName; }
    string get_name() const { return name; }
    int get_amount() const { return amount; }
    double get_price() const { return price; }
};

#endif
