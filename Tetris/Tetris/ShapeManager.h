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
	// �ٴڿ� �׿��ִ� ���� ǥ��
	list<class CShape*> m_ShapeList;

	//���� �����ִ� ���� ǥ��
	class CShape* m_pCurShape;

	//������ ���� ���� ǥ��
	class CShape* m_pNextShape;
	
public:
	void Render();
	void Update();
	class CShape* CreateShape(SHAPE_TYPE eType);
	class CShape* CreateRandomShape();
};

