#pragma once
namespace york{
class allocator
{
private:
	char * t;
	char ** pool;
	Initpool();
public:
	allocator(void);
	allocator(tpye *);
	allocator(type ,int);
	~allocator(void);	
};
};

