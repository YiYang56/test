//program 10.8.3.cpp  My_ostream_iterator
	template<class T>
	class My_ostream_iterator
	{
	 private:
	 	 string sep; //分隔符
	 	 ostream & os;
	 public:
	 	My_ostream_iterator(ostream & o, string s):sep(s),os(o)	{ }
		void operator ++() { }; // ++只需要有定义即可，不需要做什么
		My_ostream_iterator & operator * ()
		{	 return * this; 	}
		 My_ostream_iterator & operator = ( const T & val)
		{ 	os << val << sep;    return * this; 	}
	};
