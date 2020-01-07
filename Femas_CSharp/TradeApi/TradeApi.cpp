// MdApi.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include "TradeApi.h"
using namespace std;

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void CTraderSpi::OnFrontConnected()
{
	if (cbOnFrontConnected != NULL)
	{
		cbOnFrontConnected();
	}
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void CTraderSpi::OnFrontDisconnected(int nReason)
{
	if (cbOnFrontDisconnected != NULL)
	{
		cbOnFrontDisconnected(nReason);
	}
}
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	if (cbOnHeartBeatWarning != NULL)
	{
		cbOnHeartBeatWarning(nTimeLapse);
	}
}
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
void CTraderSpi::OnPackageStart(int nTopicID, int nSequenceNo)
{
	if (cbOnPackageStart != NULL)
	{
		cbOnPackageStart(nTopicID, nSequenceNo);
	}
}
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
void CTraderSpi::OnPackageEnd(int nTopicID, int nSequenceNo)
{
	if (cbOnPackageEnd != NULL)
	{
		cbOnPackageEnd(nTopicID, nSequenceNo);
	}
}
///错误应答
void CTraderSpi::OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspError != NULL)
	{
		cbOnRspError(repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}
///风控前置系统用户登录应答
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
///用户退出应答
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
///用户密码修改应答
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
///报单录入应答
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
///报单操作应答
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
///报价录入应答
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
///报价操作应答
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
///询价请求应答
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
///客户申请组合应答
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
///用户请求出入金应答
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
///用户主次席出入金应答
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
///数据流回退通知
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
///成交回报
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
///报单回报
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
///报单录入错误回报
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
///报单操作错误回报
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
///合约交易状态通知
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
///账户出入金回报
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
///报价回报
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
///报价录入错误回报
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
///报价撤单错误回报
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
///询价回报
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
///增加组合规则通知
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
///客户申请组合确认
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
///用户请求出入金
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
///报单查询应答
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
///成交单查询应答
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
///可用投资者账户查询应答
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
///交易编码查询应答
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
///投资者资金账户查询应答
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
///合约查询应答
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
///交易所查询应答
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
///投资者持仓查询应答
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
///订阅主题应答
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
///合规参数查询应答
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
///主题查询应答
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
///投资者手续费率查询应答
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
///投资者保证金率查询应答
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
///交易编码组合持仓查询应答
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
///交易编码单腿持仓查询应答
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
///穿透监管客户认证应答
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
///穿透监管信息采集中继上传信息响应
void CTraderSpi::OnRspDSProxySubmitInfo(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspDSProxySubmitInfo != NULL)
	{
		cbOnRspDSProxySubmitInfo(repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}



//针对收到空反馈的处理
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