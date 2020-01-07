using System.Runtime.InteropServices;

namespace FemasCommon
{
    ///系统用户登录请求
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcReqUserLoginField
    {
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///密码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string Password;
        ///用户端产品信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string UserProductInfo;
        ///接口端产品信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string InterfaceProductInfo;
        ///协议信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string ProtocolInfo;
        ///IP地址
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string IPAddress;
        ///Mac地址
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string MacAddress;
        ///数据中心代码
        public int DataCenterID;
        ///客户端运行文件大小
        public int UserProductFileSize;
    };
    ///系统用户登录应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspUserLoginField
    {
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///登录成功时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string LoginTime;
        ///用户最大本地报单号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string MaxOrderLocalID;
        ///交易系统名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 61)]
        public string TradingSystemName;
        ///数据中心代码
        public int DataCenterID;
        ///会员私有流当前长度
        public int PrivateFlowSize;
        ///交易员私有流当前长度
        public int UserFlowSize;
    };
    ///用户登出请求
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcReqUserLogoutField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
    };
    ///用户登出响应
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspUserLogoutField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
    };
    ///强制用户退出
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcForceUserExitField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
    };
    ///用户口令修改
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcUserPasswordUpdateField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///旧密码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string OldPassword;
        ///新密码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string NewPassword;
    };
    ///输入报单
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInputOrderField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///系统报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string OrderSysID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///指定通过此席位序号下单
        public int SeatNo;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///用户本地报单号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderLocalID;
        ///报单类型
        public TUstpFtdcOrderPriceTypeType OrderPriceType;
        ///买卖方向
        public TUstpFtdcDirectionType Direction;
        ///开平标志
        public TUstpFtdcOffsetFlagType OffsetFlag;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///价格
        public double LimitPrice;
        ///数量
        public int Volume;
        ///有效期类型
        public TUstpFtdcTimeConditionType TimeCondition;
        ///GTD日期
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string GTDDate;
        ///成交量类型
        public TUstpFtdcVolumeConditionType VolumeCondition;
        ///最小成交量
        public int MinVolume;
        ///止损价
        public double StopPrice;
        ///强平原因
        public TUstpFtdcForceCloseReasonType ForceCloseReason;
        ///自动挂起标志
        public int IsAutoSuspend;
        ///业务单元
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BusinessUnit;
        ///用户自定义域
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 65)]
        public string UserCustom;
    };
    ///报单操作
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcOrderActionField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string OrderSysID;
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///本次撤单操作的本地编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderActionLocalID;
        ///被撤订单的本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderLocalID;
        ///报单操作标志
        public TUstpFtdcActionFlagType ActionFlag;
        ///价格
        public double LimitPrice;
        ///数量变化
        public int VolumeChange;
    };
    ///内存表导出
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMemDbField
    {
        ///内存表名
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 61)]
        public string MemTableName;
    };
    ///用户请求出入金
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcstpUserDepositField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///金额
        public double Amount;
        ///出入金方向
        public TUstpFtdcAccountDirectionType AmountDirection;
        ///用户本地报单号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderLocalID;
    };
    ///用户主次席出入金
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcstpTransferMoneyField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///金额
        public double Amount;
        ///出入金方向
        public TUstpFtdcAccountDirectionType AmountDirection;
        ///用户本地报单号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderLocalID;
        ///银行机构代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BankID;
        ///银行转账密码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 36)]
        public string BankPasswd;
        ///主席转账密码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 36)]
        public string AccountPasswd;
    };
    ///响应信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspInfoField
    {
        ///错误代码
        public int ErrorID;
        ///错误信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 81)]
        public string ErrorMsg;
    };
    ///报单查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryOrderField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string OrderSysID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///报单状态
        public TUstpFtdcOrderStatusType OrderStatus;
    };
    ///成交查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryTradeField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///成交编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string TradeID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
    };
    ///合约查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInstrumentField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///产品代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string ProductID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
    };
    ///合约查询应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspInstrumentField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///品种代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string ProductID;
        ///品种名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string ProductName;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///合约名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string InstrumentName;
        ///交割年份
        public int DeliveryYear;
        ///交割月
        public int DeliveryMonth;
        ///限价单最大下单量
        public int MaxLimitOrderVolume;
        ///限价单最小下单量
        public int MinLimitOrderVolume;
        ///市价单最大下单量
        public int MaxMarketOrderVolume;
        ///市价单最小下单量
        public int MinMarketOrderVolume;
        ///数量乘数
        public int VolumeMultiple;
        ///报价单位
        public double PriceTick;
        ///币种
        public TUstpFtdcCurrencyType Currency;
        ///多头限仓
        public int LongPosLimit;
        ///空头限仓
        public int ShortPosLimit;
        ///跌停板价
        public double LowerLimitPrice;
        ///涨停板价
        public double UpperLimitPrice;
        ///昨结算
        public double PreSettlementPrice;
        ///合约交易状态
        public TUstpFtdcInstrumentStatusType InstrumentStatus;
        ///创建日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string CreateDate;
        ///上市日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string OpenDate;
        ///到期日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string ExpireDate;
        ///开始交割日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string StartDelivDate;
        ///最后交割日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string EndDelivDate;
        ///挂牌基准价
        public double BasisPrice;
        ///当前是否交易
        public int IsTrading;
        ///基础商品代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string UnderlyingInstrID;
        ///基础商品乘数
        public int UnderlyingMultiple;
        ///持仓类型
        public TUstpFtdcPositionTypeType PositionType;
        ///执行价
        public double StrikePrice;
        ///期权类型
        public TUstpFtdcOptionsTypeType OptionsType;
    };
    ///合约状态
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInstrumentStatusField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///品种代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string ProductID;
        ///品种名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string ProductName;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///合约名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string InstrumentName;
        ///交割年份
        public int DeliveryYear;
        ///交割月
        public int DeliveryMonth;
        ///限价单最大下单量
        public int MaxLimitOrderVolume;
        ///限价单最小下单量
        public int MinLimitOrderVolume;
        ///市价单最大下单量
        public int MaxMarketOrderVolume;
        ///市价单最小下单量
        public int MinMarketOrderVolume;
        ///数量乘数
        public int VolumeMultiple;
        ///报价单位
        public double PriceTick;
        ///币种
        public TUstpFtdcCurrencyType Currency;
        ///多头限仓
        public int LongPosLimit;
        ///空头限仓
        public int ShortPosLimit;
        ///跌停板价
        public double LowerLimitPrice;
        ///涨停板价
        public double UpperLimitPrice;
        ///昨结算
        public double PreSettlementPrice;
        ///合约交易状态
        public TUstpFtdcInstrumentStatusType InstrumentStatus;
        ///创建日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string CreateDate;
        ///上市日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string OpenDate;
        ///到期日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string ExpireDate;
        ///开始交割日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string StartDelivDate;
        ///最后交割日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string EndDelivDate;
        ///挂牌基准价
        public double BasisPrice;
        ///当前是否交易
        public int IsTrading;
        ///基础商品代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string UnderlyingInstrID;
        ///基础商品乘数
        public int UnderlyingMultiple;
        ///持仓类型
        public TUstpFtdcPositionTypeType PositionType;
        ///执行价
        public double StrikePrice;
        ///期权类型
        public TUstpFtdcOptionsTypeType OptionsType;
    };
    ///投资者资金查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInvestorAccountField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
    };
    ///投资者资金应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspInvestorAccountField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///资金帐号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string AccountID;
        ///上次结算准备金
        public double PreBalance;
        ///入金金额
        public double Deposit;
        ///出金金额
        public double Withdraw;
        ///冻结的保证金
        public double FrozenMargin;
        ///冻结手续费
        public double FrozenFee;
        ///冻结权利金
        public double FrozenPremium;
        ///手续费
        public double Fee;
        ///平仓盈亏
        public double CloseProfit;
        ///持仓盈亏
        public double PositionProfit;
        ///可用资金
        public double Available;
        ///多头冻结的保证金
        public double LongFrozenMargin;
        ///空头冻结的保证金
        public double ShortFrozenMargin;
        ///多头占用保证金
        public double LongMargin;
        ///空头占用保证金
        public double ShortMargin;
        ///当日释放保证金
        public double ReleaseMargin;
        ///动态权益
        public double DynamicRights;
        ///今日出入金
        public double TodayInOut;
        ///占用保证金
        public double Margin;
        ///期权权利金收支
        public double Premium;
        ///风险度
        public double Risk;
    };
    ///可用投资者查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryUserInvestorField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
    };
    ///可用投资者
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspUserInvestorField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
    };
    ///交易编码查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryTradingCodeField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
    };
    ///交易编码查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspTradingCodeField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///客户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///客户代码权限
        public TUstpFtdcTradingRightType ClientRight;
        ///是否活跃
        public TUstpFtdcIsActiveType IsActive;
    };
    ///交易所查询请求
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryExchangeField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
    };
    ///交易所查询应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspExchangeField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///交易所名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string ExchangeName;
    };
    ///投资者持仓查询请求
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInvestorPositionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
    };
    ///投资者持仓查询应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspInvestorPositionField
    {
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///客户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///买卖方向
        public TUstpFtdcDirectionType Direction;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///占用保证金
        public double UsedMargin;
        ///今持仓量
        public int Position;
        ///今日持仓成本
        public double PositionCost;
        ///昨持仓量
        public int YdPosition;
        ///昨日持仓成本
        public double YdPositionCost;
        ///冻结的保证金
        public double FrozenMargin;
        ///开仓冻结持仓
        public int FrozenPosition;
        ///平仓冻结持仓
        public int FrozenClosing;
        ///冻结的权利金
        public double FrozenPremium;
        ///最后一笔成交编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string LastTradeID;
        ///最后一笔本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string LastOrderLocalID;
        ///币种
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 4)]
        public string Currency;
    };
    ///合规参数查询请求
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryComplianceParamField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
    };
    ///合规参数查询应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspComplianceParamField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///客户号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///每日最大报单笔
        public int DailyMaxOrder;
        ///每日最大撤单笔
        public int DailyMaxOrderAction;
        ///每日最大错单笔
        public int DailyMaxErrorOrder;
        ///每日最大报单手
        public int DailyMaxOrderVolume;
        ///每日最大撤单手
        public int DailyMaxOrderActionVolume;
    };
    ///用户查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryUserField
    {
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string StartUserID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string EndUserID;
    };
    ///用户
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcUserField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///用户登录密码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string Password;
        ///是否活跃
        public TUstpFtdcIsActiveType IsActive;
        ///用户名称
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string UserName;
        ///用户类型
        public TUstpFtdcUserTypeType UserType;
        ///营业部
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 41)]
        public string Department;
        ///授权功能集
        public TUstpFtdcGrantFuncSetType GrantFuncSet;
        ///修改用户编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string SetUserID;
        ///操作日期
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string CommandDate;
        ///操作时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string CommandTime;
    };
    ///投资者手续费率查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInvestorFeeField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
    };
    ///投资者手续费率
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInvestorFeeField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///客户号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///品种代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string ProductID;
        ///开仓手续费按比例
        public double OpenFeeRate;
        ///开仓手续费按手数
        public double OpenFeeAmt;
        ///平仓手续费按比例
        public double OffsetFeeRate;
        ///平仓手续费按手数
        public double OffsetFeeAmt;
        ///平今仓手续费按比例
        public double OTFeeRate;
        ///平今仓手续费按手数
        public double OTFeeAmt;
        ///每笔订单收取的申报费
        public double PerOrderAmt;
        ///每笔撤单收取的申报费
        public double PerCancelAmt;
    };
    ///投资者保证金率查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInvestorMarginField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
    };
    ///投资者保证金率
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInvestorMarginField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///客户号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///品种代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string ProductID;
        ///多头占用保证金按比例
        public double LongMarginRate;
        ///多头保证金按手数
        public double LongMarginAmt;
        ///空头占用保证金按比例
        public double ShortMarginRate;
        ///空头保证金按手数
        public double ShortMarginAmt;
    };
    ///成交
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcTradeField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///会员编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ParticipantID;
        ///下单席位号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string SeatID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///客户号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///用户编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///下单用户编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string OrderUserID;
        ///成交编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string TradeID;
        ///报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string OrderSysID;
        ///本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderLocalID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///买卖方向
        public TUstpFtdcDirectionType Direction;
        ///开平标志
        public TUstpFtdcOffsetFlagType OffsetFlag;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///成交价格
        public double TradePrice;
        ///成交数量
        public int TradeVolume;
        ///成交时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradeTime;
        ///清算会员编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ClearingPartID;
        ///本次成交手续费
        public double UsedFee;
        ///本次成交占用保证金
        public double UsedMargin;
        ///本次成交占用权利金
        public double Premium;
        ///持仓表今持仓量
        public int Position;
        ///持仓表今日持仓成本
        public double PositionCost;
        ///资金表可用资金
        public double Available;
        ///资金表占用保证金
        public double Margin;
        ///资金表冻结的保证金
        public double FrozenMargin;
    };
    ///报单
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcOrderField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///系统报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string OrderSysID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///指定通过此席位序号下单
        public int SeatNo;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///用户本地报单号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserOrderLocalID;
        ///报单类型
        public TUstpFtdcOrderPriceTypeType OrderPriceType;
        ///买卖方向
        public TUstpFtdcDirectionType Direction;
        ///开平标志
        public TUstpFtdcOffsetFlagType OffsetFlag;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///价格
        public double LimitPrice;
        ///数量
        public int Volume;
        ///有效期类型
        public TUstpFtdcTimeConditionType TimeCondition;
        ///GTD日期
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string GTDDate;
        ///成交量类型
        public TUstpFtdcVolumeConditionType VolumeCondition;
        ///最小成交量
        public int MinVolume;
        ///止损价
        public double StopPrice;
        ///强平原因
        public TUstpFtdcForceCloseReasonType ForceCloseReason;
        ///自动挂起标志
        public int IsAutoSuspend;
        ///业务单元
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BusinessUnit;
        ///用户自定义域
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 65)]
        public string UserCustom;
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///会员编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ParticipantID;
        ///最初下单用户编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string OrderUserID;
        ///客户号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///下单席位号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string SeatID;
        ///插入时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string InsertTime;
        ///本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string OrderLocalID;
        ///报单来源
        public TUstpFtdcOrderSourceType OrderSource;
        ///报单状态
        public TUstpFtdcOrderStatusType OrderStatus;
        ///撤销时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string CancelTime;
        ///撤单用户编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string CancelUserID;
        ///今成交数量
        public int VolumeTraded;
        ///剩余数量
        public int VolumeRemain;
    };
    ///数据流回退
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcFlowMessageCancelField
    {
        ///序列系列号
        public int SequenceSeries;
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///数据中心代码
        public int DataCenterID;
        ///回退起始序列号
        public int StartSequenceNo;
        ///回退结束序列号
        public int EndSequenceNo;
    };
    ///信息分发
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDisseminationField
    {
        ///序列系列号
        public int SequenceSeries;
        ///序列号
        public int SequenceNo;
    };
    ///出入金结果
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInvestorAccountDepositResField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///资金帐号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string AccountID;
        ///资金流水号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string AccountSeqNo;
        ///金额
        public double Amount;
        ///出入金方向
        public TUstpFtdcAccountDirectionType AmountDirection;
        ///可用资金
        public double Available;
        ///结算准备金
        public double Balance;
    };
    ///报价录入
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInputQuoteField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///交易系统返回的系统报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string QuoteSysID;
        ///用户设定的本地报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserQuoteLocalID;
        ///飞马向交易系统报的本地报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string QuoteLocalID;
        ///买方买入数量
        public int BidVolume;
        ///买方开平标志
        public TUstpFtdcOffsetFlagType BidOffsetFlag;
        ///买方投机套保标志
        public TUstpFtdcHedgeFlagType BidHedgeFlag;
        ///买方买入价格
        public double BidPrice;
        ///卖方卖出数量
        public int AskVolume;
        ///卖方开平标志
        public TUstpFtdcOffsetFlagType AskOffsetFlag;
        ///卖方投机套保标志
        public TUstpFtdcHedgeFlagType AskHedgeFlag;
        ///卖方卖出价格
        public double AskPrice;
        ///业务单元
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BusinessUnit;
        ///用户自定义域
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 65)]
        public string UserCustom;
        ///拆分出来的买方用户本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BidUserOrderLocalID;
        ///拆分出来的卖方用户本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string AskUserOrderLocalID;
    };
    ///报价通知
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRtnQuoteField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///交易系统返回的系统报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string QuoteSysID;
        ///用户设定的本地报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserQuoteLocalID;
        ///飞马向交易系统报的本地报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string QuoteLocalID;
        ///买方买入数量
        public int BidVolume;
        ///买方开平标志
        public TUstpFtdcOffsetFlagType BidOffsetFlag;
        ///买方投机套保标志
        public TUstpFtdcHedgeFlagType BidHedgeFlag;
        ///买方买入价格
        public double BidPrice;
        ///卖方卖出数量
        public int AskVolume;
        ///卖方开平标志
        public TUstpFtdcOffsetFlagType AskOffsetFlag;
        ///卖方投机套保标志
        public TUstpFtdcHedgeFlagType AskHedgeFlag;
        ///卖方卖出价格
        public double AskPrice;
        ///业务单元
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BusinessUnit;
        ///用户自定义域
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 65)]
        public string UserCustom;
        ///拆分出来的买方用户本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BidUserOrderLocalID;
        ///拆分出来的卖方用户本地报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string AskUserOrderLocalID;
        ///买方系统报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string BidOrderSysID;
        ///卖方系统报单编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AskOrderSysID;
        ///报价单状态
        public TUstpFtdcQuoteStatusType QuoteStatus;
        ///插入时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string InsertTime;
        ///撤销时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string CancelTime;
        ///成交时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradeTime;
    };
    ///报价操作
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQuoteActionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///交易系统返回的系统报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string QuoteSysID;
        ///用户设定的被撤的本地报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserQuoteLocalID;
        ///用户向飞马报的本地撤消报价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserQuoteActionLocalID;
        ///报单操作标志
        public TUstpFtdcActionFlagType ActionFlag;
        ///业务单元
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string BusinessUnit;
        ///用户自定义域
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 65)]
        public string UserCustom;
    };
    ///询价请求
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcReqForQuoteField
    {
        ///询价编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string ReqForQuoteID;
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///询价时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string ReqForQuoteTime;
    };
    ///行情基础属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataBaseField
    {
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///结算组代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string SettlementGroupID;
        ///结算编号
        public int SettlementID;
        ///昨结算
        public double PreSettlementPrice;
        ///昨收盘
        public double PreClosePrice;
        ///昨持仓量
        public double PreOpenInterest;
        ///昨虚实度
        public double PreDelta;
    };
    ///行情静态属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataStaticField
    {
        ///今开盘
        public double OpenPrice;
        ///最高价
        public double HighestPrice;
        ///最低价
        public double LowestPrice;
        ///今收盘
        public double ClosePrice;
        ///涨停板价
        public double UpperLimitPrice;
        ///跌停板价
        public double LowerLimitPrice;
        ///今结算
        public double SettlementPrice;
        ///今虚实度
        public double CurrDelta;
    };
    ///行情最新成交属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataLastMatchField
    {
        ///最新价
        public double LastPrice;
        ///数量
        public int Volume;
        ///成交金额
        public double Turnover;
        ///持仓量
        public double OpenInterest;
    };
    ///行情最优价属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataBestPriceField
    {
        ///申买价一
        public double BidPrice1;
        ///申买量一
        public int BidVolume1;
        ///申卖价一
        public double AskPrice1;
        ///申卖量一
        public int AskVolume1;
    };
    ///行情申买二、三属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataBid23Field
    {
        ///申买价二
        public double BidPrice2;
        ///申买量二
        public int BidVolume2;
        ///申买价三
        public double BidPrice3;
        ///申买量三
        public int BidVolume3;
    };
    ///行情申卖二、三属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataAsk23Field
    {
        ///申卖价二
        public double AskPrice2;
        ///申卖量二
        public int AskVolume2;
        ///申卖价三
        public double AskPrice3;
        ///申卖量三
        public int AskVolume3;
    };
    ///行情申买四、五属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataBid45Field
    {
        ///申买价四
        public double BidPrice4;
        ///申买量四
        public int BidVolume4;
        ///申买价五
        public double BidPrice5;
        ///申买量五
        public int BidVolume5;
    };
    ///行情申卖四、五属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataAsk45Field
    {
        ///申卖价四
        public double AskPrice4;
        ///申卖量四
        public int AskVolume4;
        ///申卖价五
        public double AskPrice5;
        ///申卖量五
        public int AskVolume5;
    };
    ///行情更新时间属性
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarketDataUpdateTimeField
    {
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///最后修改时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string UpdateTime;
        ///最后修改毫秒
        public int UpdateMillisec;
    };
    ///深度行情
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDepthMarketDataField
    {
        ///交易日
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string TradingDay;
        ///结算组代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string SettlementGroupID;
        ///结算编号
        public int SettlementID;
        ///昨结算
        public double PreSettlementPrice;
        ///昨收盘
        public double PreClosePrice;
        ///昨持仓量
        public double PreOpenInterest;
        ///昨虚实度
        public double PreDelta;
        ///今开盘
        public double OpenPrice;
        ///最高价
        public double HighestPrice;
        ///最低价
        public double LowestPrice;
        ///今收盘
        public double ClosePrice;
        ///涨停板价
        public double UpperLimitPrice;
        ///跌停板价
        public double LowerLimitPrice;
        ///今结算
        public double SettlementPrice;
        ///今虚实度
        public double CurrDelta;
        ///最新价
        public double LastPrice;
        ///数量
        public int Volume;
        ///成交金额
        public double Turnover;
        ///持仓量
        public double OpenInterest;
        ///申买价一
        public double BidPrice1;
        ///申买量一
        public int BidVolume1;
        ///申卖价一
        public double AskPrice1;
        ///申卖量一
        public int AskVolume1;
        ///申买价二
        public double BidPrice2;
        ///申买量二
        public int BidVolume2;
        ///申买价三
        public double BidPrice3;
        ///申买量三
        public int BidVolume3;
        ///申卖价二
        public double AskPrice2;
        ///申卖量二
        public int AskVolume2;
        ///申卖价三
        public double AskPrice3;
        ///申卖量三
        public int AskVolume3;
        ///申买价四
        public double BidPrice4;
        ///申买量四
        public int BidVolume4;
        ///申买价五
        public double BidPrice5;
        ///申买量五
        public int BidVolume5;
        ///申卖价四
        public double AskPrice4;
        ///申卖量四
        public int AskVolume4;
        ///申卖价五
        public double AskPrice5;
        ///申卖量五
        public int AskVolume5;
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///最后修改时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 9)]
        public string UpdateTime;
        ///最后修改毫秒
        public int UpdateMillisec;
    };
    ///订阅合约的相关信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcSpecificInstrumentField
    {
        ///合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
    };
    ///申请组合
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcInputMarginCombActionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///交易用户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
        public string UserID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///用户本地编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 21)]
        public string UserActionLocalID;
        ///组合合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string CombInstrumentID;
        ///组合数量
        public int CombVolume;
        ///组合动作方向
        public TUstpFtdcCombDirectionType CombDirection;
        ///本地编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 13)]
        public string ActionLocalID;
    };
    ///交易编码组合持仓查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInvestorCombPositionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///组合合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string CombInstrumentID;
    };
    ///交易编码组合持仓查询应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspInvestorCombPositionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///客户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///组合合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string CombInstrumentID;
        ///组合持仓
        public int CombPosition;
        ///冻结组合持仓
        public int CombFrozenPosition;
        ///组合一手释放的保证金
        public double CombFreeMargin;
    };
    ///组合规则
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcMarginCombinationLegField
    {
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///组合合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string CombInstrumentID;
        ///单腿编号
        public int LegID;
        ///单腿合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string LegInstrumentID;
        ///买卖方向
        public TUstpFtdcDirectionType Direction;
        ///单腿乘数
        public int LegMultiple;
        ///优先级
        public int Priority;
    };
    ///交易编码单腿持仓查询
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcQryInvestorLegPositionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///单腿合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string LegInstrumentID;
    };
    ///交易编码单腿持仓查询应答
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcRspInvestorLegPositionField
    {
        ///经纪公司编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string BrokerID;
        ///交易所代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 11)]
        public string ExchangeID;
        ///投资者编号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string InvestorID;
        ///投机套保标志
        public TUstpFtdcHedgeFlagType HedgeFlag;
        ///客户代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 19)]
        public string ClientID;
        ///单腿合约代码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string InstrumentID;
        ///多头持仓
        public int LongPosition;
        ///空头持仓
        public int ShortPosition;
        ///多头占用保证金
        public double LongMargin;
        ///空头占用保证金
        public double ShortMargin;
        ///多头冻结持仓
        public int LongFrozenPosition;
        ///空头冻结持仓
        public int ShortFrozenPosition;
        ///多头冻结保证金
        public double LongFrozenMargin;
        ///空头冻结保证金
        public double ShortFrozenMargin;
    };
    ///穿透监管客户信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSUserInfoField
    {
        ///用户AppID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AppID;
        ///用户授权码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 17)]
        public string AuthCode;
        ///密钥加密类型
        public char EncryptType;
    };
    ///穿透监管客户认证请求信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSUserCertReqDataField
    {
        ///用户AppID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AppID;
        ///用户认证请求信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 801)]
        public string UserCertReqData;
        ///用户证书信息分片的总片数
        public int TotalNum;
        ///用户证书信息分片的第几片
        public int CurrentNum;
    };
    ///穿透监管客户认证响应信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSUserCertRspDataField
    {
        ///AppID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AppID;
        ///AppID类型
        public TUstpFtdcDSAppIDTypeType AppIDType;
        ///用户认证返回信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 801)]
        public string UserCertRspData;
        ///用户证书返回信息分片的总片数
        public int TotalNum;
        ///用户证书返回信息分片的第几片
        public int CurrentNum;
    };
    ///穿透监管客户信息采集信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSLocalSystemDataField
    {
        ///用户AppID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AppID;
        ///异常标识
        public char ExceptionFlag;
        ///用户信息采集结果
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 801)]
        public string LocalSystemData;
    };
    ///穿透监管中继验证客户信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSProxyCheckUserInfoField
    {
        ///用户AppID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AppID;
        ///用户授权码
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 17)]
        public string AuthCode;
        ///密钥加密类型
        public char EncryptType;
    };
    ///穿透监管中继处接收到的终端认证信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSProxyUserCertInField
    {
        ///穿透监管中继处接收到的终端认证信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 4097)]
        public string UserCertReqInfo;
    };
    ///穿透监管中继处接终端认证返回信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSProxyUserCertOutField
    {
        ///穿透监管中继处证书认证的返回结果
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 4097)]
        public string UserCertRspInfo;
        ///中继处返回数据已使用长度信息
        public int UserCertRspInfoLen;
    };
    ///穿透监管中继提交信息
    [StructLayout(LayoutKind.Sequential)]
    public struct CUstpFtdcDSProxySubmitDataField
    {
        ///AppID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string AppID;
        ///客户终端公网IP
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 40)]
        public string TerminalPubNetIP;
        ///客户终端公网端口号
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 6)]
        public string TerminalPubNetPort;
        ///客户终端登入时间
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 20)]
        public string TerminalLoginTime;
        ///异常标识
        public char ExceptionFlag;
        ///RealyID
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 31)]
        public string RelayID;
        ///终端采集信息
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 801)]
        public string TerminalSystemData;
    };

}