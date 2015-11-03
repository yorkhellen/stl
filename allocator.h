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
	struct _Nonscalar_ptr_iterator_tag
	{	// pointer to unknown type
	};
	struct _Scalar_ptr_iterator_tag
	{	// pointer to scalar type
	};
template<class t>
inline t* _allocate(size_t size, t*)
{
	void * tmp;
	if (0 == size)
		;
	else if (((size_t)(-1) / sizeof(t) < size)
		|| tmp = ::operator new(size*sizeof(t))) == 0 )
		exit(1);
	return static_cast<t *>(tmp);
}
// free memory
template<class t>
inline void _deallocate(t * buffer)
{
	::operator delete(buffer);
}
// call construct and call placement new
template<class t1 , class t2>
inline void  _construct(t1 * p , const t2 && value)
{
	void * vptr = p;
	::new(vptr)(static_cast<t1>(value));
}

template<class t >
int void _construct(t * ptr)
{
	void * vptr = ptr;
	::new(vptr)t();
}
template<class t>
inline void _destroy(t * ptr)
{
	ptr->~t();
}
// sp
template< class t >
inline void _destory(char *)
{}

template <class t >
inline void _destory(wchar_t *)
{}
template <class t>
inline void _destory(unsigned short *)
{}
template <class alloc>
	inline void  _destory_range(typename alloc::pointer _first,
	typename alloc::pointer _last, alloc & al, 
	_Nonscalar_ptr_iterator_tag)
{
		for (; _first != _last; ++first)
			al.destory(_first);
	}

template<class alloc> inline
void _Destroy_range(typename alloc::pointer _First,
typename alloc::pointer _Last, alloc& _Al,
_Scalar_ptr_iterator_tag)
{	// destroy [_First, _Last), scalar type (do nothing)
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
    pointer	allocate(size_t n , const void * hint= 0);
	void deallocate(pointer p, size_type n){destroy(p)}
	allocator(size_t n , const void *  hint  = 0 );
	~allocator(void){destroy};	
};
template <>
class allocator<void>
{
public:
	typedef  void * pointer;
};

};
#endif
