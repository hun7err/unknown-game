#ifndef __HANDLE_HPP__
#define __HANDLE_HPP__

namespace Hikari
{
	template <typename TypeName> class Handle
	{
		public:
			Handle(int key = -1) : m_ItemKey(key) {}

			virtual TypeName* operator->(void) const = 0;
			int key(void)
			{
				return m_ItemKey;
			}
			void key(int newKey)
			{
				m_ItemKey = newKey;
			}

			virtual bool isValid() = 0;

		protected:
			int m_ItemKey;
	};
}

#endif