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
            cout << "Không có vật phẩm nào\n";
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
            cout << "--- Nhập thông tin vật phẩm : \n";
            cin >> item;
            if (item.get_name().length() > 0) {
                if (is_valid_id(item.get_id())) items.push_back(item);
                else cout << "Id đã tồn tại, vui lòng nhập một ID khác!\n", --i;
            }
            else cout << "Tên vật phẩm không được để trống, vui lòng nhập lại!\n", --i;
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
        cout << "Nếu không muốn cập nhật, nhấn enter với tên, nhập -1 với số lượng và giá tiền\n";
        string _name;
        cout << "Nhập tên : ";
        cin.ignore();
        getline(cin, _name);
        if (_name.length() != 0) items[index].set_name(_name);

        int _amount;
        cout << "Nhập số lượng : ";
        cin >> _amount;
        if (_amount != -1) items[index].set_amount(_amount);

        double _price;
        cout << "Nhập giá tiền : ";
        cin >> _price;
        if (_price != -1) items[index].set_price(_price);
    }

    void sort_item(const bool status) {
        cout << "Sắp xếp thành công\n";
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

    int find_by_id(const string &id) const {
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
