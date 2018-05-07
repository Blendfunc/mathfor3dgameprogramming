#pragma once
#include <vector>
struct MF3DGPVECTOR
{
public:
	MF3DGPVECTOR(int count , ...);
	~MF3DGPVECTOR();
	int GetCount();
private:
	void * data;
	int nCount;
};

typedef MF3DGPVECTOR * pMF3DGPVECTOR;
typedef MF3DGPVECTOR ** ppMF3DGPVECTOR;
typedef float SCALAR;
typedef float * pSCALAR;
typedef std::vector<MF3DGPVECTOR> VectorCollection;
typedef VectorCollection * pVectorCollection;
typedef VectorCollection ** ppVectorCollection;

class CMF3DGPVectorOperation
{
public:
	CMF3DGPVectorOperation();
	~CMF3DGPVectorOperation();
public:
	static CMF3DGPVectorOperation * GetCMF3DGPVectorOperationInstance();
public:
	void ScalarTimesVector(ppMF3DGPVECTOR out , pMF3DGPVECTOR in1 , pSCALAR in2);//������������
	void GetContraryVector(ppMF3DGPVECTOR out, pMF3DGPVECTOR in);//�෴����
	void VectorAddition(ppMF3DGPVECTOR out, pMF3DGPVECTOR in1, pMF3DGPVECTOR in2);//�����ӷ�
	void VectorSubtraction(ppMF3DGPVECTOR out, pMF3DGPVECTOR in1, pMF3DGPVECTOR in2);//��������
	void GetVectorAbsoluteValue(pSCALAR out, pMF3DGPVECTOR in);//��������ֵ
	void VectorNormalization(ppMF3DGPVECTOR out, pMF3DGPVECTOR in);//�����淶��
	void VectorInnerProduct(pSCALAR out, pMF3DGPVECTOR in1, pMF3DGPVECTOR in2);//�����ڻ�
	void GetTheProjectionOfPOntoQ(ppMF3DGPVECTOR out, pMF3DGPVECTOR p, pMF3DGPVECTOR q);//����P��Q�ϵ�ͶӰ
	void GetVectorPIsPerpendicularToQ(ppMF3DGPVECTOR out, pMF3DGPVECTOR p, pMF3DGPVECTOR q);//����P�����Q�Ĵ�ֱ����
	void VectorCrossProduct(ppMF3DGPVECTOR out , pMF3DGPVECTOR in1 , pMF3DGPVECTOR in2);//�������
	void ParallelogramArea(pSCALAR out, pMF3DGPVECTOR v1, pMF3DGPVECTOR v2, pMF3DGPVECTOR v3);//��ƽ���ı������
	void GramSchmidt(ppVectorCollection out , pVectorCollection in);//Gram-Schmidt�������㷨
private:


	static CMF3DGPVectorOperation * m_Instance;
};