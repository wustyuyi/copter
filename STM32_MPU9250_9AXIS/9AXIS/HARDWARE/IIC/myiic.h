#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h"
 
/**************************接口配置*****************************/ 
#if 0
	#define _RCC_GPIOX_APB2PERIPH		RCC_APB2Periph_GPIOB
	#define _IIC_SCL_PIN 			    GPIO_Pin_6
	#define _IIC_SDA_PIN  				GPIO_Pin_7
	#define _IIC_PORT	  				GPIOB	

	#define _MPU6050_INT  				GPIO_Pin_3
	#define _MPU6050_PORT 				GPIOB	
	 //IO方向设置 		 
	#define SDA_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=0X80000000;}//将CRH12-15bit清零
	#define SDA_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=0X30000000;}
	 
	#define IIC_SCL    PBout(6) //SCL->PB6
	#define IIC_SDA    PBout(7) //SDA	->PB7
	#define READ_SDA   PBin(7)  //输入SDA 
#else
	#define _RCC_GPIOX_APB2PERIPH		RCC_APB2Periph_GPIOA
	#define _IIC_SCL_PIN 			    GPIO_Pin_2
	#define _IIC_SDA_PIN  				GPIO_Pin_1
	#define _IIC_PORT	  				GPIOA	

	#define _MPU6050_INT  				GPIO_Pin_1
	#define _MPU6050_PORT 				GPIOB	
	 //IO方向设置 		 
	#define SDA_IN()  {_IIC_PORT->CRL&=0XFFFFFF0F;_IIC_PORT->CRL|=0X00000080;}//
	#define SDA_OUT() {_IIC_PORT->CRL&=0XFFFFFF0F;_IIC_PORT->CRL|=0X00000030;}
	 
	#define IIC_SCL    PAout(2) //SCL->PB6
	#define IIC_SDA    PAout(1) //SDA	->PB7
	#define READ_SDA   PAin(1)  //输入SDA 
#endif
/*****************************************************************/
//IIC所有操作函数声明
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t  IIC_Read_Byte(unsigned char ack);//IIC读取一个字节并且用ack表示是否产生应答信号
uint8_t  IIC_Wait_Ack(void); 			//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void MPU6050_Register_Configuration(void);
uint8_t IIC_ReadOneByte(uint8_t SlaveAddr ,uint8_t ReadAddr);							//指定器件指定地址读取一个字节
void IIC_WriteOneByte(uint8_t SlaveAddr, uint8_t WriteAddr,uint8_t DataToWrite);		//指定器件指定地址写入一个字节
void IIC_ReadmultiyBytes(uint8_t SlaveAddr,uint8_t RegAddr,uint8_t Len,uint8_t *Buf_Addr);
/*void WriteLenByte(u16 WriteAddr,u32 DataToWrite,u8 Len);//指定地址开始写入指定长度的数据
u32 ReadLenByte(u16 ReadAddr,u8 Len);					//指定地址开始读取指定长度数据
void Write(u16 WriteAddr,u8 *pBuffer,u16 NumToWrite);	//从指定地址开始写入指定长度的数据
void Read(u16 ReadAddr,u8 *pBuffer,u16 NumToRead);   	//从指定地址开始读出指定长度的数据
*/
#endif
















