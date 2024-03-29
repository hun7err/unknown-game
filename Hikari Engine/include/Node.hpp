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

			void add(Object *pObject);
			int add(Object *pObject, std::string groupName);		/**  */
			void add(Node *pGroup);
			int add(Node *pGroup, std::string groupName);	/**  */
			void setup(void);

			std::list<Node*>* nodes();
			std::list<Object*>* objects();

			void draw(void);	// zaimplementować!

			static Node* load(std::string filename);

			//void removeObject(std::string name);
			//void removeGroup(std::string name);

			// ewentualnie move, rotate itp. - zależy od tego, na co pozwala i DirectX i Assimp

			virtual ~Node();

		private:
			std::list<Object*> * m_pObjects;
			std::list<Node*> * m_pNodes;
			std::string m_Name;
			void initialize(void);

			DirectX::XMMATRIX m_TransformationMatrix;
			// node transformation matrix
	};
}

#endif // __NODE_HPP__