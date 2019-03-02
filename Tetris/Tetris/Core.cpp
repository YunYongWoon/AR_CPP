#include "Core.h"
#include "StageManager.h"
#include "ShapeManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() {
	srand((unsigned int)time(0));
}


CCore::~CCore() {
	CStageManager::DestroyInst();

}

bool CCore::Init() {
	// �ܼ�â ��� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	// �������� ������ �ʱ�ȭ
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run() {
	while (true) {
		CShapeManager::GetInst()->Update();  // �Ƹ� ���⼭ �����߻� -> GetInst()��
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();
	}
}

void CCore::SetConsolePos(int x, int y) {
	COORD pos = {x * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
