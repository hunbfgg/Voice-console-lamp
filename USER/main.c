#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "timer.h"
#include "string.h"

/////////////////////////////////////



////////////////////////////////////
u8 Res;
u8 receive_data[10];

int main(void)
{	 
	u8 flag1=0;
	u8 flag2=0;
	u16 pwmval=180;
	u16 pwmva2=180;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为115200
	uart3_init(9600);
 	LED_Init();			     //LED端口初始化		 	
	TIM3_PWM_Init(200,7199);	 //不分频。PWM频率=72000000/7200=10Khz  0.1ms 周期20ms
//	Timer_TIM3_Init(10,7199);
	TIM_SetCompare2(TIM3,180);	 //1.5ms  90度
	TIM_SetCompare4(TIM3,180);	 //1.5ms	90度
	delay_ms(990);	
	LED0=1;
	
	while(1)
	{	
		if(Res =='1')//01灯已下降  
		{
			if(pwmval<=180)
			{
				pwmval+=5;
			}
			TIM_SetCompare2(TIM3,pwmval);
			Res ='7';
			
		}

		if(Res =='2') //02灯已上升  
		{
			if(pwmval>=180)
			{
				pwmval-=5;
			}
			TIM_SetCompare2(TIM3,pwmval);
			Res ='7';
		}

		if(Res =='3') //03灯已左转
		{

			if(pwmva2<=180)
			{
				pwmva2+=5;
			}
			TIM_SetCompare4(TIM3,pwmva2);
			Res ='7';
		}
  
		if(Res =='4')//04灯已右转  
		{

			if(pwmva2>=180)
			{
				pwmva2-=5;
			}
			TIM_SetCompare4(TIM3,pwmva2);
			Res ='7';
		}
 
		if(Res =='5')
		{

			LED0=1;
		}

		if(Res =='6')
		{

			LED0=0;
		}

	}
}

