#ifndef __HANDLE_HPP__
#define __HANDLE_HPP__

namespace Hikari
{
	template <typename TypeName> class Handle
	{
		public:
			virtual TypeName* operator->(void) const = 0;
			int key(void)
			{
				return m_ItemKey;
			}

			virtual bool isValid() = 0;

		protected:
			int m_ItemKey;
	};
}

#endif