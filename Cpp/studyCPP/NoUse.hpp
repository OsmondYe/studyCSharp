// CLASS TEMPLATE initializer_list
template<class _Elem>
class initializer_list
{	// list of pointers to elements
public:
	typedef _Elem value_type;
	typedef const _Elem& reference;
	typedef const _Elem& const_reference;
	typedef size_t size_type;

	typedef const _Elem* iterator;
	typedef const _Elem* const_iterator;

	constexpr initializer_list() noexcept
		: _First(nullptr), _Last(nullptr)
	{	// empty list
	}

	constexpr initializer_list(const _Elem *_First_arg,
		const _Elem *_Last_arg) noexcept
		: _First(_First_arg), _Last(_Last_arg)
	{	// construct with pointers
	}

	_NODISCARD constexpr const _Elem * begin() const noexcept
	{	// get beginning of list
		return (_First);
	}

	_NODISCARD constexpr const _Elem * end() const noexcept
	{	// get end of list
		return (_Last);
	}

	_NODISCARD constexpr size_t size() const noexcept
	{	// get length of list
		return (static_cast<size_t>(_Last - _First));
	}

private:
	const _Elem *_First;
	const _Elem *_Last;
};

// FUNCTION TEMPLATE begin
template<class _Elem>
_NODISCARD constexpr const _Elem * begin(initializer_list<_Elem> _Ilist) noexcept
{	// get beginning of sequence
	return (_Ilist.begin());
}

// FUNCTION TEMPLATE end
template<class _Elem>
_NODISCARD constexpr const _Elem * end(initializer_list<_Elem> _Ilist) noexcept
{	// get end of sequence
	return (_Ilist.end());
}

