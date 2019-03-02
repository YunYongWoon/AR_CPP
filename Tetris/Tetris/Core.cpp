#include "Core.h"
#include "StageManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() {
}


CCore::~CCore() {
	CStageManager::DestroyInst();

}

bool CCore::Init() {
	// 스테이지 관리자 초기화
	if (!CStageManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run() {
	CStageManager::GetInst()->Run();
}
