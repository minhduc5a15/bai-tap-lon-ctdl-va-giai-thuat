#ifndef APP_H
#define APP_H

#include "list_item.hpp"

class App : public List_item {
public:
    static void showMenu() {
        cout << "-------------------------------Ứng Dụng Mua Sắm------------------------------\n";
        cout << "------------------------------------------------------------------------\n";
        cout << "=====     Menu:                                                    =====\n"
                "=====       1. Thêm vật phẩm                                       =====\n"
                "=====       2. Hiển thị danh sách                                  =====\n"
                "=====       3. Sắp xếp theo giá tiền                               =====\n"
                "=====       4. Xóa vật phẩm theo Id                                =====\n"
                "=====       5. Cập nhật thông tin vật phẩm theo Id                 =====\n"
                "=====       6. Tìm vật phẩm theo khoảng giá                        =====\n"
                "=====       7. Tìm vật phẩm theo tên                               =====\n"
                "=====       8. Hiển thị Menu                                       =====\n"
                "=====       0. Thoát                                               =====\n";
        cout << "------------------------------------------------------------------------\n";
        cout << "------------------------------------------------------------------------\n";
    }

    void Add() {
        cout << "          -------------------THÊM VẬT PHẨM--------------------          \n";
        cout << "Nhập số vật phẩm muốn thêm: ";
        int n;
        cin >> n;
        add_item(n);
        cout << "--- Đã thêm " << n << " vật phẩm ---\n";
    }

    void Show() {
        cout << "          ---------------HIỂN THỊ DANH SÁCH-------------------          \n";
        show_list_item();
    }

    int Sort() {
        cout << "          -------------SẮP XẾP THEO GIÁ TIỀN------------------          \n";
        if (get_size() == 0) {
            cout << "Danh sách đang trống\n";
            return 0;
        }

        int value = 2;
        while (value < 0 || value > 1) {
            cout << "Sắp xếp theo giá tăng (1) hoặc giảm (0): ";
            cin >> value;
        }
        if (value == 1) sort_item(true);
        else sort_item(false);
        value = 2;
        while (value < 0 || value > 1) {
            cout << "Bạn có muốn hiển thị danh sách không (1. Có), (0. Không): ";
            cin >> value;
        }
        return value;
    }

    void Delete() {
        cout << "          --------------------XÓA VẬT PHẨM--------------------          \n";
        cout << "Nhập id vật phẩm: ";
        string id;
        cin >> id;
        if (const int index = find_by_id(id); index == -1) cout << "Không có vật phẩm này\n";
        else {
            delete_item(index);
            cout << "\nXóa thành công\n";
        }
    }

    void Update() {
        cout << "          -----------------CẬP NHẬT THÔNG TIN-----------------          \n";
        cout << "Nhập id vật phẩm: ";
        string id;
        cin >> id;
        if (const int index = find_by_id(id); index == -1) cout << "Không có vật phẩm này\n";
        else {
            update_item(index);
            cout << "Cập nhật thành công\n";
        }
    }

    void FindPrice() {
        cout << "          -------------TÌM VẬT PHẨM THEO GIÁ TIỀN-------------          \n";
        double Min = 10, Max = 1;

        int cnt = 0;
        while (Min > Max) {
            if (cnt == 1) cout << "Vui lòng nhập Min <= Max\n";
            cout << "Nhập khoảng giá [Min Max]: ";
            cin >> Min >> Max;
            cnt = 1;
        }
        cout << "Các vật phẩm có giá tiền trong khoảng [" << Min << ", " << Max << "] : \n";
        if (const bool check = find_by_price(Min, Max); !check) cout << "Không có vật phẩm nào\n";
    }

    void FindItemName() {
        cout << "          ---------------TÌM VẬT PHẨM THEO TÊN----------------          \n";
        cin.ignore();
        cout << "Nhập tên vật phẩm cần tìm: ";
        string _name;
        getline(cin, _name);

        _name = format(_name);
        if (const bool check = find_by_name(_name); !check) cout << "Không có vật phẩm nào có tên như vậy\n";
    }

    void run() {
        showMenu();
        while (true) {
            int value = -1, cnt = 0;
            while (value < 0 || value > 8) {
                if (cnt == 1) cout << "Lệnh không hợp lệ\n";
                cout << "Nhập lựa chọn: ";
                cin >> value;
                cnt = 1;
            }
            if (value == 0) {
                cout << "Cảm ơn bạn đã sử dụng";
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
