#include "Entity.h"

bool CEntity::Update(DWORD64 ObjAddress)
{
	if (ObjAddress == 0)
		return false;
	this->Address = ObjAddress;
	if (!this->GetName())
		return false;
	if (this->Name == "" || this->Name != "player" && this->Name != "npc_dummie")
		return false;
	if (this->GetLifeState() != 0)
		return false;
	if (!this->GetPos())
		return false;
	if (!this->GetHeadPos())
		return false;
	if (!this->GetTeam())
		return false;
	if (!this->GetDyingState())
		return false;
	if (!this->GetHealth())
		return false;
	return true;
}

bool CEntity::IsVisible(float WorldTime)
{
	float Time1;
	Time1 = Driver.Read<float>(this->Address + Offset::EntityData.lastVisibleTime);
	return (Time1 + 0.2) >= WorldTime;
}

bool CEntity::GetDyingState()
{
	this->DyingState = Driver.Read<int>(this->Address + Offset::EntityData.m_bleedoutState);
	return true;
}

bool CEntity::GetPos()
{
	this->Pos = Driver.Read<Vec3>(this->Address + Offset::EntityData.m_Pos);
	return true;
}

bool CEntity::GetName()
{
	byte TempData[32]{};
	char* TempName = nullptr;
	DWORD64 NameAddress = Driver.Read<DWORD64>(this->Address + Offset::EntityData.m_iSignifierName);
	if (NameAddress == 0)
		return false;
	if (!Driver.ReadBytes(NameAddress, 32, TempData))
		return false;
	TempName = reinterpret_cast<char*>(TempData);
	this->Name = TempName;
	return true;
}

bool CEntity::GetHeadPos()
{
	DWORD64 BonePointer = Driver.Read<DWORD64>(this->Address + Offset::EntityData.Bone);
	if (BonePointer == 0)
		return false;
	DWORD64 HeadPosAddress = BonePointer + 12 * 48;
	this->HeadPos.x = this->Pos.x + Driver.Read<float>(HeadPosAddress + 12);
	this->HeadPos.y = this->Pos.y + Driver.Read<float>(HeadPosAddress + 28);
	this->HeadPos.z = this->Pos.z + Driver.Read<float>(HeadPosAddress + 44);
	pView->WorldToScreen(this->HeadPos, this->HeadScreenPos);
	return true;
}

bool CEntity::GetHealth()
{
	this->Health = Driver.Read<int>(this->Address + Offset::EntityData.m_iHealth);
	return true;
}

bool CEntity::GetTeam()
{
	this->Team = Driver.Read<int>(this->Address + Offset::EntityData.m_iTeamNum);
	return true;
}

int CEntity::GetLifeState()
{
	return Driver.Read<int>(this->Address + Offset::EntityData.m_lifeState);
}