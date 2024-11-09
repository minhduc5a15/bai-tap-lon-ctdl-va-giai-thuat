#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include "item.hpp"
#include <algorithm>
#include <vector>

class List_item : public Item {
private:
    vector<Item> items;

public:
    List_item() {}

    int get_size() const { return items.size(); }

    void show_list_item() {
        if (items.empty()) {
            cout << "Khong co vat pham nao\n";
            return;
        }
        for (Item x: items) {
            cout << x << "\n";
        }
    }

    bool is_valid_id(const string &_id) {
        for (Item item: items) {
            if (_id == item.get_id()) return false;
        }
        return true;
    }

    void add_item(const int n) {
        Item item;
        for (int i = 0; i < n; ++i) {
            cout << "--- Nhap thong tin vat pham : \n";
            cin >> item;
            if (item.get_name().length() > 0) {
                if (is_valid_id(item.get_id())) items.push_back(item);
                else cout << "Id da ton tai --- Vui long nhap lai\n", --i;
            }
            else cout << "Ten vat pham khong duoc de trong --- Vui long nhap lai\n", --i;
            cout << "\n";
        }
    }

    void delete_item(const int index) {
        for (int i = index + 1; i < items.size(); ++i) {
            swap(items[i - 1], items[i]);
        }
        items.pop_back();
    }

    void update_item(const int index) {
        cout << "Neu khong muon cap nhat nhan enter voi ten, nhap -1 voi so luong va gia tien\n";
        string _name;
        cout << "Nhap ten : ";
        cin.ignore();
        getline(cin, _name);
        if (_name.length() != 0) items[index].set_name(_name);

        int _amount;
        cout << "Nhap so luong : ";
        cin >> _amount;
        if (_amount != -1) items[index].set_amount(_amount);

        double _price;
        cout << "Nhap gia tien : ";
        cin >> _price;
        if (_price != -1) items[index].set_price(_price);
    }

    void sort_item(const bool status) {
        cout << "Sap xep thanh cong\n";
        if (status) {
            sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
                return a < b;
            });
            return;
        }
        sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
            return a > b;
        });
    }

    int find_by_id(const string &id) {
        for (int i = 0; i < items.size(); ++i) {
            if (items[i].get_id() == id) {
                return i;
            }
        }
        return -1;
    }

    bool find_by_price(const double p1, const double p2) {
        bool check = false;
        for (Item item: items) {
            if (const int p = item.get_price(); p >= p1 && p <= p2) {
                check = true;
                cout << item << "\n";
            }
        }
        return check;
    }

    bool find_by_name(const string &_name) {
        bool check = false;
        for (Item item: items) {
            if (item.get_id_name().length() < _name.length()) continue;
            bool find = true;
            const int n = _name.length();
            for (int i = 0; i < n; ++i)
                if (item.get_id_name()[i] != _name[i]) {
                    find = false;
                    break;
                }

            if (find) check = true, cout << item << "\n";
        }
        return check;
    }
};

#endif
