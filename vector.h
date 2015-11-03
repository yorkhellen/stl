#pragma once
#include "allocator.h"
#include "iter.h"
namespace york {

const size_t init_size = 20 ;

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
	iterators(const iterators & val)
	{
	};
	iterators(const t  val)
	{
		this->val = val;
	}

};


template <class t, class alloc=york::allocator<t>> class vector
{
public:
	typedef t*  pointer;
	typedef t&  reference;
	typedef const t* const_pointer;
	typedef const t& const_reference;
	typedef size_t  size_type;
	typedef class iterators<t>   iterator;
	~vector(void){};

	const size_type size()const{return len;};
	iterator begin(){ return _front; };
	iterator end(){ return _end; }
	iterator cbegin()const { return front; };

	iterator cend() const { return back; };

	size_type length()const{ return len};

	vector(const vector<t,alloc>& rval);

	vector operator = (const vector<t,alloc> & rval);

    reference operator [](size_type i)
	{
		return Alloc[i];
	};
	vector(void):
		Alloc =alloc<t>(york::init_size),
		len(0),
		capality(init_size)
		_front(Alloc);
	_end(Alloc +init_size +1)
{  
};

void push_back(const t & value)
{
		if(len < capality)
		{

		}
		else
		{
			resize(2*capality);
			++len;
		}
		return true;
};
void resize(size_type new_size)
{
	   if( new_size > capality)
	   {
		   t * tmp = york::_allocate(new_size,t*);
		   for(int i = 0 ; i <length() ; ++i)
		   {
              
		   }
	   }
	   else if (new_size > length() )
	   {

	   }

};

void clear()
{
	this->len = 0 ;
};

void pop_back()
{
	if(this->len) --len;
};

private:
	alloc * Alloc;
	size_type  len;
	size_type  capality;
    iterator  _front;
	iterator  _end;

};
};

