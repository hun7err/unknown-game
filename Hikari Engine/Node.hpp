#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <d3d.h>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Object.hpp"
#include <list>

namespace Hikari
{
	class Node
	{
		public:
			Node();					/**  */
			Node(Object* pObject);	/**  */

			std::string name(void);			/**  */
			void name(std::string name);	/**  */

			int add(Object* pObject, std::string groupName);		/**  */
			int add(Node* pGroup, std::string groupName);	/**  */

			std::list<Node*>* nodes();
			std::list<Object*>* objects();

			void draw(ID3D11DeviceContext* pDeviceContext);	// zaimplementować!

			//void removeObject(std::string name);
			//void removeGroup(std::string name);

			// ewentualnie move, rotate itp. - zależy od tego, na co pozwala i DirectX i Assimp

			virtual ~Node();

		private:
			std::list<Object*> * m_pObjects;
			std::list<Node*> * m_pNodes;
			std::string m_Name;

			DirectX::XMMATRIX transformationMatrix;
			// node transformation matrix
	};
}

#endif // __NODE_HPP__