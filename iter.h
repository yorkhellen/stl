namespace york
{

	template <class t >
	struct iter
	{
	public:

		typedef t* pointer;
		virtual operator ++();
		virtual operator ++(int);
		virtual operator ==();
		virtual operator *()const{ return *val; }
		virtual operator ->()const { return val; }
	private:
		pointer val;

	};
};