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
	void ScalarTimesVector(ppMF3DGPVECTOR out , pMF3DGPVECTOR in1 , pSCALAR in2);//标量乘以向量
	void GetContraryVector(ppMF3DGPVECTOR out, pMF3DGPVECTOR in);//相反向量
	void VectorAddition(ppMF3DGPVECTOR out, pMF3DGPVECTOR in1, pMF3DGPVECTOR in2);//向量加法
	void VectorSubtraction(ppMF3DGPVECTOR out, pMF3DGPVECTOR in1, pMF3DGPVECTOR in2);//向量减法
	void GetVectorAbsoluteValue(pSCALAR out, pMF3DGPVECTOR in);//向量绝对值
	void VectorNormalization(ppMF3DGPVECTOR out, pMF3DGPVECTOR in);//向量规范化
	void VectorInnerProduct(pSCALAR out, pMF3DGPVECTOR in1, pMF3DGPVECTOR in2);//向量内积
	void GetTheProjectionOfPOntoQ(ppMF3DGPVECTOR out, pMF3DGPVECTOR p, pMF3DGPVECTOR q);//向量P在Q上的投影
	void GetVectorPIsPerpendicularToQ(ppMF3DGPVECTOR out, pMF3DGPVECTOR p, pMF3DGPVECTOR q);//向量P相对于Q的垂直向量
	void VectorCrossProduct(ppMF3DGPVECTOR out , pMF3DGPVECTOR in1 , pMF3DGPVECTOR in2);//向量外积
	void ParallelogramArea(pSCALAR out, pMF3DGPVECTOR v1, pMF3DGPVECTOR v2, pMF3DGPVECTOR v3);//求平行四边形面积
	void GramSchmidt(ppVectorCollection out , pVectorCollection in);//Gram-Schmidt正交化算法
private:


	static CMF3DGPVectorOperation * m_Instance;
};