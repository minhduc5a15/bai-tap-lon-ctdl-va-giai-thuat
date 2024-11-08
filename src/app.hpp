#ifndef APP_H
#define APP_H

#include "list_item.hpp"

class App : public List_item {
public:
    static void showMenu() {
        cout << "-------------------------------GroceryApp-------------------------------\n";
        cout << "------------------------------------------------------------------------\n";
        cout << "=====     Menu:                                                    =====\n"
                "=====       1. Them vat pham                                       =====\n"
                "=====       2. Hien thi danh sach                                  =====\n"
                "=====       3. Sap xep theo gia tien                               =====\n"
                "=====       4. Xoa vat pham theo Id                                =====\n"
                "=====       5. Cap nhat thong tin vat pham theo Id                 =====\n"
                "=====       6. Tim vat pham theo khoang gia                        =====\n"
                "=====       7. Tim vat pham theo ten                               =====\n"
                "=====       8. Hien thi Menu                                       =====\n"
                "=====       0. Thoat                                               =====\n";
        cout << "------------------------------------------------------------------------\n";
        cout << "------------------------------------------------------------------------\n";
    }

    void Add() {
        cout << "          -------------------THEM VAT PHAM--------------------          \n";
        cout << "Nhap so vat pham muon them : ";
        int n;
        cin >> n;
        add_item(n);
        cout << "\nDa them " << n << " vat pham\n";
    }

    void Show() {
        cout << "          ---------------HIEN THI DANH SACH-------------------          \n";
        show_list_item();
    }

    int Sort() {
        cout << "          -------------SAP XEP THEO GIA TIEN------------------          \n";
        if (get_size() == 0) {
            cout << "Danh sach dang trong\n";
            return 0;
        }

        int value = 2;
        while (value < 0 || value > 1) {
            cout << "Sap xep theo gia tang(1) hoac giam (0) : ";
            cin >> value;
        }
        if (value == 1) sort_item(true);
        else sort_item(false);
        value = 2;
        while (value < 0 || value > 1) {
            cout << "Ban co muon hien danh sach khong (1. Co), (0. Khong) : ";
            cin >> value;
        }
        return value;
    }

    void Delete() {
        cout << "          --------------------XOA VAT PHAM--------------------          \n";
        cout << "Nhap id vat pham : ";
        string id;
        cin >> id;
        if (const int index = find_by_id(id); index == -1) cout << "Khong co vat pham nay\n";
        else {
            delete_item(index);
            cout << "Xoa thanh cong\n";
        }
    }

    void Update() {
        cout << "          -----------------CAP NHAT THONG TIN-----------------          \n";
        cout << "Nhap id vat pham : ";
        string id;
        cin >> id;
        if (const int index = find_by_id(id); index == -1) cout << "Khong co vat pham nay\n";
        else {
            update_item(index);
            cout << "Cap nhat thanh cong\n";
        }
    }

    void FindPrice() {
        cout << "          -------------TIM VAT PHAM THEO GIA TIEN-------------          \n";
        cout << "Nhap khoang gia [Min Max]: ";
        double Min, Max;
        cin >> Min >> Max;
        cout << "Cac vat pham co gia tien trong khoang [" << Min << ", " << Max << "] : \n";
        if (const bool check = find_by_price(Min, Max); !check) cout << "Khong co vat pham nao\n";
    }

    void FindItemName() {
        cout << "          ---------------TIM VAT PHAM THEO TEN----------------          \n";
        cin.ignore();
        cout << "Nhap ten vat pham can tim : ";
        string _name;
        getline(cin, _name);

        _name = DelBlank_and_ToLowercase(_name);
        if (const bool check = find_by_name(_name); !check) cout << "Khong co vat pham nao co ten nhu vay\n";
    }


    void run() {
        showMenu();
        while (true) {
            int value = -1, cnt = 0;
            while (value < 0 || value > 8) {
                if (cnt == 1) cout << "Lenh khong hop le\n";
                cout << "Nhap lua chon : ";
                cin >> value;
                cnt = 1;
            }
            if (value == 0) {
                cout << "Cam on ban da su dung";
                break;
            }

            switch (value) {
                case 1:
                    Add();
                    break;
                case 2:
                    Show();
                    break;
                case 3:
                    if (Sort() == 1) show_list_item();
                    break;
                case 4:
                    Delete();
                    break;
                case 5:
                    Update();
                    break;
                case 6:
                    FindPrice();
                    break;
                case 7:
                    FindItemName();
                    break;
                case 8:
                    showMenu();
                    break;
                default:
                    break;
            }
            cout << "\n";
        }
    }
};

#endif
