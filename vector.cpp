#include "vector.h"
#include "allocator.h"

namespace york
{

const size_t init_size = 20 ;

template <class t , class alloc=york::allocator<t>> 
vector<t,alloc>::vector(void):
Alloc = new alloc<t>(york::init_size),
len(0),
capality(init_size),
_front(Alloc),
_end(Alloc+init_size+1)
{   	 
};

template <class t , class alloc = york::allocator<t>>	
bool vector<t,alloc>::push_bach(t & value)
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
template <class t, class alloc = york::allocator<t>>
void vector<t,alloc>::resize(size_type new_size)
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
template <class t , class alloc=york::allocator<t>> 
bool vector<t,alloc>::clear()
{

};

;};
