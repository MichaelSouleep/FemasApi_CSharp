// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TRADEAPI_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// extern "C" TRADEAPI_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef TRADEAPI_EXPORTS
#define TRADEAPI_API __declspec(dllexport)
#else
#define TRADEAPI_API __declspec(dllimport)
#endif

#pragma once
#include "USTPFtdcTraderApi.h"

#pragma region declare spi callback type
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
typedef int (WINAPI *CBOnRspUserPasswordUpdate)(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspOrderInsert)(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspOrderAction)(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspQuoteInsert)(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspQuoteAction)(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspForQuote)(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspMarginCombAction)(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspUserDeposit)(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspTransferMoney)(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///����������֪ͨ
typedef int (WINAPI *CBOnRtnFlowMessageCancel)(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel);
///�ɽ��ر�
typedef int (WINAPI *CBOnRtnTrade)(CUstpFtdcTradeField *pTrade);
///�����ر�
typedef int (WINAPI *CBOnRtnOrder)(CUstpFtdcOrderField *pOrder);
///����¼�����ر�
typedef int (WINAPI *CBOnErrRtnOrderInsert)(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo);
///������������ر�
typedef int (WINAPI *CBOnErrRtnOrderAction)(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo);
///��Լ����״̬֪ͨ
typedef int (WINAPI *CBOnRtnInstrumentStatus)(CUstpFtdcInstrumentStatusField *pInstrumentStatus);
///�˻������ر�
typedef int (WINAPI *CBOnRtnInvestorAccountDeposit)(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes);
///���ۻر�
typedef int (WINAPI *CBOnRtnQuote)(CUstpFtdcRtnQuoteField *pRtnQuote);
///����¼�����ر�
typedef int (WINAPI *CBOnErrRtnQuoteInsert)(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo);
///���۳�������ر�
typedef int (WINAPI *CBOnErrRtnQuoteAction)(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo);
///ѯ�ۻر�
typedef int (WINAPI *CBOnRtnForQuote)(CUstpFtdcReqForQuoteField *pReqForQuote);
///������Ϲ���֪ͨ
typedef int (WINAPI *CBOnRtnMarginCombinationLeg)(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg);
typedef int (WINAPI *CBOnRtnMarginCombAction)(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction);
typedef int (WINAPI *CBOnRtnUserDeposit)(CUstpFtdcstpUserDepositField *pstpUserDeposit);
///������ѯӦ��
typedef int (WINAPI *CBOnRspQryOrder)(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///�ɽ�����ѯӦ��
typedef int (WINAPI *CBOnRspQryTrade)(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///����Ͷ�����˻���ѯӦ��
typedef int (WINAPI *CBOnRspQryUserInvestor)(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///���ױ����ѯӦ��
typedef int (WINAPI *CBOnRspQryTradingCode)(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///Ͷ�����ʽ��˻���ѯӦ��
typedef int (WINAPI *CBOnRspQryInvestorAccount)(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///��Լ��ѯӦ��
typedef int (WINAPI *CBOnRspQryInstrument)(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///��������ѯӦ��
typedef int (WINAPI *CBOnRspQryExchange)(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///Ͷ���ֲֲ߳�ѯӦ��
typedef int (WINAPI *CBOnRspQryInvestorPosition)(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspSubscribeTopic)(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///�Ϲ������ѯӦ��
typedef int (WINAPI *CBOnRspQryComplianceParam)(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///�����ѯӦ��
typedef int (WINAPI *CBOnRspQryTopic)(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///Ͷ�����������ʲ�ѯӦ��
typedef int (WINAPI *CBOnRspQryInvestorFee)(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///Ͷ���߱�֤���ʲ�ѯӦ��
typedef int (WINAPI *CBOnRspQryInvestorMargin)(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///���ױ�����ϳֲֲ�ѯӦ��
typedef int (WINAPI *CBOnRspQryInvestorCombPosition)(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///���ױ��뵥�ȳֲֲ�ѯӦ��
typedef int (WINAPI *CBOnRspQryInvestorLegPosition)(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspDSUserCertification)(CUstpFtdcDSUserCertRspDataField *pDSUserCertRspData, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspDSProxySubmitInfo)(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

#pragma endregion


class CTraderSpi :public CUstpFtdcTraderSpi
{
public :
#pragma region Callback virtual address
	CBOnFrontConnected cbOnFrontConnected = 0;
	CBOnFrontDisconnected cbOnFrontDisconnected = 0;
	CBOnHeartBeatWarning cbOnHeartBeatWarning = 0;
	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	CBOnPackageStart cbOnPackageStart = 0;
	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	CBOnPackageEnd cbOnPackageEnd = 0;
	CBOnRspError cbOnRspError = 0;
	CBOnRspUserLogin cbOnRspUserLogin = 0;
	CBOnRspUserLogout cbOnRspUserLogout = 0;
	CBOnRspUserPasswordUpdate cbOnRspUserPasswordUpdate = 0;
	CBOnRspOrderInsert cbOnRspOrderInsert = 0;
	CBOnRspOrderAction cbOnRspOrderAction = 0;
	CBOnRspQuoteInsert cbOnRspQuoteInsert = 0;
	CBOnRspQuoteAction cbOnRspQuoteAction = 0;
	CBOnRspForQuote cbOnRspForQuote = 0;
	CBOnRspMarginCombAction cbOnRspMarginCombAction = 0;
	CBOnRspUserDeposit cbOnRspUserDeposit = 0;
	CBOnRspTransferMoney cbOnRspTransferMoney = 0;
	///����������֪ͨ
	CBOnRtnFlowMessageCancel cbOnRtnFlowMessageCancel = 0;
	///�ɽ��ر�
	CBOnRtnTrade cbOnRtnTrade = 0;
	///�����ر�
	CBOnRtnOrder cbOnRtnOrder = 0;
	///����¼�����ر�
	CBOnErrRtnOrderInsert cbOnErrRtnOrderInsert = 0;
	///������������ر�
	CBOnErrRtnOrderAction cbOnErrRtnOrderAction = 0;
	///��Լ����״̬֪ͨ
	CBOnRtnInstrumentStatus cbOnRtnInstrumentStatus = 0;
	///�˻������ر�
	CBOnRtnInvestorAccountDeposit cbOnRtnInvestorAccountDeposit = 0;
	///���ۻر�
	CBOnRtnQuote cbOnRtnQuote = 0;
	///����¼�����ر�
	CBOnErrRtnQuoteInsert cbOnErrRtnQuoteInsert = 0;
	///���۳�������ر�
	CBOnErrRtnQuoteAction cbOnErrRtnQuoteAction = 0;
	///ѯ�ۻر�
	CBOnRtnForQuote cbOnRtnForQuote = 0;
	///������Ϲ���֪ͨ
	CBOnRtnMarginCombinationLeg cbOnRtnMarginCombinationLeg = 0;
	CBOnRtnMarginCombAction cbOnRtnMarginCombAction = 0;
	CBOnRtnUserDeposit cbOnRtnUserDeposit = 0;
	///������ѯӦ��
	CBOnRspQryOrder cbOnRspQryOrder = 0;
	///�ɽ�����ѯӦ��
	CBOnRspQryTrade cbOnRspQryTrade = 0;
	///����Ͷ�����˻���ѯӦ��
	CBOnRspQryUserInvestor cbOnRspQryUserInvestor = 0;
	///���ױ����ѯӦ��
	CBOnRspQryTradingCode cbOnRspQryTradingCode = 0;
	///Ͷ�����ʽ��˻���ѯӦ��
	CBOnRspQryInvestorAccount cbOnRspQryInvestorAccount = 0;
	///��Լ��ѯӦ��
	CBOnRspQryInstrument cbOnRspQryInstrument = 0;
	///��������ѯӦ��
	CBOnRspQryExchange cbOnRspQryExchange = 0;
	///Ͷ���ֲֲ߳�ѯӦ��
	CBOnRspQryInvestorPosition cbOnRspQryInvestorPosition = 0;
	CBOnRspSubscribeTopic cbOnRspSubscribeTopic = 0;
	///�Ϲ������ѯӦ��
	CBOnRspQryComplianceParam cbOnRspQryComplianceParam = 0;
	///�����ѯӦ��
	CBOnRspQryTopic cbOnRspQryTopic = 0;
	///Ͷ�����������ʲ�ѯӦ��
	CBOnRspQryInvestorFee cbOnRspQryInvestorFee = 0;
	///Ͷ���߱�֤���ʲ�ѯӦ��
	CBOnRspQryInvestorMargin cbOnRspQryInvestorMargin = 0;
	///���ױ�����ϳֲֲ�ѯӦ��
	CBOnRspQryInvestorCombPosition cbOnRspQryInvestorCombPosition = 0;
	///���ױ��뵥�ȳֲֲ�ѯӦ��
	CBOnRspQryInvestorLegPosition cbOnRspQryInvestorLegPosition = 0;
	CBOnRspDSUserCertification cbOnRspDSUserCertification = 0;
	CBOnRspDSProxySubmitInfo cbOnRspDSProxySubmitInfo = 0;

#pragma endregion


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

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������Ӧ��
	virtual void OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����¼��Ӧ��
	virtual void OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///���۲���Ӧ��
	virtual void OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ѯ������Ӧ��
	virtual void OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ͻ��������Ӧ��
	virtual void OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�û���������Ӧ��
	virtual void OnRspUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�û�����ϯ�����Ӧ��
	virtual void OnRspTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel) ;

	///�ɽ��ر�
	virtual void OnRtnTrade(CUstpFtdcTradeField *pTrade) ;

	///�����ر�
	virtual void OnRtnOrder(CUstpFtdcOrderField *pOrder) ;

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo) ;

	///������������ر�
	virtual void OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) ;

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus) ;

	///�˻������ر�
	virtual void OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) ;

	///���ۻر�
	virtual void OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote) ;

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo) ;

	///���۳�������ر�
	virtual void OnErrRtnQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo) ;

	///ѯ�ۻر�
	virtual void OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote) ;

	///������Ϲ���֪ͨ
	virtual void OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg) ;

	///�ͻ��������ȷ��
	virtual void OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction) ;

	///�û���������
	virtual void OnRtnUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit) ;

	///������ѯӦ��
	virtual void OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����Ͷ�����˻���ѯӦ��
	virtual void OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///���ױ����ѯӦ��
	virtual void OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ�����ʽ��˻���ѯӦ��
	virtual void OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������ѯӦ��
	virtual void OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ���ֲֲ߳�ѯӦ��
	virtual void OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�Ϲ������ѯӦ��
	virtual void OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯӦ��
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ�����������ʲ�ѯӦ��
	virtual void OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ���߱�֤���ʲ�ѯӦ��
	virtual void OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///���ױ�����ϳֲֲ�ѯӦ��
	virtual void OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///���ױ��뵥�ȳֲֲ�ѯӦ��
	virtual void OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��͸��ܿͻ���֤Ӧ��
	virtual void OnRspDSUserCertification(CUstpFtdcDSUserCertRspDataField *pDSUserCertRspData, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��͸�����Ϣ�ɼ��м��ϴ���Ϣ��Ӧ
	virtual void OnRspDSProxySubmitInfo(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	private:
		CUstpFtdcRspInfoField* repareInfo(CUstpFtdcRspInfoField *pRspInfo);

};


class CTradeApi
{
public:
	CTradeApi(const char * pszFlowPath = "");
	~CTradeApi();

public:
	CUstpFtdcTraderApi * pUserApi;
	CTraderSpi * pUserSpi;
};