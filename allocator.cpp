#include "allocator.h"
#include <malloc.h>

template <class tpye>allocator::allocator(void):t(nullptr),pool(nullptr)
{
	
}
template <class tpye> allocator::allocator(tpye)
{

}
template <class tpye> allocator::allocator(tpye *t,size_t n)
{
	t =(tpye *)malloc(sizeof(tpye) * n);
	if(nullptr == t)
	{
		
	}
}
template <class type>allocator::~allocator(void)
{

}
template <class tpye> allocator::Initpool()
{
	const size_t  size = 20;
	pool = (tpye **) malloc(sizeof(tpye*) * poolsize );
	if(pool  == nullptr)
	{

	}
	for(unsigned int i = 0 ; i < poolsize ; ++i)
		*(pool+i) = (tpye *)malloc(sizeof(tpye) * size);
}
