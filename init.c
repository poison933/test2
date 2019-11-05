/******************************************************************************/
//
//  init.c   
//		RX62T�C�j�V��������
//  �쐬��
//    	����
//	�ύX����
//		2012/6				�V�K
//
/*******************************************************************************/

#include "iodefine.h"			//�֘A�ݸٰ��̧��
#include <machine.h>
#include <stdlib.h>
#include "extern.h"
#include "main.h"

void init(void)
{
//	US i;
// ******************************** ���W�X�^�̏����� **********************************

// ************************ �N���b�N ***********************************


  // �V�X�e���N���b�N
	SYSTEM.SCKCR.BIT.ICK = 0;			// ICLK = 12.5MHz �~ 8 = 100MHz
  // ���Ӄ��W���[���N���b�N
	SYSTEM.SCKCR.BIT.PCK = 1;			// PCLK = 12.5MHz �~ 4 = 50MHz

// *********************** I/O������ *************************
	/* ------------- �߰�1 �̐ݒ� ---------------- */
                    // P10 :    in  (IRQ0-A)
                    // P11 :    out (NC)
    PORT1.ICR.BIT.B0 = 1;       // PORT1 bit0 ���̓o�b�t�@�L��
	PORT1.DR.BIT.B1 = 0;		// bit1��'0'�ɂ���
    PORT1.DDR.BIT.B1 = 1;       // bit1���o�͂ɐݒ�                   
                    
                    
	/* ------------- �߰�2 �̐ݒ� ---------------- */
                    // P20 :	out (OUT0)
                    // P21 :	out (OUT1)
                    // P22 :	out (OUT2)
                    // P23 :	in (IN6)
                    // P24 :    in (IN7)
    
    PORT2.DR.BYTE = 0x0;        // PORT2 bit0,1,2,3 = "0"
    PORT2.DDR.BYTE = 0x07;      // PORT2 bit0,1,2���o�͂ɐݒ�
    PORT2.ICR.BYTE = 0x18;      // PORT2 bit3,4���̓o�b�t�@�L��

    /*-------------- �߰�3�̐ݒ� ------------------*/
                    // P30 :	in (MTCLKD-A)
                    // P31 :	in (MTCLKC-A)
                    // P32 :	in (MTCLKB-A)
                    // P33 :	in (MTCLKA-A)
 
    PORT3.ICR.BYTE = 0x0f;          // ���̓o�b�t�@�L��

	/* ------------- �߰�5 �̐ݒ� ---------------- */
                    // P50 :    in (SW2-4)
                    // P51 :    in (SW2-8)
                    // P52 :    in (SW3-1)
                    // P53 :    in (SW3-2)
                    // P54 :    in (SW3-4)
                    // P55 :    in (SW3-8)
 
    PORT5.ICR.BYTE = 0x3f;        // ���̓o�b�t�@�L��

	/* ------------- �߰�6 �̐ݒ� ---------------- */
                    // P60 :    in (SW1-1)
                    // P61 :    in (SW1-2)
                    // P62 :    in (SW1-4)
                    // P63 :    in (SW1-8)
                    // P64 :    in (SW2-1)
                    // P65 :    in (SW2-2)
                    
    PORT6.ICR.BYTE = 0x3f;       // ���̓o�b�t�@�L��
    

	/* ------------- �߰�7 �̐ݒ� ---------------- */
                    // P70 :    out (LED_POWER)
                    // P71 :    MTIOC3B
                    // P72 :    MTIOC4A
                    // P73 :    MTIOC4B(���j�^1�pPWM)
                    // P74 :    MTIOC3D
                    // P75 :    MTIOC4C
                    // P76 :    out (LED_INP)

    PORT7.DR.BYTE = 0x41;       // �S�Ă�LED OFF
    PORT7.DDR.BYTE = 0x41;

	/* ------------- �߰�8 �̐ݒ� ---------------- */
                    // P80 :    RXD2
                    // P81 :    TXD2
                    // P82 :    out (485_DE)
    PORT8.ICR.BIT.B0 = 1;		// bit0�̓����ޯ̧��L���ɂ���
    PORT8.DR.BIT.B2 = 0;        //485_DE Disable
    PORT8.DDR.BYTE = 0x4;
    
	/* ------------- �߰�9 �̐ݒ� ---------------- */
    
                    // P90 :    out (LED_ALARM)
                    // P91 :    MTIOC7C
                    // P92 :    MTIOC6D
                    // P93 :    MTIOC7B(���j�^2�pPWM)
                    // P94 :    MTIOC7A
                    // P95 :    MTIOC6B
                    // P96 :    out (BRAKE_OFFn)

    PORT9.DR.BYTE = 0x41;       // LED_INP = OFF BRAKE = ON
    PORT9.DDR.BYTE = 0x41;
    
	/* ------------- �߰�A �̐ݒ� ---------------- */
 
                    // PA0 :    in (IN1)
                    // PA1 :    in (IN2)
                    // PA2 :    in (IN3)
                    // PA3 :    in (IN4)
                    // PA4 :    in (IN5)
                    // PA5 :    in (IN6)
 
    PORTA.ICR.BYTE = 0x3f;      // ���̓o�b�t�@�L��

	/* ------------- �߰�B �̐ݒ� ---------------- */
                    // PB0 :    MTIOC0D(HMC411_CLK 25MHz)
                    // PB1 :    RXD0
                    // PB2 :    TXD0
                    // PB3 :    out (OUT3)
                    // PB4 :    out (OUT4)
                    // PB5 :    out (OUT5)
                    // PB6 :    out (OUT6)
                    // PB7 :    out (OUT7) 

    PORTB.DR.BYTE = 0;        // �o�͂͑S��"0"    
    PORTB.DDR.BYTE = 0xf8;  

	/* ------------- �߰�D �̐ݒ� ---------------- */
                    // PD0 :    RSPCK
                    // PD1 :    MISO
                    // PD2 :    MOSI
                    // PD5 :    RXD1
    
    PORTD.ICR.BIT.B1 = 1;               // bit1�̓����ޯ̧��L���ɂ���
    PORTD.ICR.BIT.B5 = 1;				// bit5�̓����ޯ̧��L���ɂ���

	/* ------------- �߰�E �̐ݒ� ---------------- */
                    // PE0 :    out (HMC411_RESET*)
                    // PE1 :    out (TP1)
                    // PE2 :    NMI
                    // PE3 :    out (TP2)
                    // PE4 :    out (NC)
                    // PE5 :    out (HMC411_CS*)
    PORTE.DR.BIT.B0 = 1;        // HMC411 ���Z�b�g����
    PORTE.DR.BIT.B1 = 0;
    PORTE.DR.BIT.B3 = 0;
    PORTE.DR.BIT.B5 = 1;
    PORTE.DDR.BYTE = 0x3b;
    
// ========================= SCI0������ ===============================
// ********************************************************************
// *                         FTDI:�������� 19200,8,0,1                *
// ********************************************************************
//	sci0_init(2,19200,8,0,1);			// ����������
/*	
	SYSTEM.MSTPCRB.BIT.MSTPB31 = 0;		// SCI0Ӽޭ�ٽį�ߏ�Ԃ̉���
	PORTB.ICR.BIT.B1 = 1;				// ICR register for RxD0 
	SCI0.SCR.BYTE = 0;					// SCR�̏�����
	SCI0.SMR.BYTE = 0;					// �ر�Ӱ��ڼ޽� = 0
	SCI0.SEMR.BIT.ABCS = 0;				// ���������I���N���b�N
	SCI0.SEMR.BIT.NFEN = 1;				// �m�C�Y�����@�\�L��
//	SCI0.BRR = 80;						// �r�b�g���[�g = ((P��*2)/64)/81 = 19290pps
	SCI0.BRR =							// �r�b�g���[�g = ((P��*2)/64)/81 = 19290pps
		((12500000 * 4) / (16 * 19200) + 1) / 2 - 1;
	for(i=0;i<100;i++) ;    			// Wait 1bit(51��s)
	//	�n�[�h�E�F�A�}�j���A���Q��
	//		11.2.2 ���荞�ݗv�������W�X�^m�iIERm�j�im=02h �` 1Fh�j
	//		11.3.1 ���荞�݂̃x�N�^�e�[�u��
	ICU.IER[0x1a].BIT.IEN6 = 1;			// ERI0���荞�݋���
	ICU.IER[0x1a].BIT.IEN7 = 1;			// RXI0���荞�݋���
	ICU.IER[0x1b].BIT.IEN0 = 1;			// TXI0���荞�݋���
	ICU.IER[0x1b].BIT.IEN1 = 1;			// TEI0���荞�݋���
	ICU.IPR[0x80].BIT.IPR = 10 ;		// SCI0���荞������ = 10
	// �����݋���
	SCI0.SCR.BYTE  = 0xF4;				//��M���싖��,���M���싖��,RXI�����ERI�����v������
										//TXI�����v������,TEI�����v������
*/

// ========================= SCI1������ ===============================
// ********************************************************************
// *                           �f�o�b�O�p                             *
// ********************************************************************
/*
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;		// SCI1Ӽޭ�ٽį�ߏ�Ԃ̉���
	SCI1.SCR.BYTE = 0;					// SCR�̏�����
	SCI1.SEMR.BIT.ABCS = 0;				// ���������I���N���b�N
	SCI1.SEMR.BIT.NFEN = 1;				// �m�C�Y�����@�\�L��
	SCI1.SMR.BYTE = 0 ;					// �ر�Ӱ��ڼ޽� = 0
	SCI1.BRR = 80;						// ���ڰ� = ((P��*2)/64)/81 = 19290pps
	for(i=0;i<100;i++) ;    			// Wait 1bit(51��s)
	SCI1.SCR.BYTE = 0x70;				// �رٺ��۰�ڼ޽� = 01110000
										// ����M�C�l�[�u��
										// RXI���荞�݋���
	ICU.IPR[0x81].BIT.IPR = 10 ;		// SCI1���荞������ = 10
	ICU.IER[0x1b].BIT.IEN2 = 1;			// ERI1���荞�݋���
	ICU.IER[0x1b].BIT.IEN3 = 1;			// RXI1���荞�݋���

	rp = rbuf ;							// �߲��������
*/
// ======================== SCI2 ������ ================================
// *********************************************************************
// *						RS485�p:�������� 19200,8,0,1				*
// *********************************************************************
//	sci2_init(2,19200,8,0,1);			// ����������
/*	
	SYSTEM.MSTPCRB.BIT.MSTPB29 = 0;		// SCI1Ӽޭ�ٽį�ߏ�Ԃ̉���
	IOPORT.PFFSCI.BIT.SCI2S = 1;		// P80��RXD2B�AP81��TXD2B�[�q�Ƃ��Ďg�p
	SCI2.SCR.BYTE = 0;					// SCR�̏�����
	SCI2.SEMR.BIT.ABCS = 0;				// ���������I���N���b�N
	SCI2.SEMR.BIT.NFEN = 1;				// �m�C�Y�����@�\�L��
	SCI2.SMR.BYTE = 0 ;					// �ر�Ӱ��ڼ޽� = 0
	SCI2.BRR = 80;						// ���ڰ� = ((P��*2)/64)/81 = 19290pps
	for(i=0;i<100;i++) ;    			// Wait 1bit(51��s)
	SCI2.SCR.BYTE = 0x70;				// �رٺ��۰�ڼ޽� = 01110000
										// ����M�C�l�[�u��
										// RXI���荞�݋���
	ICU.IPR[0x82].BIT.IPR = 10 ;		// SCI2���荞������ = 10
	ICU.IER[0x1b].BIT.IEN6 = 1;			// ERI2���荞�݋���
	ICU.IER[0x1b].BIT.IEN7 = 1;			// RXI2���荞�݋���
	ICU.IER[0x1c].BIT.IEN0 = 1;			// TXI2���荞�݋���
	ICU.IER[0x1c].BIT.IEN1 = 1;			// TEI2���荞�݋���

	rp = rbuf ;							// �߲��������
*/	


// ========================== CMT0������ ====================================
// **************************************************************************
// *                   1msec �^�C�}�[(�ʒu�E���x���Z�p)                     *
// **************************************************************************
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;		// CMT0,CMT1Ӽޭ�ٽį�߉���
	CMT0.CMCNT = 0;						// CMT0�J�E���^�N���A
	CMT0.CMCR.BIT.CKS = 0;				// PCLK/8=50000/8=6250
	CMT0.CMCR.BIT.CMIE = 1;				// ���߱ϯ��ɂ�銄�荞�݋���
	CMT0.CMCOR = 6249;					// ���߱ϯ����� = 1ms��2013/9/12
	//CMT0.CMCOR = 12499;					// ���߱ϯ����� = 2ms
//	ICU.IPR[4].BIT.IPR = 14;			// ���荞������=14
	ICU.IPR[4].BIT.IPR = 13;			// ���荞������=13
	ICU.IER[3].BIT.IEN4 = 1;			// CMT0���荞�݋���
	CMT.CMSTR0.BIT.STR0 = 1;			// CMT0���Ľ���

}
