#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
class Fixed {
	private:
		int					fixedPoint;
		static const int	fractionalBit = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int	_fixedPoint);
		Fixed(const float _fixedPoint);

		Fixed& operator=(const Fixed& copy);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;
};

std::ostream& operator<<(std::ostream &out, const Fixed& _Fixed);

#endif
