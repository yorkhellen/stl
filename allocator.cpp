#include "allocator.h"
namespace york
{

template <class t> t* allocator<t>::allocate(size_t n , const void * hint= 0)
{ 
	return _allocate<t>(static_cast<difference_type>(n), static_cast<pointer>(0));
}

template <class t > allocator<t>::allocator(size_t n , const void *  hint  = 0 )
{
	return allocate<t>(n, hint);
};



;};