#ifndef __MATERIALMANAGER_HPP__
#define __MATERIALMANAGER_HPP__

#include "Material.hpp"
#include "Manager.hpp"

namespace Hikari
{
	typedef Manager<Material> MaterialManager;

	std::vector<Material*> MaterialManager::m_Items;
	std::mutex MaterialManager::m_ItemMutex;
}

/*
namespace Hikari
{
	template <typename TypeName> class Manager
	{
		public:
			static unsigned int add(TypeName* pMaterial);
			static TypeName* get(unsigned int key);
			static TypeName* get(std::string name);
			static void remove(std::string name);
			static void remove(unsigned int key);

		protected:
			static std::vector<TypeName*> m_Items;
			Manager();
			static std::mutex m_ItemMutex;
	};

	class MaterialManager
	{
		public:
			static unsigned int add(Material* pMaterial);
			static Material* get(unsigned int key);
			static Material* get(std::string name);
			static void remove(std::string name);
			static void remove(unsigned int key);

		private:
			static std::vector<Material*> m_Items;
			MaterialManager();
			static std::mutex m_ItemMutex;
	};

	std::vector<Material*> MaterialManager::m_Items;
	std::mutex MaterialManager::m_ItemMutex;
}
*/

#endif