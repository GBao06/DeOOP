#include<bits/stdc++.h>

using namespace std;

class canBo{
	private:
		string maCanBo,hoTen;
		int ngayVao[3];
	public:
		canBo(){
		}
		canBo( string maCanBo, string hoten, int ngay, int thang, int nam){
			this->maCanBo = maCanBo;
			this->hoTen = hoTen;
			ngayVao[0] = ngay;
			ngayVao[1] = thang;
			ngayVao[2] = nam;
		}
		~canBo(){
		}
		void setMaCanBo(const string &maCanBo){
			this->maCanBo = maCanBo;
		}
		void setHoTen(const string &hoTen){
			this->hoTen = hoTen;
		}
		void setNgayVao( int ngay, int thang, int nam){
			ngayVao[0] = ngay;
			ngayVao[1] = thang;
			ngayVao[2] = nam;
		}
		string getMaCanBo() const{ 
			return maCanBo;
		}
		string gethoTen( ) const{
			return hoTen;
		}
		void getNgayVao( int &ngay, int &thang, int &nam) const{
			 ngay = ngayVao[0];
			 ngay = ngayVao[1];
			 ngay = ngayVao[2];
		}
		void nhap(){
			cout<<"Nhap ma can bo: ";
			getline(cin,maCanBo);
			cout<<"Nhap ho ten: ";
			getline(cin, hoTen);
			cout<<"Nhap ngay vao: ";
			cin>>ngayVao[0]>>ngayVao[1]>>ngayVao[2];
			cin.ignore();
		}
		void xuat() const{
			cout<<"Ma can bo: "<<maCanBo<<endl;
			cout<<"Ho ten: "<<hoTen<<endl;
			cout<<"Ngay vao: "<<ngayVao[0]<<"/"<<ngayVao[1]<<"/"<<ngayVao[2]<<endl;
		}
		bool operator > (const canBo &a) const {
            if (ngayVao[2] != a.ngayVao[2]) return ngayVao[2] > a.ngayVao[2];
            if (ngayVao[1] != a.ngayVao[1]) return ngayVao[1] > a.ngayVao[1];
            return ngayVao[0] > a.ngayVao[0];
        }
};


class GiangVien : public canBo{
	private:
		string donvi;
		int hesoluong;
		int phucap;
	public:
		GiangVien(){
		}
		GiangVien(string maCanBo, string hoTen, int ngay, int thang, int nam,string donvi, int hesoluong, int phucap)
		:canBo(maCanBo,hoTen,ngay,thang,nam){
			this->donvi = donvi;
			this->hesoluong = hesoluong;
			this->phucap = phucap;
		}
		~GiangVien(){
		}
		void setDonVi( const &donvi){
			this->donvi = donvi;
		}
		void sethesoluong (const &hesoluong){
			this->hesoluong = hesoluong;
		}
		void setphucap( const &phucap){
			this->phucap = phucap;
		}
		string getDonvi(){
			return donvi;
		}
		int gethesoluong(){
			return hesoluong;
		}
		int getphucap(){
			return phucap;
		}
		int tinhLuong() const {
        	return hesoluong * 1490000 + phucap;
   		 }
		void nhap(){
			canBo::nhap();
			cout<<"Nhap don vi cua can bo: ";
			getline(cin,donvi);
			cout<<"Nhap he so luong: ";
			cin>>hesoluong;
			cout<<"Nhap phu cap: ";
			cin>>phucap;
			cin.ignore();
		}
		void xuat() const {
	        canBo::xuat();
	        cout << "Don vi: " << donvi << endl;
	        cout << "He so luong: " << hesoluong << endl;
	        cout << "Phu cap chuc vu: " << phucap << endl;
	        cout << "Tien luong: " << tinhLuong() << " VND" << endl;
   	 	}
   	 	
		 
};


int main(){
	int count = 0;
	int n;
	cout<<"Nhap so luong giang vien: ";
	cin>>n;
	cin.ignore();
	GiangVien giangVien[50];
	for( int i = 0; i<n; i++){
		cout << "\nNhap thong tin giang vien thu " << i + 1 << ":\n";
		giangVien[i].nhap();
		count++;
	}
	cout<<"\n\nThong tin cac can bo: \n";
   	for( int i = 0; i<n; i++){
		giangVien[i].xuat();
	}
	
	
	for( int i=0; i<n-1; i++){
		for( int j=i+1; j<n; j++){
			if( giangVien[i] > giangVien[j]){
				swap(giangVien[i],giangVien[j]);
			}
		}
	}
	cout<<"\n\nThong tin cac can bo sau khi sap xep: \n";
	for( int i = 0; i<n; i++){
		giangVien[i].xuat();
	}
	cout<<"Luong trung binh cua tat ca cac can bo: ";
	int sum = 0;
	for( int i =0; i<n; i++){
		sum+= giangVien[i].tinhLuong();
	}
	cout<<sum/count<<" VND"<<endl;
	return 0;
}
