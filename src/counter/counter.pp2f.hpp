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
	,construction_other_underlying
	,destruction
	,member_get_const
	,member_get_modify
	,operator_assign
	,operator_assign_this
	,operator_assign_underline
	,operator_assign_other
	,operator_convert_const
	,operator_convert_direct
	,operator_plus_unary
	,operator_plus_binary
	,operator_plus_accumulate
	,operator_minus_unary
	,operator_minus_binary
	,operator_minus_accumulate
	,operator_multiply_binary
	,operator_multiply_accumulate
	,operator_divide_binary
	,operator_divide_accumulate
	,operator_module_binary
	,operator_module_accumulate
	,operator_increment_left
	,operator_increment_right
	,operator_decremet_left
	,operator_decremet_right
	,operator_or_bit_accumulate
	,operator_or_bit_binary
	,operator_or_logic_accumulate
	,operator_not
	,operator_or_logic_binary
	,operator_and_bit_accumulate
	,operator_and_bit_binary
	,operator_and_logic_accumulate
	,operator_and_logic_binary
	,operator_xor_bit_accumulate
	,operator_bit_not
	,operator_xor_bit_binary
	,operator_shift_left_binary
	,operator_shift_left_accumulate
	,operator_shift_right_binary
	,operator_shift_right_accumulate
	,operator_equal_strict
	,operator_not_equal_strict
	,operator_less_strict
	,operator_less_equal
	,operator_great_strict
	,operator_great_equal
	,function_cos
	,function_sin
	,function_tan
	,function_acos
	,function_asin
	,function_atan
	,function_cosh
	,function_sinh
	,function_tanh
	,function_acosh
	,function_asinh
	,function_atanh
	,function_atan2
	,function_pow
	,function_sqrt
	,function_cbrt
	,function_hypot
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
		"operator_plus_binary",
		"operator_plus_accumulate",
		"operator_minus_unary",
		"operator_minus_binary",
		"operator_minus_accumulate",
		"operator_multiply",
		"operator_multiply_accumulate",
		"operator_divide_binary",
		"operator_divide_accumulate",
		"operator_module_binary",
		"operator_module_accumulate",
		"operator_increment_left",
		"operator_increment_right",
		"operator_decremet_left",
		"operator_decremet_right",
		"operator_or_bit_accumulate",
		"operator_or_bit_binary",
		"operator_or_logic_binary",
		"operator_or_logic_accumulate",
		"operator_not",
		"operator_and_bit_accumulate",
		"operator_and_bit_binary",
		"operator_and_logic_accumulate",
		"operator_and_logic_binary",
		"operator_xor_bit_accumulate",
		"operator_bit_not",
		"operator_xor_bit_binary",
		"operator_shift_left_binary",
		"operator_shift_left_accumulate",
		"operator_shift_right_binary",
		"operator_shift_right_accumulate",
		"operator_equal_strict",
		"operator_not_equal_strict",
		"operator_less_strict",
		"operator_less_equal",
		"operator_great_strict",
		"operator_great_equal",
		"function_cos",
		"function_sin",
		"function_tan",
		"function_acos",
		"function_asin",
		"function_atan",
		"function_cosh",
		"function_sinh",
		"function_tanh",
		"function_acosh",
		"function_asinh",
		"function_atanh",
		"function_atan2",
		"function_pow",
		"function_sqrt",
		"function_cbrt",
		"function_hypot",
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

	typedef std::vector< counter_type > container_type;

	statistics() {
		m_container.resize(::counter::constant::_last, 0);
	}

	~statistics() {}

	counter_type operator[](key_type const& key)const {
		return this->m_container[ key ];
	}

	void set(key_type const& key, counter_type const& counter) {
		this->m_container[ key ] = counter;
	}

	counter_type const& get(key_type const& key)const {
		return m_container[ key ];
	}

	void increase(key_type const& key) {
		this->set(key, get(key) + 1);
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

	container_type m_container;
};
}

namespace counter {

template
<
	typename underlying_name
	,typename class_name = ::counter::category::common
	>
class number {
public:
	typedef class_name class_type;

	typedef underlying_name underlying_type;

	typedef ::counter::number< underlying_name, class_type > this_type;
	typedef ::counter::statistics statistics_type;

	number() {
		statistics().increase(::counter::constant::construction_blank);
	}

	explicit number(underlying_type const& underlying) {
		this->m_underlying = underlying;
		statistics().increase(::counter::constant::construction_underlying);
	}

	template< typename other_underlying_name >
	number(other_underlying_name const& other_underlying) {
		this->m_underlying = underlying_type(other_underlying);
		statistics().increase(::counter::constant::construction_other_underlying);
	}

	number(this_type const& that) {
		*this = that;
		statistics().increase(::counter::constant::construction_assign);
	}

	~number() {
		statistics().increase(::counter::constant::destruction);
	}

	this_type & operator=(this_type const& that) {
		statistics().increase(::counter::constant::operator_assign_this);
		this->set(that.get());
		return *this;
	}

	this_type & operator=(underlying_type const& that) {
		statistics().increase(::counter::constant::operator_assign_underline);
		this->get() = that;
		return *this;
	}

	template< typename other_underlying_name >
	this_type & operator=(other_underlying_name const& other) {
		statistics().increase(::counter::constant::operator_assign_other);
		this->get() = other;
		return *this;
	}

	operator underlying_type const&()const {
		statistics().increase(::counter::constant::operator_convert_const);
		return m_underlying;
	}

	operator underlying_type &() {
		statistics().increase(::counter::constant::operator_convert_direct);
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
namespace operators {

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator+
(
	::counter::number< underlying_name, class_name > const& left
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_plus_unary);
	return ::counter::number< underlying_name, class_name >(+ left.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator+
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_plus_binary);
	return ::counter::number< underlying_name, class_name >(left.get() + right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator+=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_plus_accumulate);
	left.get() += right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator-
(
	::counter::number< underlying_name, class_name > const& left
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_minus_unary);
	return ::counter::number< underlying_name, class_name >(- left.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator-
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_minus_binary);
	return ::counter::number< underlying_name, class_name >(left.get() - right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator-=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_minus_accumulate);
	left.get() -= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator*
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_multiply_binary);
	return ::counter::number< underlying_name, class_name >(left.get() * right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator *=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_multiply_accumulate);
	left.get() *= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator/
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_divide_binary);
	return ::counter::number< underlying_name, class_name >(left.get() / right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator /=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_divide_accumulate);
	left.get() /= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator%
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_module_binary);
	return ::counter::number< underlying_name, class_name >(left.get() % right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator %=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_module_accumulate);
	left.get() %= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator|
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_or_bit_binary);
	return ::counter::number< underlying_name, class_name >(left.get() | right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator |=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_or_bit_accumulate);
	left.get() |= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator&
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_and_bit_binary);
	return ::counter::number< underlying_name, class_name >(left.get() & right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator &=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_and_bit_accumulate);
	left.get() &= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator^
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_xor_bit_binary);
	return ::counter::number< underlying_name, class_name >(left.get() ^ right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator ^=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_xor_bit_accumulate);
	left.get() ^= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator ~
(
	::counter::number< underlying_name, class_name > & left
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_bit_not);
	return ::counter::number< underlying_name, class_name >(~left.get());
}

template < typename underlying_name, typename class_name >
inline
bool operator &&
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_and_logic_binary);
	return ::counter::number< underlying_name, class_name >(left.get() && right.get());
}
template < typename underlying_name, typename class_name >
inline
bool operator ||
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_or_logic_binary);
	return ::counter::number< underlying_name, class_name >(left.get() || right.get());
}
template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator>>
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_right_binary);
	return ::counter::number< underlying_name, class_name >(left.get() >> right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator >>=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_right_accumulate);
	left.get() >>= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator<<
(
	::counter::number< underlying_name, class_name > const& left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_left_binary);
	return ::counter::number< underlying_name, class_name >(left.get() << right.get());
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > & operator <<=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_shift_left_accumulate);
	left.get() <<= right.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
bool operator !
(
	::counter::number< underlying_name, class_name > const& left
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_not);
	return !left.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator ==
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_equal_strict);
	return left.get() == right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator !=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_not_equal_strict);
	return left.get() != right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator <
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_less_strict);
	return left.get() < right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator <=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_less_equal);
	return left.get() <= right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator >
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_great_strict);
	return left.get() > right.get();
}

template < typename underlying_name, typename class_name >
inline
bool operator >=
(
	::counter::number< underlying_name, class_name > & left, ::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_great_equal);
	return left.get() >= right.get();
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name >& operator ++
(
	::counter::number< underlying_name, class_name > & left
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_increment_left);
	--left.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator ++
(
	::counter::number< underlying_name, class_name > & left, int dummy
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_increment_right);
	auto original = left.get();
	left.get()++;
	return original;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name >& operator --
(
	::counter::number< underlying_name, class_name > & left
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_decremet_left);
	--left.get();
	return left;
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > operator --
(
	::counter::number< underlying_name, class_name > & left, int dummy
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::operator_decremet_right);
	auto original = left.get();
	left.get()--;
	return original;
}

}

}

namespace counter {
namespace functions {

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > cos
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_cos);
	return ::counter::number< underlying_name, class_name >(::cos(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > sin
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_sin);
	return ::counter::number< underlying_name, class_name >(::sin(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > tan
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_tan);
	return ::counter::number< underlying_name, class_name >(::tan(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > acos
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_acos);
	return ::counter::number< underlying_name, class_name >(::acos(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > asin
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_asin);
	return ::counter::number< underlying_name, class_name >(::asin(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > atan
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_atan);
	return ::counter::number< underlying_name, class_name >(::atan(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > atan2
(
	::counter::number< underlying_name, class_name > const& left
	,::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_atan2);
	return ::counter::number< underlying_name, class_name >(::atan2(left.get(), right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > cosh
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_cosh);
	return ::counter::number< underlying_name, class_name >(::cosh(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > sinh
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_sinh);
	return ::counter::number< underlying_name, class_name >(::sinh(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > tanh
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_tanh);
	return ::counter::number< underlying_name, class_name >(::tanh(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > acosh
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_acosh);
	return ::counter::number< underlying_name, class_name >(::acosh(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > asinh
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_asinh);
	return ::counter::number< underlying_name, class_name >(::asinh(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > atanh
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_atanh);
	return ::counter::number< underlying_name, class_name >(::atanh(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > pow
(
	::counter::number< underlying_name, class_name > const& left
	,::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_pow);
	return ::counter::number< underlying_name, class_name >(::pow(left.get(), right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > sqrt
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_sqrt);
	return ::counter::number< underlying_name, class_name >(::sqrt(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > cbrt
(
	::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_cbrt);
	return ::counter::number< underlying_name, class_name >(::cbrt(right.get()));
}

template < typename underlying_name, typename class_name >
inline
::counter::number< underlying_name, class_name > hypot
(
	::counter::number< underlying_name, class_name > const& left
	,::counter::number< underlying_name, class_name > const& right
) {
	::counter::number< underlying_name, class_name >::statistics().increase(::counter::constant::function_hypot);
	return ::counter::number< underlying_name, class_name >(::hypot(left.get(), right.get()));
}

}

}

using namespace ::counter::operators;
