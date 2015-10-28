namespace york
{
template <class t>
struct iterator_traits
{
	typedef typename t::value_type value_type;
};

	template <class t >
	struct iter
	{

	 public:
		typedef t* pointer;
		typedef t value_type;
		iter<t>(t):this->val(&t){};
		iter<t>(const york::iter<t> & ls){ pointer = &(ls->val)};
	     iter<t> operator ++();
		 iter<t> operator ++(int);
		 bool operator ==(iter<t>);
		 t & operator *()const{ return *val; }
		 t * operator ->()const { return val; }
	 private:
		pointer val;
	};
};

