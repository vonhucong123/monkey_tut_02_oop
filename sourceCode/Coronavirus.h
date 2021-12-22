#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Coronavirus
{
public:
	Coronavirus();
	Coronavirus(const Coronavirus& obj);
	~Coronavirus();

	void setDna(std::string &dna);
	std::string getDna();

	void setResistance(int &resistance);
	int getResistance();

	// load thông tin ADN từ file
	void loadADNInformation();
 
	void reduceResistance(int i_medicineResistance);

	// hàm đại diện cho sự sinh ra của virus
	virtual void doBorn();

	// hàm sao chép tất cả các thuộc tính của nó sang một virus mới.
	virtual list<Coronavirus*> doClone();

	// chức năng thể hiện rằng virus đã chết.
	virtual void doDie();
	virtual bool _isDie();
	
	// hàm khởi tạo sức đề kháng của virus và lưu trữ
	virtual void initResistance();

	// xác định loại virus (dùng để phân biệt các loại virus)
	virtual int virusType();

protected:
	// lưu thứ tự của chuỗi axit nucleic (A, T, G, X) 
	std::string m_dna;
	// khả năng đề kháng của virus (10-30)
	int m_resistance;

};

