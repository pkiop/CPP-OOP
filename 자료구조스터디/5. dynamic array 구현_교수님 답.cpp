//Dynamic array ������ �� ���. ������ �� ����� ����� �Ͼ�� size��ȯ���� �ſ� ��ȿ����.
// ���� :  fix darray -> bigger --> reallocation( �˳��ϰ�)
//                       smaller--> not change
//         �迭�� ���̿� ������ ������ ������ �ٸ��� �ؾ��Ѵ�.

//         legnth of array --> capacity(), reverse(sz) ;
//         length of sequence --> size(), resize(sz)
/*
	class darray{
		size_t alen;
		size_t slen;
		data_t* ep;
	���̸� �ΰ��� ���� ���� size�� ���ڶ�� �˳��ϰ� ���Ҵ�
	size�� ������ �׳� ���ܵ���. 
*/ 

#include <iostream>
#include <algorithm>

using namespace std;

typedef int data_t;

class darray {
	size_t len; // 32bits --> unsigned int,
				// 64bits --> unsigned long long
	data_t* ep;
	static void cpy(data_t* dst, const data_t* src, size_t len) {
		for (size_t i = 0; i < len; ++i)
			dst[i] = src[i];
	}
	static void set(data_t* dst, size_t len, data_t v) {
		for (size_t i = 0; i<len; ++i)
			dst[i] = v;
	}
public:
	darray(void) :len(0), ep(NULL) {}
	darray(int ll) :len(ll), ep(new data_t[ll]) {}
	darray(const darray& da) :len(da.len), ep(new data_t[da.len]) {
		cpy(ep, da.ep, len);
	}
	/* �ƴϸ� copy constructor��
	darray(const darray& da) : len(0),ep(NULL){
	alloc_copy �ص� ������ ���� �̷��Ա��� ���� �ʴ´�.
	}

	*/
	~darray(void)
	{
		if (ep != NULL)
			delete[] ep;
		len = 0;
	}

	data_t& at(const size_t index) { // ���⼭ this�� const�� �ٿ��� �� �� ������ �ϸ� �ȵȴ�. 
		return ep[index];            // ���� ������ �����Ŵ� �ϰ� ����� �ϻ��ڿ��� �ѱ�� �Ͱ� ����� ����
	}

	data_t& operator[](const size_t index) { // ���⼭ this�� const�� �ٿ��� �� �� ������ �ϸ� �ȵȴ�. 
		return ep[index];            // ���� ������ �����Ŵ� �ϰ� ����� �ϻ��ڿ��� �ѱ�� �Ͱ� ����� ����
	}

	const data_t& at(const size_t index) const { //���� ���� �ٲ��� �������� �ڵ��� ���̸� �̷������� �ϴ� ���� �ٶ����ϴ�. 
		return ep[index];
	}

	void resize(size_t ll) {
		if (len == ll)
			return;

		size_t prev_len = len;
		data_t* prev_ep = ep;

		len = ll;
		ep = new data_t[ll];

		cpy(ep, prev_ep, min(len, prev_len));
		/*if (len < prev_len) {
			cpy(ep, prev_ep, len);
		}
		else {
			cpy(ep, prev_ep, len);
		} �� if else���� ���� �ѹ������� ��� ���� */
		//set�̶� �Լ��� ������ ���ڴ�.
		set(ep + prev_len, (len<prev_len ? 0 : len - prev_len), data_t());//data_t�� �� Ÿ���� default�� �̹������� ���ؼ� �Ʒ� for�� �ּ�����
		//set�Լ��� �ι�° ���ڰ� ������ �Ǹ� ������ ū ���� �Ǳ� ������ run-time error �� �ȴ�. �׷��� typecasting
//		for (size_t i = prev_len; i < len; ++i) // ���� else�ȿ� �ִ� �����ε� if�ȿ� ���� �ѹ��� �� ���� ������ if���ۿ��ᵵ�ȴ�.
//			ep[i] = data_t();
		
		if (prev_ep != NULL)
			delete[] prev_ep;

	}

	data_t size(void) const {
		return len;
	}

	darray& operator=(const darray& da) {
		if (this == &da) // prevent self-copy
			return *this;
		if (len != da.len) {//if you need reallocation
			if (ep != NULL)
				delete[] ep;
			len = da.len;
			ep = new data_t[da.len];
		} // ���̰� �ٸ����� ���Ҵ� �ް� �ƴϸ� �ٷ� copy����
		cpy(ep, da.ep, len);
	}

	void assign(const darray& da) {
		if (this == &da) // prevent self-copy
			return;
		alloc_copy(da);
		//		darray temp(da);
		//		swap(ep, da.ep);// ����� �ѵ� �ǼӾ��� �ڵ� 
	}

	void alloc_copy(const darray& da) {
		if (len != da.len) {//if you need reallocation
			if (ep != NULL)
				delete[] ep;
			len = da.len;
			ep = new data_t[da.len];
		} // ���̰� �ٸ����� ���Ҵ� �ް� �ƴϸ� �ٷ� copy����
		cpy(ep, da.ep, len);
	}

	friend ostream& operator << (ostream& os, const darray& da) {
		for (size_t i = 0; i < da.len; ++i)
			os << da.at(i) << ' ';
		return os;
	}
};

int main(void)
{
	darray da(4);
	da[0] = 11;
	da[1] = 22;
	da[2] = 33;
	da[3] = 44;

	da.resize(3);

	cout << da << endl;
	cout << endl;

	const darray cda(da);
	cout << da << endl;
	cout << endl;

	//cout << cda.at(3) << endl; //���ϴ� parameter = > ù��° ���ڴ� �׳� darray* �ε� const darray*�� passing �ϰ� �ִ�.
							   //const �� �����ϴ� �Լ��� �� ����� ��� �Ѵ�..? 
							   //overriding!
	return 0;
}
