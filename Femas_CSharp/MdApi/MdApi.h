// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MDAPI_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// extern "C" MDAPI_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MDAPI_EXPORTS
#define MDAPI_API __declspec(dllexport)
#else
#define MDAPI_API __declspec(dllimport)
#endif
#pragma once
#include "USTPFtdcMduserApi.h"

class CMdSpi:public CUstpFtdcMduserSpi
{
public:
	CMdSpi(void);
	//~CMdSpi();

public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected() ;

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason) ;

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse) ;

	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo) ;

	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo) ;


	///����Ӧ��
	virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///���ǰ��ϵͳ�û���¼Ӧ��
	virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯӦ��
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField *pDepthMarketData) ;

	///���ĺ�Լ�������Ϣ
	virtual void OnRspSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�˶���Լ�������Ϣ
	virtual void OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

private:
	CUstpFtdcRspInfoField* repareInfo(CUstpFtdcRspInfoField *pRspInfo);
};



typedef int (WINAPI *CBOnFrontConnected)();
typedef int (WINAPI *CBOnFrontDisconnected)(int nReason);
typedef int (WINAPI *CBOnHeartBeatWarning)(int nTimeLapse);
///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
typedef int (WINAPI *CBOnPackageStart)(int nTopicID, int nSequenceNo);
///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
typedef int (WINAPI *CBOnPackageEnd)(int nTopicID, int nSequenceNo);
typedef int (WINAPI *CBOnRspError)(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspUserLogin)(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspUserLogout)(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspSubscribeTopic)(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///�����ѯӦ��
typedef int (WINAPI *CBOnRspQryTopic)(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///�������֪ͨ
typedef int (WINAPI *CBOnRtnDepthMarketData)(CUstpFtdcDepthMarketDataField *pDepthMarketData);
typedef int (WINAPI *CBOnRspSubMarketData)(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspUnSubMarketData)(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
