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
	// 콘솔창 행들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	// 스테이지 관리자 초기화
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run() {
	while (true) {
		CShapeManager::GetInst()->Update();  // 아마 여기서 문제발생 -> GetInst()가
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();
	}
}

void CCore::SetConsolePos(int x, int y) {
	COORD pos = {x * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
