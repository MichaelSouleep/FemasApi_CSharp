// MdApi.cpp : ���� DLL Ӧ�ó���ĵ���������
//
#include "stdafx.h"
#include "MdApi.h"

using namespace std;

extern CUstpFtdcMduserApi* pUserApi;
extern CBOnFrontConnected cbOnFrontConnected ;
extern CBOnFrontDisconnected cbOnFrontDisconnected ;
extern CBOnHeartBeatWarning cbOnHeartBeatWarning ;
///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
extern CBOnPackageStart cbOnPackageStart ;
///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
extern CBOnPackageEnd cbOnPackageEnd ;
extern CBOnRspError cbOnRspError ;
extern CBOnRspUserLogin cbOnRspUserLogin ;
extern CBOnRspUserLogout cbOnRspUserLogout ;
extern CBOnRspSubscribeTopic cbOnRspSubscribeTopic ;
///�����ѯӦ��
extern CBOnRspQryTopic cbOnRspQryTopic ;
///�������֪ͨ
extern CBOnRtnDepthMarketData cbOnRtnDepthMarketData ;
extern CBOnRspSubMarketData cbOnRspSubMarketData ;
extern CBOnRspUnSubMarketData cbOnRspUnSubMarketData ;

CMdSpi::CMdSpi()
{
	return;
}

void CMdSpi::OnFrontConnected()
{
	if (cbOnFrontConnected != NULL)
		cbOnFrontConnected();
}


///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
///@param nReason ����ԭ��
///        0x1001 �����ʧ��
///        0x1002 ����дʧ��
///        0x2001 ����������ʱ
///        0x2002 ��������ʧ��
///        0x2003 �յ�������
void CMdSpi::OnFrontDisconnected(int nReason) {
	if (cbOnFrontDisconnected != NULL)
	{
		cbOnFrontDisconnected(nReason);
	}
}
///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
void CMdSpi::OnHeartBeatWarning(int nTimeLapse) {
	if (cbOnHeartBeatWarning != NULL)
	{
		cbOnHeartBeatWarning(nTimeLapse);
	}
}
///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
///@param nTopicID ������루��˽���������������������ȣ�
///@param nSequenceNo �������
void CMdSpi::OnPackageStart(int nTopicID, int nSequenceNo) {
	if (cbOnPackageStart != NULL)
	{
		cbOnPackageStart(nTopicID, nSequenceNo);
	}
}
///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
///@param nTopicID ������루��˽���������������������ȣ�
///@param nSequenceNo �������
void CMdSpi::OnPackageEnd(int nTopicID, int nSequenceNo) {
	if (cbOnPackageEnd != NULL)
	{
		cbOnPackageEnd(nTopicID, nSequenceNo);
	}
}
///����Ӧ��
void CMdSpi::OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspError != NULL)
	{
		cbOnRspError(repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///���ǰ��ϵͳ�û���¼Ӧ��
void CMdSpi::OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspUserLogin != NULL)
	{
		cbOnRspUserLogin(pRspUserLogin, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///�û��˳�Ӧ��
void CMdSpi::OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspUserLogout != NULL)
	{
		cbOnRspUserLogout(pRspUserLogout, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///��������Ӧ��
void CMdSpi::OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspSubscribeTopic != NULL)
	{
		cbOnRspSubscribeTopic(pDissemination, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///�����ѯӦ��
void CMdSpi::OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspQryTopic != NULL)
	{
		cbOnRspQryTopic(pDissemination, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///�������֪ͨ
void CMdSpi::OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField *pDepthMarketData) {
	if (cbOnRtnDepthMarketData != NULL)
	{
		cbOnRtnDepthMarketData(pDepthMarketData);
	}
}
///���ĺ�Լ�������Ϣ
void CMdSpi::OnRspSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspSubMarketData != NULL)
	{
		cbOnRspSubMarketData(pSpecificInstrument, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///�˶���Լ�������Ϣ
void CMdSpi::OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	if (cbOnRspUnSubMarketData != NULL)
	{
		cbOnRspUnSubMarketData(pSpecificInstrument, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}



//����յ��շ����Ĵ���
CUstpFtdcRspInfoField rif;
CUstpFtdcRspInfoField* CMdSpi::repareInfo(CUstpFtdcRspInfoField *pRspInfo)
{
	if (pRspInfo == NULL)
	{
		memset(&rif, 0, sizeof(rif));
		return &rif;
	}
	else
		return pRspInfo;
}


