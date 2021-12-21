#pragma once
#include <iostream>
#include <string>
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

	// khi một bệnh nhân gọi hàm takeMedicine, 
	// giống như việc bệnh nhân uống thuốc, 
	// nó sẽ làm giảm sức đề kháng của virus. 
	// Nếu m_resistance của virus <= 0, virus sẽ bị tiêu diệt. 
	// Triển khai method ReduceResistance theo công thức :
	// m_resistance = m_resistance – i_medicineResistance; 
	void reduceResistance(int i_medicineResistance);

	// hàm đại diện cho sự sinh ra của virus
	virtual void doBorn();

	// hàm sao chép tất cả các thuộc tính của nó sang một virus mới.
	virtual void doClone();

	// chức năng thể hiện rằng virus đã chết.
	virtual void doDie();

	// hàm khởi tạo sức đề kháng của virus và lưu trữ
	virtual void initResistance();

protected:
	// lưu thứ tự của chuỗi axit nucleic (A, T, G, X) 
	std::string m_dna;
	// khả năng đề kháng của virus (10-30)
	int m_resistance;

};

