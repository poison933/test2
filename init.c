/******************************************************************************/
//
//  init.c   
//		RX62Tイニシャル処理
//  作成者
//    	萩原
//	変更履歴
//		2012/6				新規
//
/*******************************************************************************/

#include "iodefine.h"			//関連ｲﾝｸﾙｰﾄﾞﾌｧｲﾙ
#include <machine.h>
#include <stdlib.h>
#include "extern.h"
#include "main.h"

void init(void)
{
//	US i;
// ******************************** レジスタの初期化 **********************************

// ************************ クロック ***********************************


  // システムクロック
	SYSTEM.SCKCR.BIT.ICK = 0;			// ICLK = 12.5MHz × 8 = 100MHz
  // 周辺モジュールクロック
	SYSTEM.SCKCR.BIT.PCK = 1;			// PCLK = 12.5MHz × 4 = 50MHz

// *********************** I/O初期化 *************************
	/* ------------- ﾎﾟｰﾄ1 の設定 ---------------- */
                    // P10 :    in  (IRQ0-A)
                    // P11 :    out (NC)
    PORT1.ICR.BIT.B0 = 1;       // PORT1 bit0 入力バッファ有効
	PORT1.DR.BIT.B1 = 0;		// bit1を'0'にする
    PORT1.DDR.BIT.B1 = 1;       // bit1を出力に設定                   
                    
                    
	/* ------------- ﾎﾟｰﾄ2 の設定 ---------------- */
                    // P20 :	out (OUT0)
                    // P21 :	out (OUT1)
                    // P22 :	out (OUT2)
                    // P23 :	in (IN6)
                    // P24 :    in (IN7)
    
    PORT2.DR.BYTE = 0x0;        // PORT2 bit0,1,2,3 = "0"
    PORT2.DDR.BYTE = 0x07;      // PORT2 bit0,1,2を出力に設定
    PORT2.ICR.BYTE = 0x18;      // PORT2 bit3,4入力バッファ有効

    /*-------------- ﾎﾟｰﾄ3の設定 ------------------*/
                    // P30 :	in (MTCLKD-A)
                    // P31 :	in (MTCLKC-A)
                    // P32 :	in (MTCLKB-A)
                    // P33 :	in (MTCLKA-A)
 
    PORT3.ICR.BYTE = 0x0f;          // 入力バッファ有効

	/* ------------- ﾎﾟｰﾄ5 の設定 ---------------- */
                    // P50 :    in (SW2-4)
                    // P51 :    in (SW2-8)
                    // P52 :    in (SW3-1)
                    // P53 :    in (SW3-2)
                    // P54 :    in (SW3-4)
                    // P55 :    in (SW3-8)
 
    PORT5.ICR.BYTE = 0x3f;        // 入力バッファ有効

	/* ------------- ﾎﾟｰﾄ6 の設定 ---------------- */
                    // P60 :    in (SW1-1)
                    // P61 :    in (SW1-2)
                    // P62 :    in (SW1-4)
                    // P63 :    in (SW1-8)
                    // P64 :    in (SW2-1)
                    // P65 :    in (SW2-2)
                    
    PORT6.ICR.BYTE = 0x3f;       // 入力バッファ有効
    

	/* ------------- ﾎﾟｰﾄ7 の設定 ---------------- */
                    // P70 :    out (LED_POWER)
                    // P71 :    MTIOC3B
                    // P72 :    MTIOC4A
                    // P73 :    MTIOC4B(モニタ1用PWM)
                    // P74 :    MTIOC3D
                    // P75 :    MTIOC4C
                    // P76 :    out (LED_INP)

    PORT7.DR.BYTE = 0x41;       // 全てのLED OFF
    PORT7.DDR.BYTE = 0x41;

	/* ------------- ﾎﾟｰﾄ8 の設定 ---------------- */
                    // P80 :    RXD2
                    // P81 :    TXD2
                    // P82 :    out (485_DE)
    PORT8.ICR.BIT.B0 = 1;		// bit0の入力ﾊﾞｯﾌｧを有効にする
    PORT8.DR.BIT.B2 = 0;        //485_DE Disable
    PORT8.DDR.BYTE = 0x4;
    
	/* ------------- ﾎﾟｰﾄ9 の設定 ---------------- */
    
                    // P90 :    out (LED_ALARM)
                    // P91 :    MTIOC7C
                    // P92 :    MTIOC6D
                    // P93 :    MTIOC7B(モニタ2用PWM)
                    // P94 :    MTIOC7A
                    // P95 :    MTIOC6B
                    // P96 :    out (BRAKE_OFFn)

    PORT9.DR.BYTE = 0x41;       // LED_INP = OFF BRAKE = ON
    PORT9.DDR.BYTE = 0x41;
    
	/* ------------- ﾎﾟｰﾄA の設定 ---------------- */
 
                    // PA0 :    in (IN1)
                    // PA1 :    in (IN2)
                    // PA2 :    in (IN3)
                    // PA3 :    in (IN4)
                    // PA4 :    in (IN5)
                    // PA5 :    in (IN6)
 
    PORTA.ICR.BYTE = 0x3f;      // 入力バッファ有効

	/* ------------- ﾎﾟｰﾄB の設定 ---------------- */
                    // PB0 :    MTIOC0D(HMC411_CLK 25MHz)
                    // PB1 :    RXD0
                    // PB2 :    TXD0
                    // PB3 :    out (OUT3)
                    // PB4 :    out (OUT4)
                    // PB5 :    out (OUT5)
                    // PB6 :    out (OUT6)
                    // PB7 :    out (OUT7) 

    PORTB.DR.BYTE = 0;        // 出力は全て"0"    
    PORTB.DDR.BYTE = 0xf8;  

	/* ------------- ﾎﾟｰﾄD の設定 ---------------- */
                    // PD0 :    RSPCK
                    // PD1 :    MISO
                    // PD2 :    MOSI
                    // PD5 :    RXD1
    
    PORTD.ICR.BIT.B1 = 1;               // bit1の入力ﾊﾞｯﾌｧを有効にする
    PORTD.ICR.BIT.B5 = 1;				// bit5の入力ﾊﾞｯﾌｧを有効にする

	/* ------------- ﾎﾟｰﾄE の設定 ---------------- */
                    // PE0 :    out (HMC411_RESET*)
                    // PE1 :    out (TP1)
                    // PE2 :    NMI
                    // PE3 :    out (TP2)
                    // PE4 :    out (NC)
                    // PE5 :    out (HMC411_CS*)
    PORTE.DR.BIT.B0 = 1;        // HMC411 リセット完了
    PORTE.DR.BIT.B1 = 0;
    PORTE.DR.BIT.B3 = 0;
    PORTE.DR.BIT.B5 = 1;
    PORTE.DDR.BYTE = 0x3b;
    
// ========================= SCI0初期化 ===============================
// ********************************************************************
// *                         FTDI:調歩同期 19200,8,0,1                *
// ********************************************************************
//	sci0_init(2,19200,8,0,1);			// 調歩同期式
/*	
	SYSTEM.MSTPCRB.BIT.MSTPB31 = 0;		// SCI0ﾓｼﾞｭｰﾙｽﾄｯﾌﾟ状態の解除
	PORTB.ICR.BIT.B1 = 1;				// ICR register for RxD0 
	SCI0.SCR.BYTE = 0;					// SCRの初期化
	SCI0.SMR.BYTE = 0;					// ｼﾘｱﾙﾓｰﾄﾞﾚｼﾞｽﾀ = 0
	SCI0.SEMR.BIT.ABCS = 0;				// 調歩同期選択クロック
	SCI0.SEMR.BIT.NFEN = 1;				// ノイズ除去機能有効
//	SCI0.BRR = 80;						// ビットレート = ((Pφ*2)/64)/81 = 19290pps
	SCI0.BRR =							// ビットレート = ((Pφ*2)/64)/81 = 19290pps
		((12500000 * 4) / (16 * 19200) + 1) / 2 - 1;
	for(i=0;i<100;i++) ;    			// Wait 1bit(51μs)
	//	ハードウェアマニュアル参照
	//		11.2.2 割り込み要求許可レジスタm（IERm）（m=02h ～ 1Fh）
	//		11.3.1 割り込みのベクタテーブル
	ICU.IER[0x1a].BIT.IEN6 = 1;			// ERI0割り込み許可
	ICU.IER[0x1a].BIT.IEN7 = 1;			// RXI0割り込み許可
	ICU.IER[0x1b].BIT.IEN0 = 1;			// TXI0割り込み許可
	ICU.IER[0x1b].BIT.IEN1 = 1;			// TEI0割り込み許可
	ICU.IPR[0x80].BIT.IPR = 10 ;		// SCI0割り込みﾚﾍﾞﾙ = 10
	// 割込み許可
	SCI0.SCR.BYTE  = 0xF4;				//受信動作許可,送信動作許可,RXIおよびERI割込要求許可
										//TXI割込要求許可,TEI割込要求許可
*/

// ========================= SCI1初期化 ===============================
// ********************************************************************
// *                           デバッグ用                             *
// ********************************************************************
/*
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;		// SCI1ﾓｼﾞｭｰﾙｽﾄｯﾌﾟ状態の解除
	SCI1.SCR.BYTE = 0;					// SCRの初期化
	SCI1.SEMR.BIT.ABCS = 0;				// 調歩同期選択クロック
	SCI1.SEMR.BIT.NFEN = 1;				// ノイズ除去機能有効
	SCI1.SMR.BYTE = 0 ;					// ｼﾘｱﾙﾓｰﾄﾞﾚｼﾞｽﾀ = 0
	SCI1.BRR = 80;						// ﾋﾞﾄﾚｰﾄ = ((Pφ*2)/64)/81 = 19290pps
	for(i=0;i<100;i++) ;    			// Wait 1bit(51μs)
	SCI1.SCR.BYTE = 0x70;				// ｼﾘｱﾙｺﾝﾄﾛｰﾙﾚｼﾞｽﾀ = 01110000
										// 送受信イネーブル
										// RXI割り込み許可
	ICU.IPR[0x81].BIT.IPR = 10 ;		// SCI1割り込みﾚﾍﾞﾙ = 10
	ICU.IER[0x1b].BIT.IEN2 = 1;			// ERI1割り込み許可
	ICU.IER[0x1b].BIT.IEN3 = 1;			// RXI1割り込み許可

	rp = rbuf ;							// ﾎﾟｲﾝﾀ初期化
*/
// ======================== SCI2 初期化 ================================
// *********************************************************************
// *						RS485用:調歩同期 19200,8,0,1				*
// *********************************************************************
//	sci2_init(2,19200,8,0,1);			// 調歩同期式
/*	
	SYSTEM.MSTPCRB.BIT.MSTPB29 = 0;		// SCI1ﾓｼﾞｭｰﾙｽﾄｯﾌﾟ状態の解除
	IOPORT.PFFSCI.BIT.SCI2S = 1;		// P80をRXD2B、P81をTXD2B端子として使用
	SCI2.SCR.BYTE = 0;					// SCRの初期化
	SCI2.SEMR.BIT.ABCS = 0;				// 調歩同期選択クロック
	SCI2.SEMR.BIT.NFEN = 1;				// ノイズ除去機能有効
	SCI2.SMR.BYTE = 0 ;					// ｼﾘｱﾙﾓｰﾄﾞﾚｼﾞｽﾀ = 0
	SCI2.BRR = 80;						// ﾋﾞﾄﾚｰﾄ = ((Pφ*2)/64)/81 = 19290pps
	for(i=0;i<100;i++) ;    			// Wait 1bit(51μs)
	SCI2.SCR.BYTE = 0x70;				// ｼﾘｱﾙｺﾝﾄﾛｰﾙﾚｼﾞｽﾀ = 01110000
										// 送受信イネーブル
										// RXI割り込み許可
	ICU.IPR[0x82].BIT.IPR = 10 ;		// SCI2割り込みﾚﾍﾞﾙ = 10
	ICU.IER[0x1b].BIT.IEN6 = 1;			// ERI2割り込み許可
	ICU.IER[0x1b].BIT.IEN7 = 1;			// RXI2割り込み許可
	ICU.IER[0x1c].BIT.IEN0 = 1;			// TXI2割り込み許可
	ICU.IER[0x1c].BIT.IEN1 = 1;			// TEI2割り込み許可

	rp = rbuf ;							// ﾎﾟｲﾝﾀ初期化
*/	


// ========================== CMT0初期化 ====================================
// **************************************************************************
// *                   1msec タイマー(位置・速度演算用)                     *
// **************************************************************************
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;		// CMT0,CMT1ﾓｼﾞｭｰﾙｽﾄｯﾌﾟ解除
	CMT0.CMCNT = 0;						// CMT0カウンタクリア
	CMT0.CMCR.BIT.CKS = 0;				// PCLK/8=50000/8=6250
	CMT0.CMCR.BIT.CMIE = 1;				// ｺﾝﾍﾟｱﾏｯﾁによる割り込み許可
	CMT0.CMCOR = 6249;					// ｺﾝﾍﾟｱﾏｯﾁ周期 = 1ms■2013/9/12
	//CMT0.CMCOR = 12499;					// ｺﾝﾍﾟｱﾏｯﾁ周期 = 2ms
//	ICU.IPR[4].BIT.IPR = 14;			// 割り込みﾚﾍﾞﾙ=14
	ICU.IPR[4].BIT.IPR = 13;			// 割り込みﾚﾍﾞﾙ=13
	ICU.IER[3].BIT.IEN4 = 1;			// CMT0割り込み許可
	CMT.CMSTR0.BIT.STR0 = 1;			// CMT0ｶｳﾝﾄｽﾀｰﾄ

}
