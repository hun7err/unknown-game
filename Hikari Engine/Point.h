#ifndef __POINT_H__
#define __POINT_H__

namespace Hikari {
	class Point2D {
		public:
			Point2D(int x, int y): m_x(x), m_y(y) {}

			int x(void) { return m_x; }
			int y(void) { return m_y; }
			void x(int _x) { m_x = _x; }
			void y(int _x) { m_y = _y; }

		private:
			int m_x, m_y;
	};
}

#endif // __POINT_H__