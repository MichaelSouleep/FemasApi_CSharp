// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TRADEAPI_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// extern "C" TRADEAPI_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
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
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
typedef int (WINAPI *CBOnPackageStart)(int nTopicID, int nSequenceNo);
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
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
///数据流回退通知
typedef int (WINAPI *CBOnRtnFlowMessageCancel)(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel);
///成交回报
typedef int (WINAPI *CBOnRtnTrade)(CUstpFtdcTradeField *pTrade);
///报单回报
typedef int (WINAPI *CBOnRtnOrder)(CUstpFtdcOrderField *pOrder);
///报单录入错误回报
typedef int (WINAPI *CBOnErrRtnOrderInsert)(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo);
///报单操作错误回报
typedef int (WINAPI *CBOnErrRtnOrderAction)(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo);
///合约交易状态通知
typedef int (WINAPI *CBOnRtnInstrumentStatus)(CUstpFtdcInstrumentStatusField *pInstrumentStatus);
///账户出入金回报
typedef int (WINAPI *CBOnRtnInvestorAccountDeposit)(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes);
///报价回报
typedef int (WINAPI *CBOnRtnQuote)(CUstpFtdcRtnQuoteField *pRtnQuote);
///报价录入错误回报
typedef int (WINAPI *CBOnErrRtnQuoteInsert)(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo);
///报价撤单错误回报
typedef int (WINAPI *CBOnErrRtnQuoteAction)(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo);
///询价回报
typedef int (WINAPI *CBOnRtnForQuote)(CUstpFtdcReqForQuoteField *pReqForQuote);
///增加组合规则通知
typedef int (WINAPI *CBOnRtnMarginCombinationLeg)(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg);
typedef int (WINAPI *CBOnRtnMarginCombAction)(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction);
typedef int (WINAPI *CBOnRtnUserDeposit)(CUstpFtdcstpUserDepositField *pstpUserDeposit);
///报单查询应答
typedef int (WINAPI *CBOnRspQryOrder)(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///成交单查询应答
typedef int (WINAPI *CBOnRspQryTrade)(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///可用投资者账户查询应答
typedef int (WINAPI *CBOnRspQryUserInvestor)(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///交易编码查询应答
typedef int (WINAPI *CBOnRspQryTradingCode)(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///投资者资金账户查询应答
typedef int (WINAPI *CBOnRspQryInvestorAccount)(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///合约查询应答
typedef int (WINAPI *CBOnRspQryInstrument)(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///交易所查询应答
typedef int (WINAPI *CBOnRspQryExchange)(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///投资者持仓查询应答
typedef int (WINAPI *CBOnRspQryInvestorPosition)(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef int (WINAPI *CBOnRspSubscribeTopic)(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///合规参数查询应答
typedef int (WINAPI *CBOnRspQryComplianceParam)(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///主题查询应答
typedef int (WINAPI *CBOnRspQryTopic)(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///投资者手续费率查询应答
typedef int (WINAPI *CBOnRspQryInvestorFee)(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///投资者保证金率查询应答
typedef int (WINAPI *CBOnRspQryInvestorMargin)(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///交易编码组合持仓查询应答
typedef int (WINAPI *CBOnRspQryInvestorCombPosition)(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///交易编码单腿持仓查询应答
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
	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	CBOnPackageStart cbOnPackageStart = 0;
	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
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
	///数据流回退通知
	CBOnRtnFlowMessageCancel cbOnRtnFlowMessageCancel = 0;
	///成交回报
	CBOnRtnTrade cbOnRtnTrade = 0;
	///报单回报
	CBOnRtnOrder cbOnRtnOrder = 0;
	///报单录入错误回报
	CBOnErrRtnOrderInsert cbOnErrRtnOrderInsert = 0;
	///报单操作错误回报
	CBOnErrRtnOrderAction cbOnErrRtnOrderAction = 0;
	///合约交易状态通知
	CBOnRtnInstrumentStatus cbOnRtnInstrumentStatus = 0;
	///账户出入金回报
	CBOnRtnInvestorAccountDeposit cbOnRtnInvestorAccountDeposit = 0;
	///报价回报
	CBOnRtnQuote cbOnRtnQuote = 0;
	///报价录入错误回报
	CBOnErrRtnQuoteInsert cbOnErrRtnQuoteInsert = 0;
	///报价撤单错误回报
	CBOnErrRtnQuoteAction cbOnErrRtnQuoteAction = 0;
	///询价回报
	CBOnRtnForQuote cbOnRtnForQuote = 0;
	///增加组合规则通知
	CBOnRtnMarginCombinationLeg cbOnRtnMarginCombinationLeg = 0;
	CBOnRtnMarginCombAction cbOnRtnMarginCombAction = 0;
	CBOnRtnUserDeposit cbOnRtnUserDeposit = 0;
	///报单查询应答
	CBOnRspQryOrder cbOnRspQryOrder = 0;
	///成交单查询应答
	CBOnRspQryTrade cbOnRspQryTrade = 0;
	///可用投资者账户查询应答
	CBOnRspQryUserInvestor cbOnRspQryUserInvestor = 0;
	///交易编码查询应答
	CBOnRspQryTradingCode cbOnRspQryTradingCode = 0;
	///投资者资金账户查询应答
	CBOnRspQryInvestorAccount cbOnRspQryInvestorAccount = 0;
	///合约查询应答
	CBOnRspQryInstrument cbOnRspQryInstrument = 0;
	///交易所查询应答
	CBOnRspQryExchange cbOnRspQryExchange = 0;
	///投资者持仓查询应答
	CBOnRspQryInvestorPosition cbOnRspQryInvestorPosition = 0;
	CBOnRspSubscribeTopic cbOnRspSubscribeTopic = 0;
	///合规参数查询应答
	CBOnRspQryComplianceParam cbOnRspQryComplianceParam = 0;
	///主题查询应答
	CBOnRspQryTopic cbOnRspQryTopic = 0;
	///投资者手续费率查询应答
	CBOnRspQryInvestorFee cbOnRspQryInvestorFee = 0;
	///投资者保证金率查询应答
	CBOnRspQryInvestorMargin cbOnRspQryInvestorMargin = 0;
	///交易编码组合持仓查询应答
	CBOnRspQryInvestorCombPosition cbOnRspQryInvestorCombPosition = 0;
	///交易编码单腿持仓查询应答
	CBOnRspQryInvestorLegPosition cbOnRspQryInvestorLegPosition = 0;
	CBOnRspDSUserCertification cbOnRspDSUserCertification = 0;
	CBOnRspDSProxySubmitInfo cbOnRspDSProxySubmitInfo = 0;

#pragma endregion


	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected() ;

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason) ;

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse) ;

	///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageStart(int nTopicID, int nSequenceNo) ;

	///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
	///@param nTopicID 主题代码（如私有流、公共流、行情流等）
	///@param nSequenceNo 报文序号
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo) ;


	///错误应答
	virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///风控前置系统用户登录应答
	virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///用户退出应答
	virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///用户密码修改应答
	virtual void OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单录入应答
	virtual void OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报单操作应答
	virtual void OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报价录入应答
	virtual void OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///报价操作应答
	virtual void OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///询价请求应答
	virtual void OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///客户申请组合应答
	virtual void OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///用户请求出入金应答
	virtual void OnRspUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///用户主次席出入金应答
	virtual void OnRspTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///数据流回退通知
	virtual void OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel) ;

	///成交回报
	virtual void OnRtnTrade(CUstpFtdcTradeField *pTrade) ;

	///报单回报
	virtual void OnRtnOrder(CUstpFtdcOrderField *pOrder) ;

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo) ;

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) ;

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus) ;

	///账户出入金回报
	virtual void OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) ;

	///报价回报
	virtual void OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote) ;

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo) ;

	///报价撤单错误回报
	virtual void OnErrRtnQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo) ;

	///询价回报
	virtual void OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote) ;

	///增加组合规则通知
	virtual void OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg) ;

	///客户申请组合确认
	virtual void OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction) ;

	///用户请求出入金
	virtual void OnRtnUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit) ;

	///报单查询应答
	virtual void OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///成交单查询应答
	virtual void OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///可用投资者账户查询应答
	virtual void OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///交易编码查询应答
	virtual void OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///投资者资金账户查询应答
	virtual void OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///合约查询应答
	virtual void OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///交易所查询应答
	virtual void OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///投资者持仓查询应答
	virtual void OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///合规参数查询应答
	virtual void OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///主题查询应答
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///投资者手续费率查询应答
	virtual void OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///投资者保证金率查询应答
	virtual void OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///交易编码组合持仓查询应答
	virtual void OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///交易编码单腿持仓查询应答
	virtual void OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///穿透监管客户认证应答
	virtual void OnRspDSUserCertification(CUstpFtdcDSUserCertRspDataField *pDSUserCertRspData, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///穿透监管信息采集中继上传信息响应
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