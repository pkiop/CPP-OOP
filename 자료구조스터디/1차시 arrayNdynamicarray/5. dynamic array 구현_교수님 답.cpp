//Dynamic array 구현의 한 방법. 하지만 이 방법은 빈번히 일어나는 size변환에서 매우 비효율적.
// 숙제 :  fix darray -> bigger --> reallocation( 넉넉하게)
//                       smaller--> not change
//         배열의 길이와 수열의 길이의 개념을 다르게 해야한다.

//         legnth of array --> capacity(), reverse(sz) ;
//         length of sequence --> size(), resize(sz)
/*
	class darray{
		size_t alen;
		size_t slen;
		data_t* ep;
	길이를 두개를 만들어서 만약 size가 모자라면 넉넉하게 재할당
	size가 남으면 그냥 남겨두자. 
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
	/* 아니면 copy constructor를
	darray(const darray& da) : len(0),ep(NULL){
	alloc_copy 해도 되지만 굳이 이렇게까진 하지 않는다.
	}

	*/
	~darray(void)
	{
		if (ep != NULL)
			delete[] ep;
		len = 0;
	}

	data_t& at(const size_t index) { // 여기서 this에 const를 붙여야 할 것 같지만 하면 안된다. 
		return ep[index];            // 나는 죽이지 않을거다 하고 사람을 암살자에게 넘기는 것과 비슷한 개념
	}

	data_t& operator[](const size_t index) { // 여기서 this에 const를 붙여야 할 것 같지만 하면 안된다. 
		return ep[index];            // 나는 죽이지 않을거다 하고 사람을 암살자에게 넘기는 것과 비슷한 개념
	}

	const data_t& at(const size_t index) const { //만약 정말 바꾸지 않으려고 코딩한 것이면 이런식으로 하는 것이 바람직하다. 
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
		} 이 if else문은 위의 한문장으로 요약 가능 */
		//set이란 함수가 있으면 좋겠다.
		set(ep + prev_len, (len<prev_len ? 0 : len - prev_len), data_t());//data_t는 그 타입의 default값 이문장으로 인해서 아래 for문 주석가능
		//set함수의 두번째 인자가 음수가 되면 굉장히 큰 값이 되기 때문에 run-time error 가 된다. 그래서 typecasting
//		for (size_t i = prev_len; i < len; ++i) // 원래 else안에 있던 문장인데 if안에 들어가도 한번도 안 돌기 때문에 if문밖에써도된다.
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
		} // 길이가 다를때만 재할당 받고 아니면 바로 copy하자
		cpy(ep, da.ep, len);
	}

	void assign(const darray& da) {
		if (this == &da) // prevent self-copy
			return;
		alloc_copy(da);
		//		darray temp(da);
		//		swap(ep, da.ep);// 좋기는 한데 실속없는 코딩 
	}

	void alloc_copy(const darray& da) {
		if (len != da.len) {//if you need reallocation
			if (ep != NULL)
				delete[] ep;
			len = da.len;
			ep = new data_t[da.len];
		} // 길이가 다를때만 재할당 받고 아니면 바로 copy하자
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

	//cout << cda.at(3) << endl; //원하는 parameter = > 첫번째 인자는 그냥 darray* 인데 const darray*을 passing 하고 있다.
							   //const 에 대응하는 함수를 또 만들어 줘야 한다..? 
							   //overriding!
	return 0;
}
