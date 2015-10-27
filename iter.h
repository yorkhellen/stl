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
		iter<t>(){};
		iter<t>(const york::iter<t> & ls){};
		virtual iter<t> operator ++(){return *this;};
		virtual iter<t> operator ++(int){return *this;};
		virtual bool operator ==(iter<t>){return true;};
		virtual t & operator *()const{ return *val; }
		virtual t * operator ->()const { return val; }
	private:
		pointer val;
	};
};

