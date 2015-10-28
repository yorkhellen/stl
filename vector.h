#pragma once
#include "allocator.h"
#include "iter.h"
namespace york {
template <class t> 
class iterators: public iter<t>
{
	iter<t> operator ++(){ ++(this->val); return *this};
	iter<t> operator ++(int){iterators<t> tmp = *this, ++(this->val), return tmp ;};
	bool operator ==(iter<t> & rl){
		if(*(this->val)  == *(rl->val))
		  return true;
		return false ;
	};

};
template <class t , class alloc=york::allocator<t>> class vector
{
public:
	typedef t*  pointer;
	typedef t&  reference;
	typedef const t* const_pointer;
	typedef const t& const_reference;
	typedef size_t  size_type;
	typedef class iterators<t>   iterator;
	vector(void);
	~vector(void){};

	const size_type size()const{return len;};
	iterator begin(){ return _front; };
	iterator end(){ return _end; }
	iterator cbegin()const { return front; };
	iterator cend() const { return back; };
	size_type length()const{ return len};
	bool push_bach(t & value);
	void resize(size_type new_size);
    bool  clear();
	vector<t,alloc>(const vector<t,alloc>& rval);
	vector<t,alloc> operator = (const vector<t,alloc> & rval);
	vector<t,alloc> operator [](const int);
private:
	alloc * Alloc;
	size_type  len;
	size_type  capality;
    iterator  _front;
	iterator  _end;
};
};

