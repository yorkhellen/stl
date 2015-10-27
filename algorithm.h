
namespace york 
{

 template <class t, class iterator>
 iterator find (iterator  begin, iterator end, const t & value)
 {
 
  while (begin != end  && *begin  != value) ++ begin;
  return begin;
 }
 
};