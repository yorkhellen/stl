#pragma once
#include "allocator.h"
#include "iter.h"
namespace york {


template <class t , class alloc=york::allocator<t>> class vector
{
public:
	typedef t*  pointer;
	typedef t&  reference;
	typedef const t* const_pointer;
	typedef const t& const_reference;
	typedef size_t  size_type;

	template <class t>
	struct iterator public:iter
	{
		virtual operator ++(){};
		virtual operator ++(int){};
		virtual operator ==(){};
	};

	vector(void);
	vector(size_t t);

	~vector(void);

	const size_type size()const{return len;};
	iterator begin(){ return front; };
	iterator end(){ return back; }
	iterator cbegin()const { return front; };
	iterator cend() const { return back; };
	size_type length()const{ return len};
	bool push_bach(t & value)
	{
		if(len < capality)
		{

		}
		else
		{
			resize(2*capality);
			++len;
		}
	}
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

	}
private:
	alloc * Alloc;
	size_type  len;
	size_type  capality;
	iterator<t>  front;
	iterator<t>  back;
	
	
};

};

