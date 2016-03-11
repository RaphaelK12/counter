/*
The MIT-Zero License

Copyright (c) 2016> Dejan D. M. Milosavljevic

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

namespace counter {
namespace category {

struct common {

};

}
}

namespace counter {
namespace constant {

enum list {
	construction_blank
	,construction_assign
	,construction_underlying
	,destruction
	,member_get_const
	,member_get_modify
	,operator_assign
	,operator_convert
	,operator_plus_unary
	,operator_plus_full
	,operator_plus_accumulate
	,operator_minus_unary
	,operator_minus_full
	,operator_minus_accumulate
	,operator_multiply_full
	,operator_multiply_accumulate
	,operator_divide_full
	,operator_divide_accumulate
	,operator_module_full
	,operator_module_accumulate
	,operator_increment_left
	,operator_increment_right
	,operator_decremet_left
	,operator_decremet_right
	,operator_or_bit_accumulate
	,operator_or_bit_full
	,operator_or_logic_accumulate
	,operator_not
	,operator_or_logic_full
	,operator_and_bit_accumulate
	,operator_and_bit_full
	,operator_and_logic_accumulate
	,operator_and_logic_full
	,operator_xor_bit_accumulate
	,operator_bit_not
	,operator_xor_bit_full
	,operator_shift_left_full
	,operator_shift_left_accumulate
	,operator_shift_right_full
	,operator_shift_right_accumulate
	,operator_equal_strict
	,operator_not_equal_strict
	,operator_less_strict
	,operator_less_equal
	,operator_great_strict
	,operator_great_equal
	,function_power
	,function_sin
	,function_cos
	,function_tan
	,function_atan
	,_last
};

inline std::string const& to_string(int const& index) {
	static std::vector< std::string > s_name {
		"construction_blank",
		"construction_assign",
		"construction_underlying",
		"destruction",
		"member_get_const",
		"member_get_modify",
		"operator_assign",
		"operator_convert",
		"operator_plus_unary",
		"operator_plus_full",
		"operator_plus_accumulate",
		"operator_minus_unary",
		"operator_minus_full",
		"operator_minus_accumulate",
		"operator_multiply",
		"operator_multiply_accumulate",
		"operator_divide_full",
		"operator_divide_accumulate",
		"operator_module_full",
		"operator_module_accumulate",
		"operator_increment_left",
		"operator_increment_right",
		"operator_decremet_left",
		"operator_decremet_right",
		"operator_or_bit_accumulate",
		"operator_or_bit_full",
		"operator_or_logic_full",
		"operator_or_logic_accumulate",
		"operator_not",
		"operator_and_bit_accumulate",
		"operator_and_bit_full",
		"operator_and_logic_accumulate",
		"operator_and_logic_full",
		"operator_xor_bit_accumulate",
		"operator_bit_not",
		"operator_xor_bit_full",
		"operator_shift_left_full",
		"operator_shift_left_accumulate",
		"operator_shift_right_full",
		"operator_shift_right_accumulate",
		"operator_equal_strict",
		"operator_not_equal_strict",
		"operator_less_strict",
		"operator_less_equal",
		"operator_great_strict",
		"operator_great_equal",
		"function_power",
		"function_sin",
		"function_cos",
		"function_tan",
		"function_atan",
		"_last"
	};
	return s_name[ index ];
}

}
}

namespace counter {

class statistics {
public:

	typedef std::uint32_t key_type;
	typedef std::uint64_t counter_type;

	typedef ::counter::statistics statistics_type;

	typedef std::vector< uint64_t > container_type;

	statistics() {
		m_container.resize(::counter::constant::_last, 0);
	}

	~statistics() {}

	void set(key_type const& key, counter_type const& counter) {
		m_container[ key ] = counter;
	}

	counter_type const& get(key_type const& key) {
		return m_container[ key ];
	}

	void increase(key_type const& key) {
		set(key , get(key) + 1);
	}

	void reset() {
		for(auto & i : m_container) {
			i = 0;
		}
	}

	container_type const& container()const {
		return m_container;
	}
	container_type & container() {
		return m_container;
	}

private:
	bool m_ignore;
	container_type m_container;
};
}

namespace counter {

template
<
typename underlying_name
,typename class_name = ::counter::category::common
>
class model {
public:
	typedef class_name class_type;

	typedef underlying_name underlying_type;

	typedef ::counter::model< underlying_name, class_type > this_type;
	typedef ::counter::statistics statistics_type;

	model() {
		statistics().increase(::counter::constant::construction_blank);
	}

	model(underlying_type const& underlying) {
		this->m_underlying = underlying;
		statistics().increase(::counter::constant::construction_underlying);
	}

	model(this_type const& that) {
		*this = that;
		statistics().increase(::counter::constant::construction_assign);
	}

	~model() {
		statistics().increase(::counter::constant::destruction);
	}

	this_type & operator=(this_type const& that) {
		statistics().increase(::counter::constant::operator_assign);
		this->set(that.get());
		return *this;
	}

	this_type & operator=(underlying_type const& that) {
		statistics().increase(::counter::constant::operator_assign);
		this->get() = that;
		return *this;
	}

	operator underlying_type const&()const {
		statistics().increase(::counter::constant::operator_convert);
		return m_underlying;
	}

	underlying_type const& get()const {
		statistics().increase(::counter::constant::member_get_const);
		return m_underlying;
	}

	underlying_type & get() {
		statistics().increase(::counter::constant::member_get_modify);
		return m_underlying;
	}

	void set(underlying_type const& that) {
		m_underlying = that;
	}

public:
	static statistics_type & statistics() {
		static statistics_type s_statistics;
		return s_statistics;
	}

private:
	underlying_type m_underlying;

};

}

namespace counter {

template< typename underlying_name, typename class_name = ::counter::category::common >
using number = ::counter::model< underlying_name, class_name >;
}

namespace counter {
namespace operators {

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator+
(
	::counter::model< underlying_name, class_name > const& left
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_plus_unary);
	return + left.get();
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator+
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_plus_full);
	return ::counter::model< underlying_name, class_name >(left.get() + right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator+=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_plus_accumulate);
	left.get() += right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator-
(
	::counter::model< underlying_name, class_name > const& left
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_minus_unary);
	return - left.get();
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator-
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_minus_full);
	return ::counter::model< underlying_name, class_name >(left.get() - right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator-=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_minus_accumulate);
	left.get() -= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator*
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_multiply_full);
	return ::counter::model< underlying_name, class_name >(left.get() * right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator *=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_multiply_accumulate);
	left.get() *= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator/
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_divide_full);
	return ::counter::model< underlying_name, class_name >(left.get() / right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator /=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_divide_accumulate);
	left.get() /= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator%
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_module_full);
	return ::counter::model< underlying_name, class_name >(left.get() % right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator %=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_module_accumulate);
	left.get() %= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator|
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_or_bit_full);
	return ::counter::model< underlying_name, class_name >(left.get() | right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator |=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_or_bit_accumulate);
	left.get() |= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator&
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_and_bit_full);
	return ::counter::model< underlying_name, class_name >(left.get() & right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator &=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_and_bit_accumulate);
	left.get() &= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator^
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_xor_bit_full);
	return ::counter::model< underlying_name, class_name >(left.get() ^ right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator ^=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_xor_bit_accumulate);
	left.get() ^= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
underlying_name operator ~
(
	::counter::model< underlying_name, class_name > & left
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_bit_not);
	return ~left.get();
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator &&
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_and_logic_full);
	return ::counter::model< underlying_name, class_name >(left.get() && right.get());
}
template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator ||
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_or_logic_full);
	return ::counter::model< underlying_name, class_name >(left.get() || right.get());
}
template < typename underlying_name, typename class_name >
inline
underlying_name operator !
(
	::counter::model< underlying_name, class_name > const& left
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_not);
	return !left.get();
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator>>
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_right_full);
	return ::counter::model< underlying_name, class_name >(left.get() >> right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator >>=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_right_accumulate);
	left.get() >>= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > operator<<
(
	::counter::model< underlying_name, class_name > const& left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_left_full);
	return ::counter::model< underlying_name, class_name >(left.get() << right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name > & operator <<=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_left_accumulate);
	left.get() <<= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
bool operator ==
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_equal_strict);
	return left.get() == right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator !=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_not_equal_strict);
	return left.get() != right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator <
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_less_strict);
	return left.get() < right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator <=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_less_equal);
	return left.get() <= right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator >
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_great_strict);
	return left.get() > right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator >=
(
	::counter::model< underlying_name, class_name > & left, ::counter::model< underlying_name, class_name > const& right
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_great_equal);
	return left.get() >= right.get();
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name >& operator ++
(
	::counter::model< underlying_name, class_name > & left
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_increment_left);
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name >& operator ++
(
	::counter::model< underlying_name, class_name > & left, int dummy
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_increment_right);
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name >& operator --
(
	::counter::model< underlying_name, class_name > & left
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_decremet_left);
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::model< underlying_name, class_name >& operator --
(
	::counter::model< underlying_name, class_name > & left, int dummy
) {
	::counter::model< underlying_name, class_name >::statistics().increase(::counter::constant::operator_decremet_right);
	return left;
}

}

}

using namespace ::counter::operators;
