using FemasCommon;
using System;
using System.Runtime.InteropServices;

namespace CSharpFemasTradeApi
{
    public class CSharpFemasTDSpi
    {
        protected CSharpFemasTDApi m_api;

        public CSharpFemasTDSpi() { }

        #region Virtual Spi Method
        ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
        public virtual void OnFrontConnected() { }

        ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
        ///@param nReason 错误原因
        ///        0x1001 网络读失败
        ///        0x1002 网络写失败
        ///        0x2001 接收心跳超时
        ///        0x2002 发送心跳失败
        ///        0x2003 收到错误报文
        public virtual void OnFrontDisconnected(int nReason) { }

        ///心跳超时警告。当长时间未收到报文时，该方法被调用。
        ///@param nTimeLapse 距离上次接收报文的时间
        public virtual void OnHeartBeatWarning(int nTimeLapse) { }

        ///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
        ///@param nTopicID 主题代码（如私有流、公共流、行情流等）
        ///@param nSequenceNo 报文序号
        public virtual void OnPackageStart(int nTopicID, int nSequenceNo) { }

        ///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
        ///@param nTopicID 主题代码（如私有流、公共流、行情流等）
        ///@param nSequenceNo 报文序号
        public virtual void OnPackageEnd(int nTopicID, int nSequenceNo) { }


        ///错误应答
        public virtual void OnRspError(ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///风控前置系统用户登录应答
        public virtual void OnRspUserLogin(ref CUstpFtdcRspUserLoginField pRspUserLogin, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///用户退出应答
        public virtual void OnRspUserLogout(ref CUstpFtdcRspUserLogoutField pRspUserLogout, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///用户密码修改应答
        public virtual void OnRspUserPasswordUpdate(ref CUstpFtdcUserPasswordUpdateField pUserPasswordUpdate, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///报单录入应答
        public virtual void OnRspOrderInsert(ref CUstpFtdcInputOrderField pInputOrder, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///报单操作应答
        public virtual void OnRspOrderAction(ref CUstpFtdcOrderActionField pOrderAction, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///报价录入应答
        public virtual void OnRspQuoteInsert(ref CUstpFtdcInputQuoteField pInputQuote, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///报价操作应答
        public virtual void OnRspQuoteAction(ref CUstpFtdcQuoteActionField pQuoteAction, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///询价请求应答
        public virtual void OnRspForQuote(ref CUstpFtdcReqForQuoteField pReqForQuote, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///客户申请组合应答
        public virtual void OnRspMarginCombAction(ref CUstpFtdcInputMarginCombActionField pInputMarginCombAction, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///用户请求出入金应答
        public virtual void OnRspUserDeposit(ref CUstpFtdcstpUserDepositField pstpUserDeposit, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///用户主次席出入金应答
        public virtual void OnRspTransferMoney(ref CUstpFtdcstpTransferMoneyField pstpTransferMoney, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///数据流回退通知
        public virtual void OnRtnFlowMessageCancel(ref CUstpFtdcFlowMessageCancelField pFlowMessageCancel) { }

        ///成交回报
        public virtual void OnRtnTrade(ref CUstpFtdcTradeField pTrade) { }

        ///报单回报
        public virtual void OnRtnOrder(ref CUstpFtdcOrderField pOrder) { }

        ///报单录入错误回报
        public virtual void OnErrRtnOrderInsert(ref CUstpFtdcInputOrderField pInputOrder, ref CUstpFtdcRspInfoField pRspInfo) { }

        ///报单操作错误回报
        public virtual void OnErrRtnOrderAction(ref CUstpFtdcOrderActionField pOrderAction, ref CUstpFtdcRspInfoField pRspInfo) { }

        ///合约交易状态通知
        public virtual void OnRtnInstrumentStatus(ref CUstpFtdcInstrumentStatusField pInstrumentStatus) { }

        ///账户出入金回报
        public virtual void OnRtnInvestorAccountDeposit(ref CUstpFtdcInvestorAccountDepositResField pInvestorAccountDepositRes) { }

        ///报价回报
        public virtual void OnRtnQuote(ref CUstpFtdcRtnQuoteField pRtnQuote) { }

        ///报价录入错误回报
        public virtual void OnErrRtnQuoteInsert(ref CUstpFtdcInputQuoteField pInputQuote, ref CUstpFtdcRspInfoField pRspInfo) { }

        ///报价撤单错误回报
        public virtual void OnErrRtnQuoteAction(ref CUstpFtdcQuoteActionField pQuoteAction, ref CUstpFtdcRspInfoField pRspInfo) { }

        ///询价回报
        public virtual void OnRtnForQuote(ref CUstpFtdcReqForQuoteField pReqForQuote) { }

        ///增加组合规则通知
        public virtual void OnRtnMarginCombinationLeg(ref CUstpFtdcMarginCombinationLegField pMarginCombinationLeg) { }

        ///客户申请组合确认
        public virtual void OnRtnMarginCombAction(ref CUstpFtdcInputMarginCombActionField pInputMarginCombAction) { }

        ///用户请求出入金
        public virtual void OnRtnUserDeposit(ref CUstpFtdcstpUserDepositField pstpUserDeposit) { }

        ///报单查询应答
        public virtual void OnRspQryOrder(ref CUstpFtdcOrderField pOrder, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///成交单查询应答
        public virtual void OnRspQryTrade(ref CUstpFtdcTradeField pTrade, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///可用投资者账户查询应答
        public virtual void OnRspQryUserInvestor(ref CUstpFtdcRspUserInvestorField pRspUserInvestor, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///交易编码查询应答
        public virtual void OnRspQryTradingCode(ref CUstpFtdcRspTradingCodeField pRspTradingCode, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///投资者资金账户查询应答
        public virtual void OnRspQryInvestorAccount(ref CUstpFtdcRspInvestorAccountField pRspInvestorAccount, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///合约查询应答
        public virtual void OnRspQryInstrument(ref CUstpFtdcRspInstrumentField pRspInstrument, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///交易所查询应答
        public virtual void OnRspQryExchange(ref CUstpFtdcRspExchangeField pRspExchange, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///投资者持仓查询应答
        public virtual void OnRspQryInvestorPosition(ref CUstpFtdcRspInvestorPositionField pRspInvestorPosition, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///订阅主题应答
        public virtual void OnRspSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///合规参数查询应答
        public virtual void OnRspQryComplianceParam(ref CUstpFtdcRspComplianceParamField pRspComplianceParam, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///主题查询应答
        public virtual void OnRspQryTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///投资者手续费率查询应答
        public virtual void OnRspQryInvestorFee(ref CUstpFtdcInvestorFeeField pInvestorFee, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///投资者保证金率查询应答
        public virtual void OnRspQryInvestorMargin(ref CUstpFtdcInvestorMarginField pInvestorMargin, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///交易编码组合持仓查询应答
        public virtual void OnRspQryInvestorCombPosition(ref CUstpFtdcRspInvestorCombPositionField pRspInvestorCombPosition, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///交易编码单腿持仓查询应答
        public virtual void OnRspQryInvestorLegPosition(ref CUstpFtdcRspInvestorLegPositionField pRspInvestorLegPosition, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///穿透监管客户认证应答
        public virtual void OnRspDSUserCertification(ref CUstpFtdcDSUserCertRspDataField pDSUserCertRspData, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        ///穿透监管信息采集中继上传信息响应
        public virtual void OnRspDSProxySubmitInfo(ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast) { }

        #endregion

    }

    public class CSharpFemasTDApi
    {
        private IntPtr api;

        const string strDllFile = "femascsharptdapi.dll";

        private string FlowPath;

        public CSharpFemasTDApi(string _FlowPath = "")
        {
            //this.FrontAddr = _addr;
            //this.BrokerID = _broker;
            //this.InvestorID = _investor;
            //this.passWord = _pwd;
            this.FlowPath = _FlowPath;
            api = CreateApi(_FlowPath);
        }

        public void RegisterSpi(CSharpFemasTDSpi spi)
        {
            OnFrontConnected += spi.OnFrontConnected;
            OnFrontDisconnected += spi.OnFrontDisconnected;
            OnHeartBeatWarning += spi.OnHeartBeatWarning;
            OnPackageStart += spi.OnPackageStart;
            OnPackageEnd += spi.OnPackageEnd;
            OnRspError += spi.OnRspError;
            OnRspUserLogin += spi.OnRspUserLogin;
            OnRspUserLogout += spi.OnRspUserLogout;
            OnRspUserPasswordUpdate += spi.OnRspUserPasswordUpdate;
            OnRspOrderInsert += spi.OnRspOrderInsert;
            OnRspOrderAction += spi.OnRspOrderAction;
            OnRspQuoteInsert += spi.OnRspQuoteInsert;
            OnRspQuoteAction += spi.OnRspQuoteAction;
            OnRspForQuote += spi.OnRspForQuote;
            OnRspMarginCombAction += spi.OnRspMarginCombAction;
            OnRspUserDeposit += spi.OnRspUserDeposit;
            OnRspTransferMoney += spi.OnRspTransferMoney;
            OnRtnFlowMessageCancel += spi.OnRtnFlowMessageCancel;
            OnRtnTrade += spi.OnRtnTrade;
            OnRtnOrder += spi.OnRtnOrder;
            OnErrRtnOrderInsert += spi.OnErrRtnOrderInsert;
            OnErrRtnOrderAction += spi.OnErrRtnOrderAction;
            OnRtnInstrumentStatus += spi.OnRtnInstrumentStatus;
            OnRtnInvestorAccountDeposit += spi.OnRtnInvestorAccountDeposit;
            OnRtnQuote += spi.OnRtnQuote;
            OnErrRtnQuoteInsert += spi.OnErrRtnQuoteInsert;
            OnErrRtnQuoteAction += spi.OnErrRtnQuoteAction;
            OnRtnForQuote += spi.OnRtnForQuote;
            OnRtnMarginCombinationLeg += spi.OnRtnMarginCombinationLeg;
            OnRtnMarginCombAction += spi.OnRtnMarginCombAction;
            OnRtnUserDeposit += spi.OnRtnUserDeposit;
            OnRspQryOrder += spi.OnRspQryOrder;
            OnRspQryTrade += spi.OnRspQryTrade;
            OnRspQryUserInvestor += spi.OnRspQryUserInvestor;
            OnRspQryTradingCode += spi.OnRspQryTradingCode;
            OnRspQryInvestorAccount += spi.OnRspQryInvestorAccount;
            OnRspQryInstrument += spi.OnRspQryInstrument;
            OnRspQryExchange += spi.OnRspQryExchange;
            OnRspQryInvestorPosition += spi.OnRspQryInvestorPosition;
            OnRspSubscribeTopic += spi.OnRspSubscribeTopic;
            OnRspQryComplianceParam += spi.OnRspQryComplianceParam;
            OnRspQryTopic += spi.OnRspQryTopic;
            OnRspQryInvestorFee += spi.OnRspQryInvestorFee;
            OnRspQryInvestorMargin += spi.OnRspQryInvestorMargin;
            OnRspQryInvestorCombPosition += spi.OnRspQryInvestorCombPosition;
            OnRspQryInvestorLegPosition += spi.OnRspQryInvestorLegPosition;
            OnRspDSUserCertification += spi.OnRspDSUserCertification;
            OnRspDSProxySubmitInfo += spi.OnRspDSProxySubmitInfo;
        }



        ///创建TraderApi
        ///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
        ///@return 创建出的UserApi
        public IntPtr CreateApi(string pszFlowPath = "")
        {
            return cppRelease(pszFlowPath);
        }
        [DllImport(strDllFile, EntryPoint = "Release", CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr cppRelease(string pszFlowPath);
        ///获取系统版本号
        ///@param nMajorVersion 主版本号
        ///@param nMinorVersion 子版本号
        ///@return 系统标识字符串
        ///删除接口对象本身
        ///@remark 不再使用本接口对象时,调用该函数删除接口对象
        public void Release()
        {
            cppRelease(api);
        }
        [DllImport(strDllFile, EntryPoint = "Release", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppRelease(IntPtr api);


        ///初始化
        ///@remark 初始化运行环境,只有调用后,接口才开始工作
        public void Init()
        {
            cppInit(api);
        }
        [DllImport(strDllFile, EntryPoint = "Init", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppInit(IntPtr api);


        ///等待接口线程结束运行
        ///@return 线程退出代码
        public int Join()
        {
            return cppJoin(api);
        }
        [DllImport(strDllFile, EntryPoint = "Join", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppJoin(IntPtr api);


        ///获取当前交易日
        ///@retrun 获取到的交易日
        ///@remark 只有登录成功后,才能得到正确的交易日
        public string GetTradingDay()
        {
            return cppGetTradingDay(api);
        }
        [DllImport(strDllFile, EntryPoint = "GetTradingDay", CallingConvention = CallingConvention.Cdecl)]
        static extern string cppGetTradingDay(IntPtr api);


        ///注册前置机网络地址
        ///@param pszFrontAddress：前置机网络地址。
        ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
        ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
        public void RegisterFront(string pszFrontAddress)
        {
            cppRegisterFront(api, pszFrontAddress);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterFront", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppRegisterFront(IntPtr api, string pszFrontAddress);


        ///注册名字服务器网络地址
        ///@param pszNsAddress：名字服务器网络地址。
        ///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
        ///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
        ///@remark RegisterFront优先于RegisterNameServer
        public void RegisterNameServer(string pszNsAddress)
        {
            cppRegisterNameServer(api, pszNsAddress);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterNameServer", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppRegisterNameServer(IntPtr api, string pszNsAddress);



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
        public int RegisterCertificateFile(string pszCertFileName, string pszKeyFileName, string pszCaFileName, string pszKeyFilePassword)
        {
            return cppRegisterCertificateFile(api, pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterCertificateFile", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppRegisterCertificateFile(IntPtr api, string pszCertFileName, string pszKeyFileName, string pszCaFileName, string pszKeyFilePassword);


        ///订阅私有流。
        ///@param nResumeType 私有流重传方式  
        ///        USTP_TERT_RESTART:从本交易日开始重传
        ///        USTP_TERT_RESUME:从上次收到的续传
        ///        USTP_TERT_QUICK:只传送登录后私有流的内容
        ///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
        public void SubscribePrivateTopic(EFemasTSSType nResumeType)
        {
            cppSubscribePrivateTopic(api, nResumeType);
        }
        [DllImport(strDllFile, EntryPoint = "SubscribePrivateTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSubscribePrivateTopic(IntPtr api, EFemasTSSType nResumeType);


        ///订阅公共流。
        ///@param nResumeType 公共流重传方式  
        ///        USTP_TERT_RESTART:从本交易日开始重传
        ///        USTP_TERT_RESUME:从上次收到的续传
        ///        USTP_TERT_QUICK:只传送登录后公共流的内容
        ///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
        public void SubscribePublicTopic(EFemasTSSType nResumeType)
        {
            cppSubscribePublicTopic(api, nResumeType);
        }
        [DllImport(strDllFile, EntryPoint = "SubscribePublicTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSubscribePublicTopic(IntPtr api, EFemasTSSType nResumeType);


        ///订阅交易员流。
        ///@param nResumeType 交易员流重传方式  
        ///        USTP_TERT_RESTART:从本交易日开始重传
        ///        USTP_TERT_RESUME:从上次收到的续传
        ///        USTP_TERT_QUICK:只传送登录后交易员流的内容
        ///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
        public void SubscribeUserTopic(EFemasTSSType nResumeType)
        {
            cppSubscribeUserTopic(api, nResumeType);
        }
        [DllImport(strDllFile, EntryPoint = "SubscribeUserTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSubscribeUserTopic(IntPtr api, EFemasTSSType nResumeType);


        ///订阅询价流。
        ///@param nResumeType 交易员流重传方式  
        ///        USTP_TERT_RESTART:从本交易日开始重传
        ///        USTP_TERT_RESUME:从上次收到的续传
        ///        USTP_TERT_QUICK:只传送登录后交易员流的内容
        ///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
        public void SubscribeForQuote(EFemasTSSType nResumeType)
        {
            cppSubscribeForQuote(api, nResumeType);
        }
        [DllImport(strDllFile, EntryPoint = "SubscribeForQuote", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSubscribeForQuote(IntPtr api, EFemasTSSType nResumeType);


        ///设置心跳超时时间。
        ///@param timeout 心跳超时时间(秒)  
        public void SetHeartbeatTimeout(int timeout)
        {
            cppSetHeartbeatTimeout(api, timeout);
        }
        [DllImport(strDllFile, EntryPoint = "SetHeartbeatTimeout", CallingConvention = CallingConvention.Cdecl)]
        static extern void cppSetHeartbeatTimeout(IntPtr api, int timeout);


        ///打开请求日志文件
        ///@param pszReqLogFileName 请求日志文件名  
        ///@return 0 操作成功
        ///@return -1 打开日志文件失败
        public int OpenRequestLog(string pszReqLogFileName)
        {
            return cppOpenRequestLog(api, pszReqLogFileName);
        }
        [DllImport(strDllFile, EntryPoint = "OpenRequestLog", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppOpenRequestLog(IntPtr api, string pszReqLogFileName);


        ///打开应答日志文件
        ///@param pszRspLogFileName 应答日志文件名  
        ///@return 0 操作成功
        ///@return -1 打开日志文件失败
        public int OpenResponseLog(string pszRspLogFileName)
        {
            return cppOpenResponseLog(api, pszRspLogFileName);
        }
        [DllImport(strDllFile, EntryPoint = "OpenResponseLog", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppOpenResponseLog(IntPtr api, string pszRspLogFileName);


        ///穿透监管中继处用户证书认证 
        public int RegisterDSProxyUserCert(ref CUstpFtdcDSProxyCheckUserInfoField pDSProxyUserUserInfo, ref CUstpFtdcDSProxyUserCertInField pDSProxyUserCertIn, ref CUstpFtdcDSProxyUserCertOutField pDProxyUserCertOut, int nRequestID)
        {
            return cppRegisterDSProxyUserCert(api, ref pDSProxyUserUserInfo, ref pDSProxyUserCertIn, ref pDProxyUserCertOut, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "RegisterDSProxyUserCert", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppRegisterDSProxyUserCert(IntPtr api, ref CUstpFtdcDSProxyCheckUserInfoField pDSProxyUserUserInfo, ref CUstpFtdcDSProxyUserCertInField pDSProxyUserCertIn, ref CUstpFtdcDSProxyUserCertOutField pDProxyUserCertOut, int nRequestID);


        ///风控前置系统用户登录请求
        public int ReqUserLogin(ref CUstpFtdcReqUserLoginField pReqUserLogin, int nRequestID)
        {
            return cppReqUserLogin(api, ref pReqUserLogin, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUserLogin", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUserLogin(IntPtr api, ref CUstpFtdcReqUserLoginField pReqUserLogin, int nRequestID);


        ///用户退出请求
        public int ReqUserLogout(ref CUstpFtdcReqUserLogoutField pReqUserLogout, int nRequestID)
        {
            return cppReqUserLogout(api, ref pReqUserLogout, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUserLogout", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUserLogout(IntPtr api, ref CUstpFtdcReqUserLogoutField pReqUserLogout, int nRequestID);


        ///用户密码修改请求
        public int ReqUserPasswordUpdate(ref CUstpFtdcUserPasswordUpdateField pUserPasswordUpdate, int nRequestID)
        {
            return cppReqUserPasswordUpdate(api, ref pUserPasswordUpdate, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUserPasswordUpdate", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUserPasswordUpdate(IntPtr api, ref CUstpFtdcUserPasswordUpdateField pUserPasswordUpdate, int nRequestID);


        ///报单录入请求
        public int ReqOrderInsert(ref CUstpFtdcInputOrderField pInputOrder, int nRequestID)
        {
            return cppReqOrderInsert(api, ref pInputOrder, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqOrderInsert", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqOrderInsert(IntPtr api, ref CUstpFtdcInputOrderField pInputOrder, int nRequestID);


        ///报单操作请求
        public int ReqOrderAction(ref CUstpFtdcOrderActionField pOrderAction, int nRequestID)
        {
            return cppReqOrderAction(api, ref pOrderAction, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqOrderAction", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqOrderAction(IntPtr api, ref CUstpFtdcOrderActionField pOrderAction, int nRequestID);


        ///请求报价录入
        public int ReqQuoteInsert(ref CUstpFtdcInputQuoteField pInputQuote, int nRequestID)
        {
            return cppReqQuoteInsert(api, ref pInputQuote, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQuoteInsert", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQuoteInsert(IntPtr api, ref CUstpFtdcInputQuoteField pInputQuote, int nRequestID);


        ///报价操作请求
        public int ReqQuoteAction(ref CUstpFtdcQuoteActionField pQuoteAction, int nRequestID)
        {
            return cppReqQuoteAction(api, ref pQuoteAction, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQuoteAction", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQuoteAction(IntPtr api, ref CUstpFtdcQuoteActionField pQuoteAction, int nRequestID);


        ///客户询价请求
        public int ReqForQuote(ref CUstpFtdcReqForQuoteField pReqForQuote, int nRequestID)
        {
            return cppReqForQuote(api, ref pReqForQuote, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqForQuote", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqForQuote(IntPtr api, ref CUstpFtdcReqForQuoteField pReqForQuote, int nRequestID);


        ///客户申请组合请求
        public int ReqMarginCombAction(ref CUstpFtdcInputMarginCombActionField pInputMarginCombAction, int nRequestID)
        {
            return cppReqMarginCombAction(api, ref pInputMarginCombAction, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqMarginCombAction", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqMarginCombAction(IntPtr api, ref CUstpFtdcInputMarginCombActionField pInputMarginCombAction, int nRequestID);


        ///用户请求出入金
        public int ReqUserDeposit(ref CUstpFtdcstpUserDepositField pstpUserDeposit, int nRequestID)
        {
            return cppReqUserDeposit(api, ref pstpUserDeposit, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqUserDeposit", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqUserDeposit(IntPtr api, ref CUstpFtdcstpUserDepositField pstpUserDeposit, int nRequestID);


        ///用户主次席出入金
        public int ReqTransferMoney(ref CUstpFtdcstpTransferMoneyField pstpTransferMoney, int nRequestID)
        {
            return cppReqTransferMoney(api, ref pstpTransferMoney, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqTransferMoney", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqTransferMoney(IntPtr api, ref CUstpFtdcstpTransferMoneyField pstpTransferMoney, int nRequestID);


        ///报单查询请求
        public int ReqQryOrder(ref CUstpFtdcQryOrderField pQryOrder, int nRequestID)
        {
            return cppReqQryOrder(api, ref pQryOrder, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryOrder", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryOrder(IntPtr api, ref CUstpFtdcQryOrderField pQryOrder, int nRequestID);


        ///成交单查询请求
        public int ReqQryTrade(ref CUstpFtdcQryTradeField pQryTrade, int nRequestID)
        {
            return cppReqQryTrade(api, ref pQryTrade, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryTrade", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryTrade(IntPtr api, ref CUstpFtdcQryTradeField pQryTrade, int nRequestID);


        ///可用投资者账户查询请求
        public int ReqQryUserInvestor(ref CUstpFtdcQryUserInvestorField pQryUserInvestor, int nRequestID)
        {
            return cppReqQryUserInvestor(api, ref pQryUserInvestor, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryUserInvestor", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryUserInvestor(IntPtr api, ref CUstpFtdcQryUserInvestorField pQryUserInvestor, int nRequestID);


        ///交易编码查询请求
        public int ReqQryTradingCode(ref CUstpFtdcQryTradingCodeField pQryTradingCode, int nRequestID)
        {
            return cppReqQryTradingCode(api, ref pQryTradingCode, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryTradingCode", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryTradingCode(IntPtr api, ref CUstpFtdcQryTradingCodeField pQryTradingCode, int nRequestID);


        ///投资者资金账户查询请求
        public int ReqQryInvestorAccount(ref CUstpFtdcQryInvestorAccountField pQryInvestorAccount, int nRequestID)
        {
            return cppReqQryInvestorAccount(api, ref pQryInvestorAccount, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInvestorAccount", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInvestorAccount(IntPtr api, ref CUstpFtdcQryInvestorAccountField pQryInvestorAccount, int nRequestID);


        ///合约查询请求
        public int ReqQryInstrument(ref CUstpFtdcQryInstrumentField pQryInstrument, int nRequestID)
        {
            return cppReqQryInstrument(api, ref pQryInstrument, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInstrument", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInstrument(IntPtr api, ref CUstpFtdcQryInstrumentField pQryInstrument, int nRequestID);


        ///交易所查询请求
        public int ReqQryExchange(ref CUstpFtdcQryExchangeField pQryExchange, int nRequestID)
        {
            return cppReqQryExchange(api, ref pQryExchange, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryExchange", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryExchange(IntPtr api, ref CUstpFtdcQryExchangeField pQryExchange, int nRequestID);


        ///投资者持仓查询请求
        public int ReqQryInvestorPosition(ref CUstpFtdcQryInvestorPositionField pQryInvestorPosition, int nRequestID)
        {
            return cppReqQryInvestorPosition(api, ref pQryInvestorPosition, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInvestorPosition", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInvestorPosition(IntPtr api, ref CUstpFtdcQryInvestorPositionField pQryInvestorPosition, int nRequestID);


        ///订阅主题请求
        public int ReqSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, int nRequestID)
        {
            return cppReqSubscribeTopic(api, ref pDissemination, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqSubscribeTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqSubscribeTopic(IntPtr api, ref CUstpFtdcDisseminationField pDissemination, int nRequestID);


        ///合规参数查询请求
        public int ReqQryComplianceParam(ref CUstpFtdcQryComplianceParamField pQryComplianceParam, int nRequestID)
        {
            return cppReqQryComplianceParam(api, ref pQryComplianceParam, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryComplianceParam", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryComplianceParam(IntPtr api, ref CUstpFtdcQryComplianceParamField pQryComplianceParam, int nRequestID);


        ///主题查询请求
        public int ReqQryTopic(ref CUstpFtdcDisseminationField pDissemination, int nRequestID)
        {
            return cppReqQryTopic(api, ref pDissemination, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryTopic", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryTopic(IntPtr api, ref CUstpFtdcDisseminationField pDissemination, int nRequestID);


        ///投资者手续费率查询请求
        public int ReqQryInvestorFee(ref CUstpFtdcQryInvestorFeeField pQryInvestorFee, int nRequestID)
        {
            return cppReqQryInvestorFee(api, ref pQryInvestorFee, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInvestorFee", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInvestorFee(IntPtr api, ref CUstpFtdcQryInvestorFeeField pQryInvestorFee, int nRequestID);


        ///投资者保证金率查询请求
        public int ReqQryInvestorMargin(ref CUstpFtdcQryInvestorMarginField pQryInvestorMargin, int nRequestID)
        {
            return cppReqQryInvestorMargin(api, ref pQryInvestorMargin, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInvestorMargin", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInvestorMargin(IntPtr api, ref CUstpFtdcQryInvestorMarginField pQryInvestorMargin, int nRequestID);


        ///交易编码组合持仓查询请求
        public int ReqQryInvestorCombPosition(ref CUstpFtdcQryInvestorCombPositionField pQryInvestorCombPosition, int nRequestID)
        {
            return cppReqQryInvestorCombPosition(api, ref pQryInvestorCombPosition, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInvestorCombPosition", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInvestorCombPosition(IntPtr api, ref CUstpFtdcQryInvestorCombPositionField pQryInvestorCombPosition, int nRequestID);


        ///交易编码单腿持仓查询请求
        public int ReqQryInvestorLegPosition(ref CUstpFtdcQryInvestorLegPositionField pQryInvestorLegPosition, int nRequestID)
        {
            return cppReqQryInvestorLegPosition(api, ref pQryInvestorLegPosition, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqQryInvestorLegPosition", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqQryInvestorLegPosition(IntPtr api, ref CUstpFtdcQryInvestorLegPositionField pQryInvestorLegPosition, int nRequestID);


        ///穿透监管客户认证请求
        public int ReqDSUserCertification(ref CUstpFtdcDSUserInfoField pDSUserInfo, int nRequestID)
        {
            return cppReqDSUserCertification(api, ref pDSUserInfo, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqDSUserCertification", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqDSUserCertification(IntPtr api, ref CUstpFtdcDSUserInfoField pDSUserInfo, int nRequestID);


        ///穿透监管信息采集中继上传信息
        public int ReqDSProxySubmitInfo(ref CUstpFtdcDSProxySubmitDataField pDSProxySubmitData, int nRequestID)
        {
            return cppReqDSProxySubmitInfo(api, ref pDSProxySubmitData, nRequestID);
        }
        [DllImport(strDllFile, EntryPoint = "ReqDSProxySubmitInfo", CallingConvention = CallingConvention.Cdecl)]
        static extern int cppReqDSProxySubmitInfo(IntPtr api, ref CUstpFtdcDSProxySubmitDataField pDSProxySubmitData, int nRequestID);




        /******************************************注册回调*************************************************************/
        [DllImport(strDllFile, EntryPoint = "RegOnFrontConnected", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnFrontConnected(IntPtr api, deleFrontConnected cb);
        deleFrontConnected FrontConnected;
        public delegate void deleFrontConnected();
        public event deleFrontConnected OnFrontConnected
        {
            add { FrontConnected += value; cppRegOnFrontConnected(api, FrontConnected); }
            remove { FrontConnected -= value; cppRegOnFrontConnected(api, FrontConnected); }
        }

        [DllImport(strDllFile, EntryPoint = "RegOnFrontDisconnected", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnFrontDisconnected(IntPtr api, deleFrontDisconnected cb);
        deleFrontDisconnected FrontDisconnected;
        public delegate void deleFrontDisconnected(int nReason);
        public event deleFrontDisconnected OnFrontDisconnected
        {
            add { FrontDisconnected += value; cppRegOnFrontDisconnected(api, FrontDisconnected); }
            remove { FrontDisconnected -= value; cppRegOnFrontDisconnected(api, FrontDisconnected); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnHeartBeatWarning", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnHeartBeatWarning(IntPtr api, deleHeartBeatWarning cb);
        deleHeartBeatWarning HeartBeatWarning;
        public delegate void deleHeartBeatWarning(int nTimeLapse);
        public event deleHeartBeatWarning OnHeartBeatWarning
        {
            add { HeartBeatWarning += value; cppRegOnHeartBeatWarning(api, HeartBeatWarning); }
            remove { HeartBeatWarning -= value; cppRegOnHeartBeatWarning(api, HeartBeatWarning); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnPackageStart", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnPackageStart(IntPtr api, delePackageStart cb);
        delePackageStart PackageStart;
        public delegate void delePackageStart(int nTopicID, int nSequenceNo);
        public event delePackageStart OnPackageStart
        {
            add { PackageStart += value; cppRegOnPackageStart(api, PackageStart); }
            remove { PackageStart -= value; cppRegOnPackageStart(api, PackageStart); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnPackageEnd", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnPackageEnd(IntPtr api, delePackageEnd cb);
        delePackageEnd PackageEnd;
        public delegate void delePackageEnd(int nTopicID, int nSequenceNo);
        public event delePackageEnd OnPackageEnd
        {
            add { PackageEnd += value; cppRegOnPackageEnd(api, PackageEnd); }
            remove { PackageEnd -= value; cppRegOnPackageEnd(api, PackageEnd); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspError", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspError(IntPtr api, deleRspError cb);
        deleRspError RspError;
        public delegate void deleRspError(ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspError OnRspError
        {
            add { RspError += value; cppRegOnRspError(api, RspError); }
            remove { RspError -= value; cppRegOnRspError(api, RspError); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUserLogin", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUserLogin(IntPtr api, deleRspUserLogin cb);
        deleRspUserLogin RspUserLogin;
        public delegate void deleRspUserLogin(ref CUstpFtdcRspUserLoginField pRspUserLogin, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUserLogin OnRspUserLogin
        {
            add { RspUserLogin += value; cppRegOnRspUserLogin(api, RspUserLogin); }
            remove { RspUserLogin -= value; cppRegOnRspUserLogin(api, RspUserLogin); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUserLogout", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUserLogout(IntPtr api, deleRspUserLogout cb);
        deleRspUserLogout RspUserLogout;
        public delegate void deleRspUserLogout(ref CUstpFtdcRspUserLogoutField pRspUserLogout, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUserLogout OnRspUserLogout
        {
            add { RspUserLogout += value; cppRegOnRspUserLogout(api, RspUserLogout); }
            remove { RspUserLogout -= value; cppRegOnRspUserLogout(api, RspUserLogout); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUserPasswordUpdate", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUserPasswordUpdate(IntPtr api, deleRspUserPasswordUpdate cb);
        deleRspUserPasswordUpdate RspUserPasswordUpdate;
        public delegate void deleRspUserPasswordUpdate(ref CUstpFtdcUserPasswordUpdateField pUserPasswordUpdate, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUserPasswordUpdate OnRspUserPasswordUpdate
        {
            add { RspUserPasswordUpdate += value; cppRegOnRspUserPasswordUpdate(api, RspUserPasswordUpdate); }
            remove { RspUserPasswordUpdate -= value; cppRegOnRspUserPasswordUpdate(api, RspUserPasswordUpdate); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspOrderInsert", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspOrderInsert(IntPtr api, deleRspOrderInsert cb);
        deleRspOrderInsert RspOrderInsert;
        public delegate void deleRspOrderInsert(ref CUstpFtdcInputOrderField pInputOrder, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspOrderInsert OnRspOrderInsert
        {
            add { RspOrderInsert += value; cppRegOnRspOrderInsert(api, RspOrderInsert); }
            remove { RspOrderInsert -= value; cppRegOnRspOrderInsert(api, RspOrderInsert); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspOrderAction", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspOrderAction(IntPtr api, deleRspOrderAction cb);
        deleRspOrderAction RspOrderAction;
        public delegate void deleRspOrderAction(ref CUstpFtdcOrderActionField pOrderAction, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspOrderAction OnRspOrderAction
        {
            add { RspOrderAction += value; cppRegOnRspOrderAction(api, RspOrderAction); }
            remove { RspOrderAction -= value; cppRegOnRspOrderAction(api, RspOrderAction); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQuoteInsert", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQuoteInsert(IntPtr api, deleRspQuoteInsert cb);
        deleRspQuoteInsert RspQuoteInsert;
        public delegate void deleRspQuoteInsert(ref CUstpFtdcInputQuoteField pInputQuote, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQuoteInsert OnRspQuoteInsert
        {
            add { RspQuoteInsert += value; cppRegOnRspQuoteInsert(api, RspQuoteInsert); }
            remove { RspQuoteInsert -= value; cppRegOnRspQuoteInsert(api, RspQuoteInsert); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQuoteAction", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQuoteAction(IntPtr api, deleRspQuoteAction cb);
        deleRspQuoteAction RspQuoteAction;
        public delegate void deleRspQuoteAction(ref CUstpFtdcQuoteActionField pQuoteAction, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQuoteAction OnRspQuoteAction
        {
            add { RspQuoteAction += value; cppRegOnRspQuoteAction(api, RspQuoteAction); }
            remove { RspQuoteAction -= value; cppRegOnRspQuoteAction(api, RspQuoteAction); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspForQuote", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspForQuote(IntPtr api, deleRspForQuote cb);
        deleRspForQuote RspForQuote;
        public delegate void deleRspForQuote(ref CUstpFtdcReqForQuoteField pReqForQuote, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspForQuote OnRspForQuote
        {
            add { RspForQuote += value; cppRegOnRspForQuote(api, RspForQuote); }
            remove { RspForQuote -= value; cppRegOnRspForQuote(api, RspForQuote); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspMarginCombAction", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspMarginCombAction(IntPtr api, deleRspMarginCombAction cb);
        deleRspMarginCombAction RspMarginCombAction;
        public delegate void deleRspMarginCombAction(ref CUstpFtdcInputMarginCombActionField pInputMarginCombAction, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspMarginCombAction OnRspMarginCombAction
        {
            add { RspMarginCombAction += value; cppRegOnRspMarginCombAction(api, RspMarginCombAction); }
            remove { RspMarginCombAction -= value; cppRegOnRspMarginCombAction(api, RspMarginCombAction); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspUserDeposit", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspUserDeposit(IntPtr api, deleRspUserDeposit cb);
        deleRspUserDeposit RspUserDeposit;
        public delegate void deleRspUserDeposit(ref CUstpFtdcstpUserDepositField pstpUserDeposit, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspUserDeposit OnRspUserDeposit
        {
            add { RspUserDeposit += value; cppRegOnRspUserDeposit(api, RspUserDeposit); }
            remove { RspUserDeposit -= value; cppRegOnRspUserDeposit(api, RspUserDeposit); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspTransferMoney", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspTransferMoney(IntPtr api, deleRspTransferMoney cb);
        deleRspTransferMoney RspTransferMoney;
        public delegate void deleRspTransferMoney(ref CUstpFtdcstpTransferMoneyField pstpTransferMoney, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspTransferMoney OnRspTransferMoney
        {
            add { RspTransferMoney += value; cppRegOnRspTransferMoney(api, RspTransferMoney); }
            remove { RspTransferMoney -= value; cppRegOnRspTransferMoney(api, RspTransferMoney); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnFlowMessageCancel", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnFlowMessageCancel(IntPtr api, deleRtnFlowMessageCancel cb);
        deleRtnFlowMessageCancel RtnFlowMessageCancel;
        public delegate void deleRtnFlowMessageCancel(ref CUstpFtdcFlowMessageCancelField pFlowMessageCancel);
        public event deleRtnFlowMessageCancel OnRtnFlowMessageCancel
        {
            add { RtnFlowMessageCancel += value; cppRegOnRtnFlowMessageCancel(api, RtnFlowMessageCancel); }
            remove { RtnFlowMessageCancel -= value; cppRegOnRtnFlowMessageCancel(api, RtnFlowMessageCancel); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnTrade", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnTrade(IntPtr api, deleRtnTrade cb);
        deleRtnTrade RtnTrade;
        public delegate void deleRtnTrade(ref CUstpFtdcTradeField pTrade);
        public event deleRtnTrade OnRtnTrade
        {
            add { RtnTrade += value; cppRegOnRtnTrade(api, RtnTrade); }
            remove { RtnTrade -= value; cppRegOnRtnTrade(api, RtnTrade); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnOrder", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnOrder(IntPtr api, deleRtnOrder cb);
        deleRtnOrder RtnOrder;
        public delegate void deleRtnOrder(ref CUstpFtdcOrderField pOrder);
        public event deleRtnOrder OnRtnOrder
        {
            add { RtnOrder += value; cppRegOnRtnOrder(api, RtnOrder); }
            remove { RtnOrder -= value; cppRegOnRtnOrder(api, RtnOrder); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnErrRtnOrderInsert", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnErrRtnOrderInsert(IntPtr api, deleErrRtnOrderInsert cb);
        deleErrRtnOrderInsert ErrRtnOrderInsert;
        public delegate void deleErrRtnOrderInsert(ref CUstpFtdcInputOrderField pInputOrder, ref CUstpFtdcRspInfoField pRspInfo);
        public event deleErrRtnOrderInsert OnErrRtnOrderInsert
        {
            add { ErrRtnOrderInsert += value; cppRegOnErrRtnOrderInsert(api, ErrRtnOrderInsert); }
            remove { ErrRtnOrderInsert -= value; cppRegOnErrRtnOrderInsert(api, ErrRtnOrderInsert); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnErrRtnOrderAction", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnErrRtnOrderAction(IntPtr api, deleErrRtnOrderAction cb);
        deleErrRtnOrderAction ErrRtnOrderAction;
        public delegate void deleErrRtnOrderAction(ref CUstpFtdcOrderActionField pOrderAction, ref CUstpFtdcRspInfoField pRspInfo);
        public event deleErrRtnOrderAction OnErrRtnOrderAction
        {
            add { ErrRtnOrderAction += value; cppRegOnErrRtnOrderAction(api, ErrRtnOrderAction); }
            remove { ErrRtnOrderAction -= value; cppRegOnErrRtnOrderAction(api, ErrRtnOrderAction); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnInstrumentStatus", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnInstrumentStatus(IntPtr api, deleRtnInstrumentStatus cb);
        deleRtnInstrumentStatus RtnInstrumentStatus;
        public delegate void deleRtnInstrumentStatus(ref CUstpFtdcInstrumentStatusField pInstrumentStatus);
        public event deleRtnInstrumentStatus OnRtnInstrumentStatus
        {
            add { RtnInstrumentStatus += value; cppRegOnRtnInstrumentStatus(api, RtnInstrumentStatus); }
            remove { RtnInstrumentStatus -= value; cppRegOnRtnInstrumentStatus(api, RtnInstrumentStatus); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnInvestorAccountDeposit", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnInvestorAccountDeposit(IntPtr api, deleRtnInvestorAccountDeposit cb);
        deleRtnInvestorAccountDeposit RtnInvestorAccountDeposit;
        public delegate void deleRtnInvestorAccountDeposit(ref CUstpFtdcInvestorAccountDepositResField pInvestorAccountDepositRes);
        public event deleRtnInvestorAccountDeposit OnRtnInvestorAccountDeposit
        {
            add { RtnInvestorAccountDeposit += value; cppRegOnRtnInvestorAccountDeposit(api, RtnInvestorAccountDeposit); }
            remove { RtnInvestorAccountDeposit -= value; cppRegOnRtnInvestorAccountDeposit(api, RtnInvestorAccountDeposit); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnQuote", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnQuote(IntPtr api, deleRtnQuote cb);
        deleRtnQuote RtnQuote;
        public delegate void deleRtnQuote(ref CUstpFtdcRtnQuoteField pRtnQuote);
        public event deleRtnQuote OnRtnQuote
        {
            add { RtnQuote += value; cppRegOnRtnQuote(api, RtnQuote); }
            remove { RtnQuote -= value; cppRegOnRtnQuote(api, RtnQuote); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnErrRtnQuoteInsert", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnErrRtnQuoteInsert(IntPtr api, deleErrRtnQuoteInsert cb);
        deleErrRtnQuoteInsert ErrRtnQuoteInsert;
        public delegate void deleErrRtnQuoteInsert(ref CUstpFtdcInputQuoteField pInputQuote, ref CUstpFtdcRspInfoField pRspInfo);
        public event deleErrRtnQuoteInsert OnErrRtnQuoteInsert
        {
            add { ErrRtnQuoteInsert += value; cppRegOnErrRtnQuoteInsert(api, ErrRtnQuoteInsert); }
            remove { ErrRtnQuoteInsert -= value; cppRegOnErrRtnQuoteInsert(api, ErrRtnQuoteInsert); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnErrRtnQuoteAction", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnErrRtnQuoteAction(IntPtr api, deleErrRtnQuoteAction cb);
        deleErrRtnQuoteAction ErrRtnQuoteAction;
        public delegate void deleErrRtnQuoteAction(ref CUstpFtdcQuoteActionField pQuoteAction, ref CUstpFtdcRspInfoField pRspInfo);
        public event deleErrRtnQuoteAction OnErrRtnQuoteAction
        {
            add { ErrRtnQuoteAction += value; cppRegOnErrRtnQuoteAction(api, ErrRtnQuoteAction); }
            remove { ErrRtnQuoteAction -= value; cppRegOnErrRtnQuoteAction(api, ErrRtnQuoteAction); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnForQuote", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnForQuote(IntPtr api, deleRtnForQuote cb);
        deleRtnForQuote RtnForQuote;
        public delegate void deleRtnForQuote(ref CUstpFtdcReqForQuoteField pReqForQuote);
        public event deleRtnForQuote OnRtnForQuote
        {
            add { RtnForQuote += value; cppRegOnRtnForQuote(api, RtnForQuote); }
            remove { RtnForQuote -= value; cppRegOnRtnForQuote(api, RtnForQuote); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnMarginCombinationLeg", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnMarginCombinationLeg(IntPtr api, deleRtnMarginCombinationLeg cb);
        deleRtnMarginCombinationLeg RtnMarginCombinationLeg;
        public delegate void deleRtnMarginCombinationLeg(ref CUstpFtdcMarginCombinationLegField pMarginCombinationLeg);
        public event deleRtnMarginCombinationLeg OnRtnMarginCombinationLeg
        {
            add { RtnMarginCombinationLeg += value; cppRegOnRtnMarginCombinationLeg(api, RtnMarginCombinationLeg); }
            remove { RtnMarginCombinationLeg -= value; cppRegOnRtnMarginCombinationLeg(api, RtnMarginCombinationLeg); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnMarginCombAction", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnMarginCombAction(IntPtr api, deleRtnMarginCombAction cb);
        deleRtnMarginCombAction RtnMarginCombAction;
        public delegate void deleRtnMarginCombAction(ref CUstpFtdcInputMarginCombActionField pInputMarginCombAction);
        public event deleRtnMarginCombAction OnRtnMarginCombAction
        {
            add { RtnMarginCombAction += value; cppRegOnRtnMarginCombAction(api, RtnMarginCombAction); }
            remove { RtnMarginCombAction -= value; cppRegOnRtnMarginCombAction(api, RtnMarginCombAction); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRtnUserDeposit", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRtnUserDeposit(IntPtr api, deleRtnUserDeposit cb);
        deleRtnUserDeposit RtnUserDeposit;
        public delegate void deleRtnUserDeposit(ref CUstpFtdcstpUserDepositField pstpUserDeposit);
        public event deleRtnUserDeposit OnRtnUserDeposit
        {
            add { RtnUserDeposit += value; cppRegOnRtnUserDeposit(api, RtnUserDeposit); }
            remove { RtnUserDeposit -= value; cppRegOnRtnUserDeposit(api, RtnUserDeposit); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryOrder", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryOrder(IntPtr api, deleRspQryOrder cb);
        deleRspQryOrder RspQryOrder;
        public delegate void deleRspQryOrder(ref CUstpFtdcOrderField pOrder, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryOrder OnRspQryOrder
        {
            add { RspQryOrder += value; cppRegOnRspQryOrder(api, RspQryOrder); }
            remove { RspQryOrder -= value; cppRegOnRspQryOrder(api, RspQryOrder); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryTrade", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryTrade(IntPtr api, deleRspQryTrade cb);
        deleRspQryTrade RspQryTrade;
        public delegate void deleRspQryTrade(ref CUstpFtdcTradeField pTrade, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryTrade OnRspQryTrade
        {
            add { RspQryTrade += value; cppRegOnRspQryTrade(api, RspQryTrade); }
            remove { RspQryTrade -= value; cppRegOnRspQryTrade(api, RspQryTrade); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryUserInvestor", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryUserInvestor(IntPtr api, deleRspQryUserInvestor cb);
        deleRspQryUserInvestor RspQryUserInvestor;
        public delegate void deleRspQryUserInvestor(ref CUstpFtdcRspUserInvestorField pRspUserInvestor, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryUserInvestor OnRspQryUserInvestor
        {
            add { RspQryUserInvestor += value; cppRegOnRspQryUserInvestor(api, RspQryUserInvestor); }
            remove { RspQryUserInvestor -= value; cppRegOnRspQryUserInvestor(api, RspQryUserInvestor); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryTradingCode", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryTradingCode(IntPtr api, deleRspQryTradingCode cb);
        deleRspQryTradingCode RspQryTradingCode;
        public delegate void deleRspQryTradingCode(ref CUstpFtdcRspTradingCodeField pRspTradingCode, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryTradingCode OnRspQryTradingCode
        {
            add { RspQryTradingCode += value; cppRegOnRspQryTradingCode(api, RspQryTradingCode); }
            remove { RspQryTradingCode -= value; cppRegOnRspQryTradingCode(api, RspQryTradingCode); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInvestorAccount", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInvestorAccount(IntPtr api, deleRspQryInvestorAccount cb);
        deleRspQryInvestorAccount RspQryInvestorAccount;
        public delegate void deleRspQryInvestorAccount(ref CUstpFtdcRspInvestorAccountField pRspInvestorAccount, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInvestorAccount OnRspQryInvestorAccount
        {
            add { RspQryInvestorAccount += value; cppRegOnRspQryInvestorAccount(api, RspQryInvestorAccount); }
            remove { RspQryInvestorAccount -= value; cppRegOnRspQryInvestorAccount(api, RspQryInvestorAccount); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInstrument", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInstrument(IntPtr api, deleRspQryInstrument cb);
        deleRspQryInstrument RspQryInstrument;
        public delegate void deleRspQryInstrument(ref CUstpFtdcRspInstrumentField pRspInstrument, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInstrument OnRspQryInstrument
        {
            add { RspQryInstrument += value; cppRegOnRspQryInstrument(api, RspQryInstrument); }
            remove { RspQryInstrument -= value; cppRegOnRspQryInstrument(api, RspQryInstrument); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryExchange", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryExchange(IntPtr api, deleRspQryExchange cb);
        deleRspQryExchange RspQryExchange;
        public delegate void deleRspQryExchange(ref CUstpFtdcRspExchangeField pRspExchange, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryExchange OnRspQryExchange
        {
            add { RspQryExchange += value; cppRegOnRspQryExchange(api, RspQryExchange); }
            remove { RspQryExchange -= value; cppRegOnRspQryExchange(api, RspQryExchange); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInvestorPosition", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInvestorPosition(IntPtr api, deleRspQryInvestorPosition cb);
        deleRspQryInvestorPosition RspQryInvestorPosition;
        public delegate void deleRspQryInvestorPosition(ref CUstpFtdcRspInvestorPositionField pRspInvestorPosition, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInvestorPosition OnRspQryInvestorPosition
        {
            add { RspQryInvestorPosition += value; cppRegOnRspQryInvestorPosition(api, RspQryInvestorPosition); }
            remove { RspQryInvestorPosition -= value; cppRegOnRspQryInvestorPosition(api, RspQryInvestorPosition); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspSubscribeTopic", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspSubscribeTopic(IntPtr api, deleRspSubscribeTopic cb);
        deleRspSubscribeTopic RspSubscribeTopic;
        public delegate void deleRspSubscribeTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspSubscribeTopic OnRspSubscribeTopic
        {
            add { RspSubscribeTopic += value; cppRegOnRspSubscribeTopic(api, RspSubscribeTopic); }
            remove { RspSubscribeTopic -= value; cppRegOnRspSubscribeTopic(api, RspSubscribeTopic); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryComplianceParam", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryComplianceParam(IntPtr api, deleRspQryComplianceParam cb);
        deleRspQryComplianceParam RspQryComplianceParam;
        public delegate void deleRspQryComplianceParam(ref CUstpFtdcRspComplianceParamField pRspComplianceParam, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryComplianceParam OnRspQryComplianceParam
        {
            add { RspQryComplianceParam += value; cppRegOnRspQryComplianceParam(api, RspQryComplianceParam); }
            remove { RspQryComplianceParam -= value; cppRegOnRspQryComplianceParam(api, RspQryComplianceParam); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryTopic", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryTopic(IntPtr api, deleRspQryTopic cb);
        deleRspQryTopic RspQryTopic;
        public delegate void deleRspQryTopic(ref CUstpFtdcDisseminationField pDissemination, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryTopic OnRspQryTopic
        {
            add { RspQryTopic += value; cppRegOnRspQryTopic(api, RspQryTopic); }
            remove { RspQryTopic -= value; cppRegOnRspQryTopic(api, RspQryTopic); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInvestorFee", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInvestorFee(IntPtr api, deleRspQryInvestorFee cb);
        deleRspQryInvestorFee RspQryInvestorFee;
        public delegate void deleRspQryInvestorFee(ref CUstpFtdcInvestorFeeField pInvestorFee, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInvestorFee OnRspQryInvestorFee
        {
            add { RspQryInvestorFee += value; cppRegOnRspQryInvestorFee(api, RspQryInvestorFee); }
            remove { RspQryInvestorFee -= value; cppRegOnRspQryInvestorFee(api, RspQryInvestorFee); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInvestorMargin", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInvestorMargin(IntPtr api, deleRspQryInvestorMargin cb);
        deleRspQryInvestorMargin RspQryInvestorMargin;
        public delegate void deleRspQryInvestorMargin(ref CUstpFtdcInvestorMarginField pInvestorMargin, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInvestorMargin OnRspQryInvestorMargin
        {
            add { RspQryInvestorMargin += value; cppRegOnRspQryInvestorMargin(api, RspQryInvestorMargin); }
            remove { RspQryInvestorMargin -= value; cppRegOnRspQryInvestorMargin(api, RspQryInvestorMargin); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInvestorCombPosition", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInvestorCombPosition(IntPtr api, deleRspQryInvestorCombPosition cb);
        deleRspQryInvestorCombPosition RspQryInvestorCombPosition;
        public delegate void deleRspQryInvestorCombPosition(ref CUstpFtdcRspInvestorCombPositionField pRspInvestorCombPosition, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInvestorCombPosition OnRspQryInvestorCombPosition
        {
            add { RspQryInvestorCombPosition += value; cppRegOnRspQryInvestorCombPosition(api, RspQryInvestorCombPosition); }
            remove { RspQryInvestorCombPosition -= value; cppRegOnRspQryInvestorCombPosition(api, RspQryInvestorCombPosition); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspQryInvestorLegPosition", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspQryInvestorLegPosition(IntPtr api, deleRspQryInvestorLegPosition cb);
        deleRspQryInvestorLegPosition RspQryInvestorLegPosition;
        public delegate void deleRspQryInvestorLegPosition(ref CUstpFtdcRspInvestorLegPositionField pRspInvestorLegPosition, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspQryInvestorLegPosition OnRspQryInvestorLegPosition
        {
            add { RspQryInvestorLegPosition += value; cppRegOnRspQryInvestorLegPosition(api, RspQryInvestorLegPosition); }
            remove { RspQryInvestorLegPosition -= value; cppRegOnRspQryInvestorLegPosition(api, RspQryInvestorLegPosition); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspDSUserCertification", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspDSUserCertification(IntPtr api, deleRspDSUserCertification cb);
        deleRspDSUserCertification RspDSUserCertification;
        public delegate void deleRspDSUserCertification(ref CUstpFtdcDSUserCertRspDataField pDSUserCertRspData, ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspDSUserCertification OnRspDSUserCertification
        {
            add { RspDSUserCertification += value; cppRegOnRspDSUserCertification(api, RspDSUserCertification); }
            remove { RspDSUserCertification -= value; cppRegOnRspDSUserCertification(api, RspDSUserCertification); }
        }


        [DllImport(strDllFile, EntryPoint = "RegOnRspDSProxySubmitInfo", CallingConvention = CallingConvention.StdCall)]
        static extern void cppRegOnRspDSProxySubmitInfo(IntPtr api, deleRspDSProxySubmitInfo cb);
        deleRspDSProxySubmitInfo RspDSProxySubmitInfo;
        public delegate void deleRspDSProxySubmitInfo(ref CUstpFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        public event deleRspDSProxySubmitInfo OnRspDSProxySubmitInfo
        {
            add { RspDSProxySubmitInfo += value; cppRegOnRspDSProxySubmitInfo(api, RspDSProxySubmitInfo); }
            remove { RspDSProxySubmitInfo -= value; cppRegOnRspDSProxySubmitInfo(api, RspDSProxySubmitInfo); }
        }





    }
}
