#include "MF3DGPVector.h"
#include <cstdarg>
#include <cstdarg>
#include <cstdlib>

MF3DGPVECTOR::MF3DGPVECTOR(int count, ...)
{
	nCount = count;
	va_list vl;
	va_start(vl , count);
	data = malloc(sizeof(float) * count);
	int addressStart = (int)data;
	for(int i = 0 ; i < count ; i++)
	{
		float f = va_arg(vl, float);
		int addressDes = addressStart + sizeof(float) * i;
		float * pf = (float *)addressDes;
		*pf = f;
	}
	va_end(vl);
}

MF3DGPVECTOR::~MF3DGPVECTOR()
{
	free(data);
}

int MF3DGPVECTOR::GetCount()
{
	return nCount;
}

CMF3DGPVectorOperation * m_Instance = nullptr;

CMF3DGPVectorOperation::CMF3DGPVectorOperation()
{
}

CMF3DGPVectorOperation::~CMF3DGPVectorOperation()
{
}

CMF3DGPVectorOperation * CMF3DGPVectorOperation::GetCMF3DGPVectorOperationInstance()
{
	if(m_Instance == nullptr)
	{
		m_Instance = new CMF3DGPVectorOperation;
	}
	return m_Instance;
}
