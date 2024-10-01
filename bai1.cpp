#include<iostream>

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
		void xuat(){
			cout<<"Ma can bo: "<<maCanBo<<endl;
			cout<<"Ho ten: "<<hoTen<<endl;
			cout<<"Ngay vao: "<<ngayVao[0]<<"/"<<ngayVao[1]<<"/"<<ngayVao[2]<<endl;
		}

};




int main(){
	canBo *cb = new canBo;
	cout<<"Nhap thong tin canBo: "<<endl;
	cb->nhap();
	cb->xuat();
	
	
	
	return 0;
}
