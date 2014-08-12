#include "../../../../include/Core/Objects/Node/Node.hpp"
using namespace DirectX;

Hikari::Node::Node()
{
	initialize();
}

Hikari::Node::Node(Hikari::Object* pObject)
{
	initialize();
	m_pObjects->push_back(pObject);
}

void Hikari::Node::initialize(void)
{
	m_pNodes = new std::list<Hikari::Node*>();
	m_pObjects = new std::list<Hikari::Object*>();
	XMStoreFloat4x4(&m_TransformationMatrix, XMMatrixIdentity());
}

Hikari::Node::~Node()
{
	delete m_pNodes;
	delete m_pObjects;
}

std::list<Hikari::Node*>* Hikari::Node::nodes(void)
{
	return m_pNodes;
}

std::list<Hikari::Object*>* Hikari::Node::objects(void)
{
	return m_pObjects;
}

void Hikari::Node::draw(XMFLOAT4X4 transformationMatrix)
{
	XMFLOAT4X4 newTransformation;
	XMStoreFloat4x4(&newTransformation, XMMatrixMultiply(XMLoadFloat4x4(&transformationMatrix), XMLoadFloat4x4(&m_TransformationMatrix)));

	for(std::list<Object*>::iterator currentObject = m_pObjects->begin(); currentObject != m_pObjects->end(); ++currentObject)
	{
		(*currentObject)->draw(newTransformation);
	}

	for(std::list<Node*>::iterator currentNode = m_pNodes->begin(); currentNode != m_pNodes->end(); ++currentNode)
	{
		(*currentNode)->draw(newTransformation);
	}
}

void Hikari::Node::draw(void)
{
	XMFLOAT4X4 transformation;
	XMStoreFloat4x4(&transformation, XMMatrixIdentity());

	draw(transformation);
}

Hikari::Node* Hikari::Node::load(std::string filename)
{
	return new Node();	// do zaimplementowania ³adowanie Assimpem
}

std::string Hikari::Node::name(void)
{
	return m_Name;
}

void Hikari::Node::name(std::string name)
{
	m_Name = name;
}

void Hikari::Node::add(Hikari::Object *pObject)
{
	m_pObjects->push_back(pObject);
}

int Hikari::Node::add(Hikari::Object* pObject, std::string groupName)
{
	if( m_Name == groupName )
	{
		m_pObjects->push_back(pObject);
		return 0;
	}

	if( ! m_pNodes->empty() )
	{
		for(auto currentGroup = m_pNodes->begin(); currentGroup != m_pNodes->end(); ++currentGroup)
		{
			if((*currentGroup)->add(pObject, groupName) == 0)	// +- DFS
			{
				return 0;
			}
		}
	}
	return -1;
}

void Hikari::Node::add(Hikari::Node *pNode)
{
	m_pNodes->push_back(pNode);
}

int Hikari::Node::add(Hikari::Node* pGroup, std::string groupName)
{
	if( m_Name == groupName )
	{
		m_pNodes->push_back(pGroup);
		return 0;
	}

	if( ! m_pNodes->empty() )
	{
		for(auto currentGroup = m_pNodes->begin(); currentGroup != m_pNodes->end(); ++currentGroup)
		{
			if((*currentGroup)->add(pGroup, groupName) == 0)	// +- DFS
			{
				return 0;
			}
		}
	}
	return -1;
}

void Hikari::Node::setup(void)
{
	for(std::list<Object*>::iterator currentObject = m_pObjects->begin(); currentObject != m_pObjects->end(); ++currentObject)
	{
		(*currentObject)->setup();
	}

	for(std::list<Node*>::iterator currentNode = m_pNodes->begin(); currentNode != m_pNodes->end(); ++currentNode)
	{
		(*currentNode)->setup();
	}
}
