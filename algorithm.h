
namespace york 
{

 template <class t, class iterator>
 iterator find (iterator  begin, iterator end, t & value)
 {
    for(iterator i = begin ; i != end ; ++i)
		if(  * i == value) return i ;
	return end ;
 }
 
};