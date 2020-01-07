// MdApi.cpp : ���� DLL Ӧ�ó���ĵ���������
//
#include "stdafx.h"
#include "TradeApi.h"
using namespace std;

///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
void CTraderSpi::OnFrontConnected()
{
	if (cbOnFrontConnected != NULL)
	{
		cbOnFrontConnected();
	}
}

///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
///@param nReason ����ԭ��
///        0x1001 �����ʧ��
///        0x1002 ����дʧ��
///        0x2001 ����������ʱ
///        0x2002 ��������ʧ��
///        0x2003 �յ�������
void CTraderSpi::OnFrontDisconnected(int nReason)
{
	if (cbOnFrontDisconnected != NULL)
	{
		cbOnFrontDisconnected(nReason);
	}
}
///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	if (cbOnHeartBeatWarning != NULL)
	{
		cbOnHeartBeatWarning(nTimeLapse);
	}
}
///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
///@param nTopicID ������루��˽���������������������ȣ�
///@param nSequenceNo �������
void CTraderSpi::OnPackageStart(int nTopicID, int nSequenceNo)
{
	if (cbOnPackageStart != NULL)
	{
		cbOnPackageStart(nTopicID, nSequenceNo);
	}
}
///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
///@param nTopicID ������루��˽���������������������ȣ�
///@param nSequenceNo �������
void CTraderSpi::OnPackageEnd(int nTopicID, int nSequenceNo)
{
	if (cbOnPackageEnd != NULL)
	{
		cbOnPackageEnd(nTopicID, nSequenceNo);
	}
}
///����Ӧ��
void CTraderSpi::OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspError != NULL)
	{
		cbOnRspError(repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///���ǰ��ϵͳ�û���¼Ӧ��
void CTraderSpi::OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspUserLogin != NULL)
	{
		if (pRspUserLogin == NULL)
		{
			CUstpFtdcRspUserLoginField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspUserLoginField));
			cbOnRspUserLogin(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspUserLogin(pRspUserLogin, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�û��˳�Ӧ��
void CTraderSpi::OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspUserLogout != NULL)
	{
		if (pRspUserLogout == NULL)
		{
			CUstpFtdcRspUserLogoutField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspUserLogoutField));
			cbOnRspUserLogout(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspUserLogout(pRspUserLogout, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�û������޸�Ӧ��
void CTraderSpi::OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspUserPasswordUpdate != NULL)
	{
		if (pUserPasswordUpdate == NULL)
		{
			CUstpFtdcUserPasswordUpdateField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcUserPasswordUpdateField));
			cbOnRspUserPasswordUpdate(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspUserPasswordUpdate(pUserPasswordUpdate, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///����¼��Ӧ��
void CTraderSpi::OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspOrderInsert != NULL)
	{
		if (pInputOrder == NULL)
		{
			CUstpFtdcInputOrderField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInputOrderField));
			cbOnRspOrderInsert(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspOrderInsert(pInputOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///��������Ӧ��
void CTraderSpi::OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspOrderAction != NULL)
	{
		if (pOrderAction == NULL)
		{
			CUstpFtdcOrderActionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcOrderActionField));
			cbOnRspOrderAction(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspOrderAction(pOrderAction, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///����¼��Ӧ��
void CTraderSpi::OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQuoteInsert != NULL)
	{
		if (pInputQuote == NULL)
		{
			CUstpFtdcInputQuoteField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInputQuoteField));
			cbOnRspQuoteInsert(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQuoteInsert(pInputQuote, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///���۲���Ӧ��
void CTraderSpi::OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQuoteAction != NULL)
	{
		if (pQuoteAction == NULL)
		{
			CUstpFtdcQuoteActionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcQuoteActionField));
			cbOnRspQuoteAction(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQuoteAction(pQuoteAction, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///ѯ������Ӧ��
void CTraderSpi::OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspForQuote != NULL)
	{
		if (pReqForQuote == NULL)
		{
			CUstpFtdcReqForQuoteField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcReqForQuoteField));
			cbOnRspForQuote(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspForQuote(pReqForQuote, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�ͻ��������Ӧ��
void CTraderSpi::OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspMarginCombAction != NULL)
	{
		if (pInputMarginCombAction == NULL)
		{
			CUstpFtdcInputMarginCombActionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInputMarginCombActionField));
			cbOnRspMarginCombAction(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspMarginCombAction(pInputMarginCombAction, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�û���������Ӧ��
void CTraderSpi::OnRspUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspUserDeposit != NULL)
	{
		if (pstpUserDeposit == NULL)
		{
			CUstpFtdcstpUserDepositField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcstpUserDepositField));
			cbOnRspUserDeposit(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspUserDeposit(pstpUserDeposit, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�û�����ϯ�����Ӧ��
void CTraderSpi::OnRspTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspTransferMoney != NULL)
	{
		if (pstpTransferMoney == NULL)
		{
			CUstpFtdcstpTransferMoneyField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcstpTransferMoneyField));
			cbOnRspTransferMoney(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspTransferMoney(pstpTransferMoney, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///����������֪ͨ
void CTraderSpi::OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel)
{
	if (cbOnRtnFlowMessageCancel != NULL)
	{
		if (pFlowMessageCancel == NULL)
		{
			CUstpFtdcFlowMessageCancelField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcFlowMessageCancelField));
			cbOnRtnFlowMessageCancel(&rsp);
		}
		else
		{
			cbOnRtnFlowMessageCancel(pFlowMessageCancel);
		}
	}
}
///�ɽ��ر�
void CTraderSpi::OnRtnTrade(CUstpFtdcTradeField *pTrade)
{
	if (cbOnRtnTrade != NULL)
	{
		if (pTrade == NULL)
		{
			CUstpFtdcTradeField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcTradeField));
			cbOnRtnTrade(&rsp);
		}
		else
		{
			cbOnRtnTrade(pTrade);
		}
	}
}
///�����ر�
void CTraderSpi::OnRtnOrder(CUstpFtdcOrderField *pOrder)
{
	if (cbOnRtnOrder != NULL)
	{
		if (pOrder == NULL)
		{
			CUstpFtdcOrderField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcOrderField));
			cbOnRtnOrder(&rsp);
		}
		else
		{
			cbOnRtnOrder(pOrder);
		}
	}
}
///����¼�����ر�
void CTraderSpi::OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo)
{
	if (cbOnErrRtnOrderInsert != NULL)
	{
		if (pInputOrder == NULL)
		{
			CUstpFtdcInputOrderField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInputOrderField));
			cbOnErrRtnOrderInsert(&rsp, repareInfo(pRspInfo));
		}
		else
		{
			cbOnErrRtnOrderInsert(pInputOrder, repareInfo(pRspInfo));
		}
	}
}
///������������ر�
void CTraderSpi::OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo)
{
	if (cbOnErrRtnOrderAction != NULL)
	{
		if (pOrderAction == NULL)
		{
			CUstpFtdcOrderActionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcOrderActionField));
			cbOnErrRtnOrderAction(&rsp, repareInfo(pRspInfo));
		}
		else
		{
			cbOnErrRtnOrderAction(pOrderAction, repareInfo(pRspInfo));
		}
	}
}
///��Լ����״̬֪ͨ
void CTraderSpi::OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus)
{
	if (cbOnRtnInstrumentStatus != NULL)
	{
		if (pInstrumentStatus == NULL)
		{
			CUstpFtdcInstrumentStatusField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInstrumentStatusField));
			cbOnRtnInstrumentStatus(&rsp);
		}
		else
		{
			cbOnRtnInstrumentStatus(pInstrumentStatus);
		}
	}
}
///�˻������ر�
void CTraderSpi::OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes)
{
	if (cbOnRtnInvestorAccountDeposit != NULL)
	{
		if (pInvestorAccountDepositRes == NULL)
		{
			CUstpFtdcInvestorAccountDepositResField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInvestorAccountDepositResField));
			cbOnRtnInvestorAccountDeposit(&rsp);
		}
		else
		{
			cbOnRtnInvestorAccountDeposit(pInvestorAccountDepositRes);
		}
	}
}
///���ۻر�
void CTraderSpi::OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote)
{
	if (cbOnRtnQuote != NULL)
	{
		if (pRtnQuote == NULL)
		{
			CUstpFtdcRtnQuoteField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRtnQuoteField));
			cbOnRtnQuote(&rsp);
		}
		else
		{
			cbOnRtnQuote(pRtnQuote);
		}
	}
}
///����¼�����ر�
void CTraderSpi::OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo)
{
	if (cbOnErrRtnQuoteInsert != NULL)
	{
		if (pInputQuote == NULL)
		{
			CUstpFtdcInputQuoteField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInputQuoteField));
			cbOnErrRtnQuoteInsert(&rsp, repareInfo(pRspInfo));
		}
		else
		{
			cbOnErrRtnQuoteInsert(pInputQuote, repareInfo(pRspInfo));
		}
	}
}
///���۳�������ر�
void CTraderSpi::OnErrRtnQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo)
{
	if (cbOnErrRtnQuoteAction != NULL)
	{
		if (pQuoteAction == NULL)
		{
			CUstpFtdcQuoteActionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcQuoteActionField));
			cbOnErrRtnQuoteAction(&rsp, repareInfo(pRspInfo));
		}
		else
		{
			cbOnErrRtnQuoteAction(pQuoteAction, repareInfo(pRspInfo));
		}
	}
}
///ѯ�ۻر�
void CTraderSpi::OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote)
{
	if (cbOnRtnForQuote != NULL)
	{
		if (pReqForQuote == NULL)
		{
			CUstpFtdcReqForQuoteField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcReqForQuoteField));
			cbOnRtnForQuote(&rsp);
		}
		else
		{
			cbOnRtnForQuote(pReqForQuote);
		}
	}
}
///������Ϲ���֪ͨ
void CTraderSpi::OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg)
{
	if (cbOnRtnMarginCombinationLeg != NULL)
	{
		if (pMarginCombinationLeg == NULL)
		{
			CUstpFtdcMarginCombinationLegField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcMarginCombinationLegField));
			cbOnRtnMarginCombinationLeg(&rsp);
		}
		else
		{
			cbOnRtnMarginCombinationLeg(pMarginCombinationLeg);
		}
	}
}
///�ͻ��������ȷ��
void CTraderSpi::OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction)
{
	if (cbOnRtnMarginCombAction != NULL)
	{
		if (pInputMarginCombAction == NULL)
		{
			CUstpFtdcInputMarginCombActionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInputMarginCombActionField));
			cbOnRtnMarginCombAction(&rsp);
		}
		else
		{
			cbOnRtnMarginCombAction(pInputMarginCombAction);
		}
	}
}
///�û���������
void CTraderSpi::OnRtnUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit)
{
	if (cbOnRtnUserDeposit != NULL)
	{
		if (pstpUserDeposit == NULL)
		{
			CUstpFtdcstpUserDepositField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcstpUserDepositField));
			cbOnRtnUserDeposit(&rsp);
		}
		else
		{
			cbOnRtnUserDeposit(pstpUserDeposit);
		}
	}
}
///������ѯӦ��
void CTraderSpi::OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryOrder != NULL)
	{
		if (pOrder == NULL)
		{
			CUstpFtdcOrderField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcOrderField));
			cbOnRspQryOrder(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryOrder(pOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�ɽ�����ѯӦ��
void CTraderSpi::OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryTrade != NULL)
	{
		if (pTrade == NULL)
		{
			CUstpFtdcTradeField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcTradeField));
			cbOnRspQryTrade(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryTrade(pTrade, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///����Ͷ�����˻���ѯӦ��
void CTraderSpi::OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryUserInvestor != NULL)
	{
		if (pRspUserInvestor == NULL)
		{
			CUstpFtdcRspUserInvestorField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspUserInvestorField));
			cbOnRspQryUserInvestor(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryUserInvestor(pRspUserInvestor, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///���ױ����ѯӦ��
void CTraderSpi::OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryTradingCode != NULL)
	{
		if (pRspTradingCode == NULL)
		{
			CUstpFtdcRspTradingCodeField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspTradingCodeField));
			cbOnRspQryTradingCode(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryTradingCode(pRspTradingCode, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///Ͷ�����ʽ��˻���ѯӦ��
void CTraderSpi::OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInvestorAccount != NULL)
	{
		if (pRspInvestorAccount == NULL)
		{
			CUstpFtdcRspInvestorAccountField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspInvestorAccountField));
			cbOnRspQryInvestorAccount(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInvestorAccount(pRspInvestorAccount, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///��Լ��ѯӦ��
void CTraderSpi::OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInstrument != NULL)
	{
		if (pRspInstrument == NULL)
		{
			CUstpFtdcRspInstrumentField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspInstrumentField));
			cbOnRspQryInstrument(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInstrument(pRspInstrument, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///��������ѯӦ��
void CTraderSpi::OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryExchange != NULL)
	{
		if (pRspExchange == NULL)
		{
			CUstpFtdcRspExchangeField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspExchangeField));
			cbOnRspQryExchange(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryExchange(pRspExchange, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///Ͷ���ֲֲ߳�ѯӦ��
void CTraderSpi::OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInvestorPosition != NULL)
	{
		if (pRspInvestorPosition == NULL)
		{
			CUstpFtdcRspInvestorPositionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspInvestorPositionField));
			cbOnRspQryInvestorPosition(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInvestorPosition(pRspInvestorPosition, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///��������Ӧ��
void CTraderSpi::OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspSubscribeTopic != NULL)
	{
		if (pDissemination == NULL)
		{
			CUstpFtdcDisseminationField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcDisseminationField));
			cbOnRspSubscribeTopic(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspSubscribeTopic(pDissemination, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�Ϲ������ѯӦ��
void CTraderSpi::OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryComplianceParam != NULL)
	{
		if (pRspComplianceParam == NULL)
		{
			CUstpFtdcRspComplianceParamField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspComplianceParamField));
			cbOnRspQryComplianceParam(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryComplianceParam(pRspComplianceParam, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///�����ѯӦ��
void CTraderSpi::OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryTopic != NULL)
	{
		if (pDissemination == NULL)
		{
			CUstpFtdcDisseminationField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcDisseminationField));
			cbOnRspQryTopic(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryTopic(pDissemination, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///Ͷ�����������ʲ�ѯӦ��
void CTraderSpi::OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInvestorFee != NULL)
	{
		if (pInvestorFee == NULL)
		{
			CUstpFtdcInvestorFeeField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInvestorFeeField));
			cbOnRspQryInvestorFee(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInvestorFee(pInvestorFee, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///Ͷ���߱�֤���ʲ�ѯӦ��
void CTraderSpi::OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInvestorMargin != NULL)
	{
		if (pInvestorMargin == NULL)
		{
			CUstpFtdcInvestorMarginField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcInvestorMarginField));
			cbOnRspQryInvestorMargin(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInvestorMargin(pInvestorMargin, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///���ױ�����ϳֲֲ�ѯӦ��
void CTraderSpi::OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInvestorCombPosition != NULL)
	{
		if (pRspInvestorCombPosition == NULL)
		{
			CUstpFtdcRspInvestorCombPositionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspInvestorCombPositionField));
			cbOnRspQryInvestorCombPosition(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInvestorCombPosition(pRspInvestorCombPosition, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///���ױ��뵥�ȳֲֲ�ѯӦ��
void CTraderSpi::OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspQryInvestorLegPosition != NULL)
	{
		if (pRspInvestorLegPosition == NULL)
		{
			CUstpFtdcRspInvestorLegPositionField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcRspInvestorLegPositionField));
			cbOnRspQryInvestorLegPosition(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspQryInvestorLegPosition(pRspInvestorLegPosition, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///��͸��ܿͻ���֤Ӧ��
void CTraderSpi::OnRspDSUserCertification(CUstpFtdcDSUserCertRspDataField *pDSUserCertRspData, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspDSUserCertification != NULL)
	{
		if (pDSUserCertRspData == NULL)
		{
			CUstpFtdcDSUserCertRspDataField rsp;
			memset(&rsp, 0, sizeof(CUstpFtdcDSUserCertRspDataField));
			cbOnRspDSUserCertification(&rsp, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
		{
			cbOnRspDSUserCertification(pDSUserCertRspData, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
}
///��͸�����Ϣ�ɼ��м��ϴ���Ϣ��Ӧ
void CTraderSpi::OnRspDSProxySubmitInfo(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspDSProxySubmitInfo != NULL)
	{
		cbOnRspDSProxySubmitInfo(repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}



//����յ��շ����Ĵ���
CUstpFtdcRspInfoField rif;
CUstpFtdcRspInfoField* CTraderSpi::repareInfo(CUstpFtdcRspInfoField *pRspInfo)
{
	if (pRspInfo == NULL)
	{
		memset(&rif, 0, sizeof(rif));
		return &rif;
	}
	else
		return pRspInfo;
}