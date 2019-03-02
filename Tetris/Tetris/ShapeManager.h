#pragma once

#include "Value.h"

class CShapeManager
{
private:
	CShapeManager();
	~CShapeManager();

private:
	static CShapeManager* m_pInst;

public:
	static CShapeManager* GetInst() {
		if (!m_pInst)
			m_pInst = new CShapeManager;
		return m_pInst;
	}

	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}
private:
	// 바닥에 쌓여있는 도형 표현
	list<class CShape*> m_ShapeList;

	//현재 나와있는 도형 표현
	class CShape* m_pCurShape;

	//다음에 나올 도형 표현
	class CShape* m_pNextShape;
	
public:
	void Render();
	void Update();
	class CShape* CreateShape(SHAPE_TYPE eType);
	class CShape* CreateRandomShape();
};

