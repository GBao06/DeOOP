#include<bits/stdc++.h>
using namespace std;

class nguoi {
private:
    string hodem, ten;
    int ngaysinh[3];  
public:
    nguoi() {
        hodem = ten = "";
        ngaysinh[0] = ngaysinh[1] = ngaysinh[2] = 0;
    }
    nguoi(string hodem, string ten, int ngay, int thang, int nam) {
        this->hodem = hodem;
        this->ten = ten;
        this->ngaysinh[0] = ngay;
        this->ngaysinh[1] = thang;
        this->ngaysinh[2] = nam;
    }
    nguoi(const nguoi &x) {
        this->hodem = x.hodem;
        this->ten = x.ten;
        this->ngaysinh[0] = x.ngaysinh[0];
        this->ngaysinh[1] = x.ngaysinh[1];
        this->ngaysinh[2] = x.ngaysinh[2];
    }


    void nhap() {
        cin.ignore();
        cout << "Nhap ho dem: ";
        getline(cin, hodem);
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap ngay sinh: ";
        cin >> ngaysinh[0] >> ngaysinh[1] >> ngaysinh[2];
    }


    void xuat() const {
        cout << "Ho va ten: " << hodem << " " << ten << endl;
        cout << "Ngay sinh: " << ngaysinh[0] << "/" << ngaysinh[1] << "/" << ngaysinh[2] << endl;
    }


    bool operator > (const nguoi &x) const {
        if (ten != x.ten) return ten > x.ten; 
        return hodem > x.hodem;  
    }
};

class sinhvien : public nguoi {
private:
    string masv;
    double dtb; 
public:
    sinhvien() {
        masv = "";
        dtb = 0.0;
    }
    sinhvien(string masv, double dtb, string hodem, string ten, int ngay, int thang, int nam) 
        : nguoi(hodem, ten, ngay, thang, nam) {
        this->masv = masv;
        this->dtb = dtb;
    }
    void nhap() {
        nguoi::nhap();
        cout << "Nhap ma sinh vien: ";
        cin >> masv;
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
    }
    void xuat() const {
        nguoi::xuat();
        cout << "Ma sinh vien: " << masv << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }
    string getMsv() const { return masv; }
    double getDtb() const { return dtb; }
};

bool compare(const sinhvien &a, const sinhvien &b) {
    return a > b; 
}

int main() {
    cout << "Nhap so luong sinh vien: ";
    int n; cin >> n;
    vector<sinhvien> v(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien " << i + 1 << ":\n";
        v[i].nhap();
    }
//    cout << "\n----------------------\n";
//    cout << "Danh sach sinh vien: \n";
//    for (int i = 0; i < n; i++) {
//        cout << "Sinh vien " << i + 1 << ":\n";
//        v[i].xuat();
//    }


    sort(v.begin(), v.end(), compare);

    cout << "\n----------------------\n";
    cout << "Danh sach sinh vien sau khi sap xep theo ho dem:\n";
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        v[i].xuat();
    }
    cout << "\n----------------------\n";
    cout << "Nhung sinh vien co diem trung binh cao nhat: \n";
	
	double max_dtb = v[0].getDtb();
	for ( int i=0; i<n;i++){
		if( v[i].getDtb() == max_dtb){
			v[i].xuat();
		}
	}
    return 0;
}

