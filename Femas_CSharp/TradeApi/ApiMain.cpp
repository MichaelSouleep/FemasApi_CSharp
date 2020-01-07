// TradeApi.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "TradeApi.h"
#include <stdio.h>
#include "USTPFtdcTraderApi.h"


CTradeApi::CTradeApi(const char *pszFlowPath) :pUserApi(nullptr), pUserSpi(nullptr)
{
	pUserApi = CUstpFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
	pUserSpi = new CTraderSpi;
	pUserApi->RegisterSpi(pUserSpi);
}

CTradeApi::~CTradeApi()
{
	if (pUserApi)
	{
		pUserApi->Release();
	}
	if (pUserSpi)
	{
		delete pUserSpi;
		pUserSpi = nullptr;
	}
}

///创建TraderApi
///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
///@return 创建出的UserApi
extern "C" TRADEAPI_API CTradeApi* CreateApi(const char *pszFlowPath = "")
{
	return new CTradeApi(pszFlowPath);
	//return CTradeApi::CreateFtdcTraderApi(pszFlowPath);			// 创建UserApi
}

///获取系统版本号
///@param nMajorVersion 主版本号
///@param nMinorVersion 子版本号
///@return 系统标识字符串
extern "C" TRADEAPI_API char*  GetApiVersion()
{
	int majorVer(0), minorVer(0);
	const char * sysID = CUstpFtdcTraderApi::GetVersion(majorVer, minorVer);
	char ver[100];
	memset(ver, 0, 100);
	sprintf(ver, "%s%d.%d", sysID, majorVer, minorVer);
	ver[sizeof(ver)] = 0;
	return ver;
}


//static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);

///删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
extern "C" TRADEAPI_API void Release(CTradeApi* pUserApi)
{
	return pUserApi->pUserApi->Release();
}

///初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
extern "C" TRADEAPI_API void Init(CTradeApi* pUserApi)
{
	return pUserApi->pUserApi->Init();
}

///等待接口线程结束运行
///@return 线程退出代码
extern "C" TRADEAPI_API int Join(CTradeApi* pUserApi)
{
	return pUserApi->pUserApi->Join();
}

///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
extern "C" TRADEAPI_API const char *GetTradingDay(CTradeApi* pUserApi)
{
	return pUserApi->pUserApi->GetTradingDay();
}

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
extern "C" TRADEAPI_API void RegisterFront(CTradeApi* pUserApi, char *pszFrontAddress)
{
	pUserApi->pUserApi->RegisterFront(pszFrontAddress);
}

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterFront优先于RegisterNameServer
extern "C" TRADEAPI_API void RegisterNameServer(CTradeApi* pUserApi, char *pszNsAddress)
{
	pUserApi->pUserApi->RegisterNameServer(pszNsAddress);
}

///注册回调接口
///@param pSpi 派生自回调接口类的实例
extern "C" TRADEAPI_API void RegisterSpi(CTradeApi* pUserApi, CUstpFtdcTraderSpi *pSpi)
{
	pUserApi->pUserApi->RegisterSpi(pSpi);
}

///加载证书
///@param pszCertFileName 用户证书文件名
///@param pszKeyFileName 用户私钥文件名
///@param pszCaFileName 可信任CA证书文件名
///@param pszKeyFilePassword 用户私钥文件密码
///@return 0 操作成功
///@return -1 可信任CA证书载入失败
///@return -2 用户证书载入失败
///@return -3 用户私钥载入失败	
///@return -4 用户证书校验失败
extern "C" TRADEAPI_API int RegisterCertificateFile(CTradeApi* pUserApi, const char *pszCertFileName, const char *pszKeyFileName,
	const char *pszCaFileName, const char *pszKeyFilePassword)
{
	return pUserApi->pUserApi->RegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
}

///订阅私有流。
///@param nResumeType 私有流重传方式  
///        USTP_TERT_RESTART:从本交易日开始重传
///        USTP_TERT_RESUME:从上次收到的续传
///        USTP_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
extern "C" TRADEAPI_API void SubscribePrivateTopic(CTradeApi* pUserApi, USTP_TE_RESUME_TYPE nResumeType)
{
	pUserApi->pUserApi->SubscribePrivateTopic(nResumeType);
}

///订阅公共流。
///@param nResumeType 公共流重传方式  
///        USTP_TERT_RESTART:从本交易日开始重传
///        USTP_TERT_RESUME:从上次收到的续传
///        USTP_TERT_QUICK:只传送登录后公共流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
extern "C" TRADEAPI_API void SubscribePublicTopic(CTradeApi* pUserApi, USTP_TE_RESUME_TYPE nResumeType)
{
	pUserApi->pUserApi->SubscribePublicTopic(nResumeType);
}

///订阅交易员流。
///@param nResumeType 交易员流重传方式  
///        USTP_TERT_RESTART:从本交易日开始重传
///        USTP_TERT_RESUME:从上次收到的续传
///        USTP_TERT_QUICK:只传送登录后交易员流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
extern "C" TRADEAPI_API void SubscribeUserTopic(CTradeApi* pUserApi, USTP_TE_RESUME_TYPE nResumeType)
{
	pUserApi->pUserApi->SubscribeUserTopic(nResumeType);
}

///订阅询价流。
///@param nResumeType 交易员流重传方式  
///        USTP_TERT_RESTART:从本交易日开始重传
///        USTP_TERT_RESUME:从上次收到的续传
///        USTP_TERT_QUICK:只传送登录后交易员流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
extern "C" TRADEAPI_API void SubscribeForQuote(CTradeApi* pUserApi, USTP_TE_RESUME_TYPE nResumeType)
{
	pUserApi->pUserApi->SubscribeForQuote(nResumeType);
}

///设置心跳超时时间。
///@param timeout 心跳超时时间(秒)  
extern "C" TRADEAPI_API void SetHeartbeatTimeout(CTradeApi* pUserApi, unsigned int timeout)
{
	pUserApi->pUserApi->SetHeartbeatTimeout(timeout);
}

///打开请求日志文件
///@param pszReqLogFileName 请求日志文件名  
///@return 0 操作成功
///@return -1 打开日志文件失败
extern "C" TRADEAPI_API int OpenRequestLog(CTradeApi* pUserApi, const char *pszReqLogFileName)
{
	return pUserApi->pUserApi->OpenRequestLog(pszReqLogFileName);
}

///打开应答日志文件
///@param pszRspLogFileName 应答日志文件名  
///@return 0 操作成功
///@return -1 打开日志文件失败
extern "C" TRADEAPI_API int OpenResponseLog(CTradeApi* pUserApi, const char *pszRspLogFileName)
{
	return pUserApi->pUserApi->OpenResponseLog(pszRspLogFileName);
}

///穿透监管中继处用户证书认证 
extern "C" TRADEAPI_API int RegisterDSProxyUserCert(CTradeApi* pUserApi, CUstpFtdcDSProxyCheckUserInfoField *pDSProxyUserUserInfo, CUstpFtdcDSProxyUserCertInField *pDSProxyUserCertIn, CUstpFtdcDSProxyUserCertOutField *pDProxyUserCertOut, int nRequestID)
{
	return pUserApi->pUserApi->RegisterDSProxyUserCert(pDSProxyUserUserInfo, pDSProxyUserCertIn, pDProxyUserCertOut, nRequestID);
}



///风控前置系统用户登录请求
extern "C" TRADEAPI_API int ReqUserLogin(CTradeApi* pUserApi, CUstpFtdcReqUserLoginField *pReqUserLogin, int nRequestID)
{
	return pUserApi->pUserApi->ReqUserLogin(pReqUserLogin, nRequestID);
}

///用户退出请求
extern "C" TRADEAPI_API int ReqUserLogout(CTradeApi* pUserApi, CUstpFtdcReqUserLogoutField *pReqUserLogout, int nRequestID)
{
	return pUserApi->pUserApi->ReqUserLogout(pReqUserLogout, nRequestID);
}

///用户密码修改请求
extern "C" TRADEAPI_API int ReqUserPasswordUpdate(CTradeApi* pUserApi, CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	return pUserApi->pUserApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

///报单录入请求
extern "C" TRADEAPI_API int ReqOrderInsert(CTradeApi* pUserApi, CUstpFtdcInputOrderField *pInputOrder, int nRequestID)
{
	return pUserApi->pUserApi->ReqOrderInsert(pInputOrder, nRequestID);
}

///报单操作请求
extern "C" TRADEAPI_API int ReqOrderAction(CTradeApi* pUserApi, CUstpFtdcOrderActionField *pOrderAction, int nRequestID)
{
	return pUserApi->pUserApi->ReqOrderAction(pOrderAction, nRequestID);
}

///请求报价录入
extern "C" TRADEAPI_API int ReqQuoteInsert(CTradeApi* pUserApi, CUstpFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	return pUserApi->pUserApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

///报价操作请求
extern "C" TRADEAPI_API int ReqQuoteAction(CTradeApi* pUserApi, CUstpFtdcQuoteActionField *pQuoteAction, int nRequestID)
{
	return pUserApi->pUserApi->ReqQuoteAction(pQuoteAction, nRequestID);
}

///客户询价请求
extern "C" TRADEAPI_API int ReqForQuote(CTradeApi* pUserApi, CUstpFtdcReqForQuoteField *pReqForQuote, int nRequestID)
{
	return pUserApi->pUserApi->ReqForQuote(pReqForQuote, nRequestID);
}

///客户申请组合请求
extern "C" TRADEAPI_API int ReqMarginCombAction(CTradeApi* pUserApi, CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, int nRequestID)
{
	return pUserApi->pUserApi->ReqMarginCombAction(pInputMarginCombAction, nRequestID);
}

///用户请求出入金
extern "C" TRADEAPI_API int ReqUserDeposit(CTradeApi* pUserApi, CUstpFtdcstpUserDepositField *pstpUserDeposit, int nRequestID)
{
	return pUserApi->pUserApi->ReqUserDeposit(pstpUserDeposit, nRequestID);
}

///用户主次席出入金
extern "C" TRADEAPI_API int ReqTransferMoney(CTradeApi* pUserApi, CUstpFtdcstpTransferMoneyField *pstpTransferMoney, int nRequestID)
{
	return pUserApi->pUserApi->ReqTransferMoney(pstpTransferMoney, nRequestID);
}

///报单查询请求
extern "C" TRADEAPI_API int ReqQryOrder(CTradeApi* pUserApi, CUstpFtdcQryOrderField *pQryOrder, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryOrder(pQryOrder, nRequestID);
}

///成交单查询请求
extern "C" TRADEAPI_API int ReqQryTrade(CTradeApi* pUserApi, CUstpFtdcQryTradeField *pQryTrade, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryTrade(pQryTrade, nRequestID);
}

///可用投资者账户查询请求
extern "C" TRADEAPI_API int ReqQryUserInvestor(CTradeApi* pUserApi, CUstpFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryUserInvestor(pQryUserInvestor, nRequestID);
}

///交易编码查询请求
extern "C" TRADEAPI_API int ReqQryTradingCode(CTradeApi* pUserApi, CUstpFtdcQryTradingCodeField *pQryTradingCode, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

///投资者资金账户查询请求
extern "C" TRADEAPI_API int ReqQryInvestorAccount(CTradeApi* pUserApi, CUstpFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInvestorAccount(pQryInvestorAccount, nRequestID);
}

///合约查询请求
extern "C" TRADEAPI_API int ReqQryInstrument(CTradeApi* pUserApi, CUstpFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

///交易所查询请求
extern "C" TRADEAPI_API int ReqQryExchange(CTradeApi* pUserApi, CUstpFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryExchange(pQryExchange, nRequestID);
}

///投资者持仓查询请求
extern "C" TRADEAPI_API int ReqQryInvestorPosition(CTradeApi* pUserApi, CUstpFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

///订阅主题请求
extern "C" TRADEAPI_API int ReqSubscribeTopic(CTradeApi* pUserApi, CUstpFtdcDisseminationField *pDissemination, int nRequestID)
{
	return pUserApi->pUserApi->ReqSubscribeTopic(pDissemination, nRequestID);
}

///合规参数查询请求
extern "C" TRADEAPI_API int ReqQryComplianceParam(CTradeApi* pUserApi, CUstpFtdcQryComplianceParamField *pQryComplianceParam, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryComplianceParam(pQryComplianceParam, nRequestID);
}

///主题查询请求
extern "C" TRADEAPI_API int ReqQryTopic(CTradeApi* pUserApi, CUstpFtdcDisseminationField *pDissemination, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryTopic(pDissemination, nRequestID);
}

///投资者手续费率查询请求
extern "C" TRADEAPI_API int ReqQryInvestorFee(CTradeApi* pUserApi, CUstpFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInvestorFee(pQryInvestorFee, nRequestID);
}

///投资者保证金率查询请求
extern "C" TRADEAPI_API int ReqQryInvestorMargin(CTradeApi* pUserApi, CUstpFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInvestorMargin(pQryInvestorMargin, nRequestID);
}

///交易编码组合持仓查询请求
extern "C" TRADEAPI_API int ReqQryInvestorCombPosition(CTradeApi* pUserApi, CUstpFtdcQryInvestorCombPositionField *pQryInvestorCombPosition, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInvestorCombPosition(pQryInvestorCombPosition, nRequestID);
}

///交易编码单腿持仓查询请求
extern "C" TRADEAPI_API int ReqQryInvestorLegPosition(CTradeApi* pUserApi, CUstpFtdcQryInvestorLegPositionField *pQryInvestorLegPosition, int nRequestID)
{
	return pUserApi->pUserApi->ReqQryInvestorLegPosition(pQryInvestorLegPosition, nRequestID);
}

///穿透监管客户认证请求
extern "C" TRADEAPI_API int ReqDSUserCertification(CTradeApi* pUserApi, CUstpFtdcDSUserInfoField *pDSUserInfo, int nRequestID)
{
	return pUserApi->pUserApi->ReqDSUserCertification(pDSUserInfo, nRequestID);
}

///穿透监管信息采集中继上传信息
extern "C" TRADEAPI_API int ReqDSProxySubmitInfo(CTradeApi* pUserApi, CUstpFtdcDSProxySubmitDataField *pDSProxySubmitData, int nRequestID)
{
	return pUserApi->pUserApi->ReqDSProxySubmitInfo(pDSProxySubmitData, nRequestID);
}






/********************************************回调函数**************************************************/
///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
extern "C" TRADEAPI_API void WINAPI RegOnFrontConnected(CTradeApi* pUserApi, CBOnFrontConnected cb)
{
	pUserApi->pUserSpi->cbOnFrontConnected = cb;
};
///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
extern "C" TRADEAPI_API void WINAPI RegOnFrontDisconnected(CTradeApi* pUserApi, CBOnFrontDisconnected cb)
{
	pUserApi->pUserSpi->cbOnFrontDisconnected = cb;
}
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
extern "C" TRADEAPI_API void WINAPI RegOnHeartBeatWarning(CTradeApi* pUserApi, CBOnHeartBeatWarning cb)
{
	pUserApi->pUserSpi->cbOnHeartBeatWarning = cb;
}
///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
extern "C" TRADEAPI_API void WINAPI RegOnPackageStart(CTradeApi* pUserApi, CBOnPackageStart cb)
{
	pUserApi->pUserSpi->cbOnPackageStart = cb;
}
///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
///@param nTopicID 主题代码（如私有流、公共流、行情流等）
///@param nSequenceNo 报文序号
extern "C" TRADEAPI_API void WINAPI RegOnPackageEnd(CTradeApi* pUserApi, CBOnPackageEnd cb)
{
	pUserApi->pUserSpi->cbOnPackageEnd = cb;
}
///错误应答
extern "C" TRADEAPI_API void WINAPI RegOnRspError(CTradeApi* pUserApi, CBOnRspError cb)
{
	pUserApi->pUserSpi->cbOnRspError = cb;
}
///风控前置系统用户登录应答
extern "C" TRADEAPI_API void WINAPI RegOnRspUserLogin(CTradeApi* pUserApi, CBOnRspUserLogin cb)
{
	pUserApi->pUserSpi->cbOnRspUserLogin = cb;
}
///用户退出应答
extern "C" TRADEAPI_API void WINAPI RegOnRspUserLogout(CTradeApi* pUserApi, CBOnRspUserLogout cb)
{
	pUserApi->pUserSpi->cbOnRspUserLogout = cb;
}
///用户密码修改应答
extern "C" TRADEAPI_API void WINAPI RegOnRspUserPasswordUpdate(CTradeApi* pUserApi, CBOnRspUserPasswordUpdate cb)
{
	pUserApi->pUserSpi->cbOnRspUserPasswordUpdate = cb;
}
///报单录入应答
extern "C" TRADEAPI_API void WINAPI RegOnRspOrderInsert(CTradeApi* pUserApi, CBOnRspOrderInsert cb)
{
	pUserApi->pUserSpi->cbOnRspOrderInsert = cb;
}
///报单操作应答
extern "C" TRADEAPI_API void WINAPI RegOnRspOrderAction(CTradeApi* pUserApi, CBOnRspOrderAction cb)
{
	pUserApi->pUserSpi->cbOnRspOrderAction = cb;
}
///报价录入应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQuoteInsert(CTradeApi* pUserApi, CBOnRspQuoteInsert cb)
{
	pUserApi->pUserSpi->cbOnRspQuoteInsert = cb;
}
///报价操作应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQuoteAction(CTradeApi* pUserApi, CBOnRspQuoteAction cb)
{
	pUserApi->pUserSpi->cbOnRspQuoteAction = cb;
}
///询价请求应答
extern "C" TRADEAPI_API void WINAPI RegOnRspForQuote(CTradeApi* pUserApi, CBOnRspForQuote cb)
{
	pUserApi->pUserSpi->cbOnRspForQuote = cb;
}
///客户申请组合应答
extern "C" TRADEAPI_API void WINAPI RegOnRspMarginCombAction(CTradeApi* pUserApi, CBOnRspMarginCombAction cb)
{
	pUserApi->pUserSpi->cbOnRspMarginCombAction = cb;
}
///用户请求出入金应答
extern "C" TRADEAPI_API void WINAPI RegOnRspUserDeposit(CTradeApi* pUserApi, CBOnRspUserDeposit cb)
{
	pUserApi->pUserSpi->cbOnRspUserDeposit = cb;
}
///用户主次席出入金应答
extern "C" TRADEAPI_API void WINAPI RegOnRspTransferMoney(CTradeApi* pUserApi, CBOnRspTransferMoney cb)
{
	pUserApi->pUserSpi->cbOnRspTransferMoney = cb;
}
///数据流回退通知
extern "C" TRADEAPI_API void WINAPI RegOnRtnFlowMessageCancel(CTradeApi* pUserApi, CBOnRtnFlowMessageCancel cb)
{
	pUserApi->pUserSpi->cbOnRtnFlowMessageCancel = cb;
}
///成交回报
extern "C" TRADEAPI_API void WINAPI RegOnRtnTrade(CTradeApi* pUserApi, CBOnRtnTrade cb)
{
	pUserApi->pUserSpi->cbOnRtnTrade = cb;
}
///报单回报
extern "C" TRADEAPI_API void WINAPI RegOnRtnOrder(CTradeApi* pUserApi, CBOnRtnOrder cb)
{
	pUserApi->pUserSpi->cbOnRtnOrder = cb;
}
///报单录入错误回报
extern "C" TRADEAPI_API void WINAPI RegOnErrRtnOrderInsert(CTradeApi* pUserApi, CBOnErrRtnOrderInsert cb)
{
	pUserApi->pUserSpi->cbOnErrRtnOrderInsert = cb;
}
///报单操作错误回报
extern "C" TRADEAPI_API void WINAPI RegOnErrRtnOrderAction(CTradeApi* pUserApi, CBOnErrRtnOrderAction cb)
{
	pUserApi->pUserSpi->cbOnErrRtnOrderAction = cb;
}
///合约交易状态通知
extern "C" TRADEAPI_API void WINAPI RegOnRtnInstrumentStatus(CTradeApi* pUserApi, CBOnRtnInstrumentStatus cb)
{
	pUserApi->pUserSpi->cbOnRtnInstrumentStatus = cb;
}
///账户出入金回报
extern "C" TRADEAPI_API void WINAPI RegOnRtnInvestorAccountDeposit(CTradeApi* pUserApi, CBOnRtnInvestorAccountDeposit cb)
{
	pUserApi->pUserSpi->cbOnRtnInvestorAccountDeposit = cb;
}
///报价回报
extern "C" TRADEAPI_API void WINAPI RegOnRtnQuote(CTradeApi* pUserApi, CBOnRtnQuote cb)
{
	pUserApi->pUserSpi->cbOnRtnQuote = cb;
}
///报价录入错误回报
extern "C" TRADEAPI_API void WINAPI RegOnErrRtnQuoteInsert(CTradeApi* pUserApi, CBOnErrRtnQuoteInsert cb)
{
	pUserApi->pUserSpi->cbOnErrRtnQuoteInsert = cb;
}
///报价撤单错误回报
extern "C" TRADEAPI_API void WINAPI RegOnErrRtnQuoteAction(CTradeApi* pUserApi, CBOnErrRtnQuoteAction cb)
{
	pUserApi->pUserSpi->cbOnErrRtnQuoteAction = cb;
}
///询价回报
extern "C" TRADEAPI_API void WINAPI RegOnRtnForQuote(CTradeApi* pUserApi, CBOnRtnForQuote cb)
{
	pUserApi->pUserSpi->cbOnRtnForQuote = cb;
}
///增加组合规则通知
extern "C" TRADEAPI_API void WINAPI RegOnRtnMarginCombinationLeg(CTradeApi* pUserApi, CBOnRtnMarginCombinationLeg cb)
{
	pUserApi->pUserSpi->cbOnRtnMarginCombinationLeg = cb;
}
///客户申请组合确认
extern "C" TRADEAPI_API void WINAPI RegOnRtnMarginCombAction(CTradeApi* pUserApi, CBOnRtnMarginCombAction cb)
{
	pUserApi->pUserSpi->cbOnRtnMarginCombAction = cb;
}
///用户请求出入金
extern "C" TRADEAPI_API void WINAPI RegOnRtnUserDeposit(CTradeApi* pUserApi, CBOnRtnUserDeposit cb)
{
	pUserApi->pUserSpi->cbOnRtnUserDeposit = cb;
}
///报单查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryOrder(CTradeApi* pUserApi, CBOnRspQryOrder cb)
{
	pUserApi->pUserSpi->cbOnRspQryOrder = cb;
}
///成交单查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryTrade(CTradeApi* pUserApi, CBOnRspQryTrade cb)
{
	pUserApi->pUserSpi->cbOnRspQryTrade = cb;
}
///可用投资者账户查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryUserInvestor(CTradeApi* pUserApi, CBOnRspQryUserInvestor cb)
{
	pUserApi->pUserSpi->cbOnRspQryUserInvestor = cb;
}
///交易编码查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryTradingCode(CTradeApi* pUserApi, CBOnRspQryTradingCode cb)
{
	pUserApi->pUserSpi->cbOnRspQryTradingCode = cb;
}
///投资者资金账户查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInvestorAccount(CTradeApi* pUserApi, CBOnRspQryInvestorAccount cb)
{
	pUserApi->pUserSpi->cbOnRspQryInvestorAccount = cb;
}
///合约查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInstrument(CTradeApi* pUserApi, CBOnRspQryInstrument cb)
{
	pUserApi->pUserSpi->cbOnRspQryInstrument = cb;
}
///交易所查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryExchange(CTradeApi* pUserApi, CBOnRspQryExchange cb)
{
	pUserApi->pUserSpi->cbOnRspQryExchange = cb;
}
///投资者持仓查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInvestorPosition(CTradeApi* pUserApi, CBOnRspQryInvestorPosition cb)
{
	pUserApi->pUserSpi->cbOnRspQryInvestorPosition = cb;
}
///订阅主题应答
extern "C" TRADEAPI_API void WINAPI RegOnRspSubscribeTopic(CTradeApi* pUserApi, CBOnRspSubscribeTopic cb)
{
	pUserApi->pUserSpi->cbOnRspSubscribeTopic = cb;
}
///合规参数查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryComplianceParam(CTradeApi* pUserApi, CBOnRspQryComplianceParam cb)
{
	pUserApi->pUserSpi->cbOnRspQryComplianceParam = cb;
}
///主题查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryTopic(CTradeApi* pUserApi, CBOnRspQryTopic cb)
{
	pUserApi->pUserSpi->cbOnRspQryTopic = cb;
}
///投资者手续费率查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInvestorFee(CTradeApi* pUserApi, CBOnRspQryInvestorFee cb)
{
	pUserApi->pUserSpi->cbOnRspQryInvestorFee = cb;
}
///投资者保证金率查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInvestorMargin(CTradeApi* pUserApi, CBOnRspQryInvestorMargin cb)
{
	pUserApi->pUserSpi->cbOnRspQryInvestorMargin = cb;
}
///交易编码组合持仓查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInvestorCombPosition(CTradeApi* pUserApi, CBOnRspQryInvestorCombPosition cb)
{
	pUserApi->pUserSpi->cbOnRspQryInvestorCombPosition = cb;
}
///交易编码单腿持仓查询应答
extern "C" TRADEAPI_API void WINAPI RegOnRspQryInvestorLegPosition(CTradeApi* pUserApi, CBOnRspQryInvestorLegPosition cb)
{
	pUserApi->pUserSpi->cbOnRspQryInvestorLegPosition = cb;
}
///穿透监管客户认证应答
extern "C" TRADEAPI_API void WINAPI RegOnRspDSUserCertification(CTradeApi* pUserApi, CBOnRspDSUserCertification cb)
{
	pUserApi->pUserSpi->cbOnRspDSUserCertification = cb;
}
///穿透监管信息采集中继上传信息响应
extern "C" TRADEAPI_API void WINAPI RegOnRspDSProxySubmitInfo(CTradeApi* pUserApi, CBOnRspDSProxySubmitInfo cb)
{
	pUserApi->pUserSpi->cbOnRspDSProxySubmitInfo = cb;
}
