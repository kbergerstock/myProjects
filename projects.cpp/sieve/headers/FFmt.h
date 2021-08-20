
#include <iostream>
#include <iomanip>

class FFmt
{
    int myWidth;
    int myPrecision;
public:
    FFmt( int width, int precision )
        : myWidth( width )
        , myPrecision( precision )
    {
    }

    friend std::ostream& operator<<( std::ostream& dest, FFmt const& fmt )
    {
        dest.setf( std::ios_base::fixed, std::ios_base::floatfield );
        dest.precision( fmt.myPrecision );
        dest.width( fmt.myWidth );
        return dest;
    }
};