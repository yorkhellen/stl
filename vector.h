#pragma once
#include "allocator.h"
namespace york {

template <class t , class alloc=york::allocator>class vector
{
public:
	typedef t*  pointer;
	typedef t&  reference;;
	typedef const t* const_pointer;
	typedef const t& const_reference;
	typedef size_t  size_type;

	vector(void);
	vector(size_t t);

	~vector(void);

	size_type size()const{return length;};
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
	
	

};

};

