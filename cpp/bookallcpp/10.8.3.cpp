//program 10.8.3.cpp  My_ostream_iterator
	template<class T>
	class My_ostream_iterator
	{
	 private:
	 	 string sep; //�ָ���
	 	 ostream & os;
	 public:
	 	My_ostream_iterator(ostream & o, string s):sep(s),os(o)	{ }
		void operator ++() { }; // ++ֻ��Ҫ�ж��弴�ɣ�����Ҫ��ʲô
		My_ostream_iterator & operator * ()
		{	 return * this; 	}
		 My_ostream_iterator & operator = ( const T & val)
		{ 	os << val << sep;    return * this; 	}
	};
