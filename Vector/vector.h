#include "point.h"

class Vec{
	private:
		point start, endp;
		double distancia();
		void print();
		public:
		Vec (double startx , double starty , double endpx , double endpy){
			start.x=startx, start.y=starty, endp.x=endpx, endp.y=endpy;
		}
		double getstartx() {return start.x;}
		double getstarty() {return start.y;}
		double getendpx() {return endp.x;}
		double getendpy() {return endp.y;}
};

