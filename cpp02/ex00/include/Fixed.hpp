#pragma once

class Fixed {

public:

	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	Fixed&	operator=(Fixed const &rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);

private:

	int					_bits;
	static const int	fracBit = 8;

};
