#pragma once

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>
using std::cout;
#ifndef YORK
#define YORK
namespace york{

// allocate memory
template<class t>
inline t* _allocate(ptrdiff_t size, t*)
{
	set_new_handler(0);
	t* tmp static_cast<t*>(::operator new((size_t)(size*sizeof(t))));
	if( 0 == tmp)
	{
#ifdef DEBUG
		cout<<"out of memory"<<std::endl;
#endif
		exit(1);
	}
	return tmp;
}
// free memory
template<class t>
inline void _deallocate(t * buffer)
{
	::operator delete(buffer);
}
// call construct and call placement new
template<class t1 , class t2>
inline void  _construct(t1 * p , const t2 & value)
{
	new(p)static_cast<t1>(value);
}
template<class t>
void fill(t  *p, const  t &value)
{
	*p = value;
}
template<class t>
void fill_n(t *p, const t &value, const size_t n)
{
	t * it = p;
	for (int i = 0; i < n; ++i)
	{
		*it = p;
		++it;
	}
	
}
template<class t > 
// here is the allocator class
class allocator
{
   private:
public:
	typedef t               value_type;
	typedef t*              pointer;
	typedef const t *       const_pointer;
	typedef t&              reference;
	typedef const t&        const_reference;
	typedef size_t          size_type;
	typedef ptrdiff_t       difference_type;
	//typedef iter<t>     iterator;

	template <class u >
	struct rebind{
		typedef allocator<u> other;
	};

	size_type max_size()const
	{
		return static_cast<size_type>(UINT_MAX / sizeof(t));
	}

	const_pointer const_address(const_reference x){return static_cast<const_pointer> &x}

	pointer address(reference x){return static_cast<pointer>(&x)};

	void destroy(pointer p){_destroy(p)};

	pointer allocate(size_type n , const void * hint= 0)
	{ 
		return _allocate(static_cast<difference_type>(n), static_cast<pointer>(0));
	}
	void deallocate(pointer p, size_type n){deallocate(p)}

	void construct(pointer p , const t & value)
	{ 
		_construct(p, value);
	}
	allocator(size_type n , const void *  hint  = 0 )
	{
		return allocate(n, hint);
	}
	~allocator(void);	
};
template <>
class allocator<void>
{
public:
	typedef  void * pointer;
};




};
#endif
