/*********************************************************
     +---------------------------------------------+
     |��Ȥ����       ԭ������    �๦����תPOV LED |
     +---------------------------------------------+	   

 ��Դ���Ȩ�� ��Ȥ���� ȫȨ���У��������ã�������������֪
        �Ͻ�����������ҵĿ�ģ�Υ�߱ؾ�������Ը�
        ��Ȥ���� 
         ->��Ʒ��ѯ QQ:1327074668 MSN:zhiqudz@163.com
		 ->��Ʒ���� http://58788771.taobao.com/
	                Tel:18106718021
	 /*********************************************/
	 /*	�� Ŀ:	ƽ��/����/��ɫ/�๦����תPOV LED  */
	 /*	ģ �飺	��ʱ��ģ��						  */
	 /*	�� �ܣ�	��ʱ��0����ʱ��1��׼ʱ��		  */
	 /*	�� ����	V3.0							  */
	 /*	�� �ƣ�	ZhiQu Studio					  */
	 /*	ʱ �䣺	2013��7��5��					  */
	 /*	�� ��:	2013.7.5.19:00 ������Ŀ			  */
	 /*	˵ ����	����MCU STC115F08S2  			  */		 
	 /*********************************************/	  
/*********************************************************/
#include "Time.h"



//===============��ʱ����ʼ������==================//
void Time_init(void)
{
	 AUXR=0XD5;	//����T0 1Tģʽ, ģʽ����ģʽΪ12T, ����ʹ���ڲ�RAM,�������������ʷ�������
			    // b7       b6       b5       b4      b3     b2     b1     b0
			    //t0x12   t1x12    uart_m0x6  TR2   T2/CT   T2X12 EXTRAM  SIST2       
			    //	1        1		  0		   1	   0	  1	   	 0      1
				//SIST2   ��ʱ��2�Ƿ���������1�Ĳ����ʷ�����  
				//EXTRAM  �ڲ�/�ⲿRAM��ȡ����	 0�����ڲ�RAM��ȡ��
				//T2x12    ��ʱ��2ʱ��ģʽ
				//T2/CT    ��ʱ��2������ʱ���Ǽ�����
				//TR2      ��ʱ��2��������
				
				
	 TMOD=0X00; //��ʱ��0������ʽ1,/��ʱ��1������ʽ2,8λ�Զ���װ��
			    //   b7   b6   b5  b4  b3   b2  b1   b0/
			    //  GATE  C/T  M1   M0 GATE	C/T M1   M0
			    //    0	  0	   1	0	0	 0	 0	 1

	 /*
	 IT0=1;			 //���ж�0������ʽ,Ϊ1ʱΪ�½�����Ч,Ϊ0ʱ�͵�ƽ��Ч
	 IT1=1;           //���ж�1������ʽ, Ϊ1ʱΪ�½�����Ч,Ϊ0ʱ�͵�ƽ��Ч
 	 EX0=1;			 //���ж�0ʹ�ܱ�־
	 EX1=1;			 //���ж�1ʹ�ܱ�־
	 EA=1;	    //�����жϣ�
	 */
	 TL0 = 0xD4;		//���ö�ʱ��ֵ	 1MS
	 TH0 = 0xCD;		//���ö�ʱ��ֵ
	 //TL1 = 0xF8;		//���ö�ʱ��ֵ	 255us
	 //TH1 = 0xE9;		//���ö�ʱ��ֵ
	 TL1 = 0x33;		//���ö�ʱ��ֵ	 125us
	 TH1 = 0xF5;		//���ö�ʱ��ֵ
	 TR1 = 1;		    //������ʱ��1

 	 TR0 = 1;		    //�򿪶�ʱ��0
	 TL0 = 0xD4;		//���ö�ʱ��ֵ	 1MS
	 TH0 = 0xCD;		//���ö�ʱ��ֵ
	 //TR1 =0;		    //�ض�ʱ��1
	 //TR0 =0;		    //�ض�ʱ��0
	 ET0 = 1;		    //��ʱ��0�ж�ʹ��,Ϊ1ʱ��,Ϊ0ʱ��
	 ET1 = 1;		    //��ʱ��1�ж�ʹ��,Ϊ1ʱ��,Ϊ0ʱ��
	 //ET0 = 0;		    //��ʱ��0�ж�ʹ��,Ϊ1ʱ��,Ϊ0ʱ��
	 //ET1 = 0;		    //��ʱ��1�ж�ʹ��,Ϊ1ʱ��,Ϊ0ʱ��		 
}
/****************************************************************
����������ʱ��0�жϷ�����  �жϺ�:1 ;
��  �ã���
��  ������
����ֵ����
��  �ܣ��ṩÿ����ʾλ�������ʱ��;
��  ע����ʱ��0,������ʽ1,16λ��ʱ�� 1Tģʽ, ��ʱ153us
/****************************************************************/

void timer0(void)   interrupt 1   using 1
{
//    TR0=0;
//	Time0_flag=1;	           //��ʱ�жϱ�־λ��1;
//	TH0=-Pt/256;TL0=-Pt%256;   //���ö�ʱ��T0�ĳ���ֵ

                       //����
//	TR0=1;
}

/****************************************************************
����������ʱ��1�жϷ�����  �жϺ�:3 ;
��  �ã���
��  ������
����ֵ����
��  �ܣ��ṩ��ʾλ�������ʱ��;
��  ע����ʱ��1,������ʽ0,16λ�Զ���װ�� 1Tģʽ, ��ʱ125us
/****************************************************************/

void timer1(void)   interrupt 3   using 2
{
//	uint s,j,k,n;
//	s++; irtime++;	j++; n++;		//	second,minute,hour

}
	