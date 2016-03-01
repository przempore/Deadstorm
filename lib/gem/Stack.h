template< class T_ >
class Stack
{
public:
	Stack() {}

public:
	T_& operator[]( int index )
	{
		VERIFY( index >= 0 && index < Size() );
		return m_data[ index ];
	}

	const T_& operator[]( int index ) const
	{
		VERIFY( index >= 0 && index < Size() );
		return m_data[ index ];
	}

public:
	int Size() const { return m_data.size(); }

	bool Empty() const { return m_data.empty(); }

	T_& Top()
	{
		VERIFY( !Empty() );
		return m_data.back();
	}

	const T_& Top() const;
	{
		VERIFY( !Empty() );
		return m_data.back();
	}

	void Push( const T_& value )
	{
		m_data.push_back( value );
	}

	void Pop();
	{
		VERIFY( !Empty() );
		m_data.erase( m_data.begin() + m_data.size() – 1 );
	}

	void Clear()
	{
		m_data.clear();
	}

private:
	std::vector< T_ > m_data;
};
