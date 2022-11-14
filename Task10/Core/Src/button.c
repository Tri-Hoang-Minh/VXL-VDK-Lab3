/*
 * button.c
 *
 *  Created on: Oct 31, 2022
 *      Author: Hoang Tri
 */
#include "button.h"

int button1_flag= 0;
int button2_flag=0;
int button3_flag=0;
int KeyReg0= NORMAL_STATE;  // 1
int KeyReg1= NORMAL_STATE;  // 1
int KeyReg2= NORMAL_STATE;  // 1
int KeyReg3= NORMAL_STATE;  // 1
int TimerForKeyPress_1=0;  // setTimer();
int TimerForKeyPress_2=0;  // setTimer();
int TimerForKeyPress_3=0;  // setTimer();

int KeyReg4= NORMAL_STATE;  // 1
int KeyReg5= NORMAL_STATE;  // 1
int KeyReg6= NORMAL_STATE;  // 1
int KeyReg7= NORMAL_STATE;  // 1


int KeyReg8= NORMAL_STATE;   // 1
int KeyReg9= NORMAL_STATE;   // 1
int KeyReg10= NORMAL_STATE;  // 1
int KeyReg11= NORMAL_STATE;  // 1


int flag_change_state_button1=0;
int flag_change_state_button2= 0;
int flag_change_state_button3= 0;


int isButton1Pressed()
{
	 if(button1_flag==1)
	 {
		 button1_flag=0;
		 return 1;
	 }
	 return 0;
}
int isButton2Pressed()
{
	 if(button2_flag==1)
	 {
		 button2_flag=0;
		 return 1;
	 }
	 return 0;
}
int isButton3Pressed()
{
	 if(button3_flag==1)
	 {
		 button3_flag=0;
		 return 1;
	 }
	 return 0;
}
void subKeyProcess1()
{
	button1_flag=1;
}
void subKeyProcess2()
{
	button2_flag=1;
}
void subKeyProcess3()
{
	button3_flag=1;
}
void getKeyInput()
{
   KeyReg0=KeyReg1;
   KeyReg1=KeyReg2;
   KeyReg2=HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
   if((KeyReg0==KeyReg1) && (KeyReg1==KeyReg2))
   {
         if(KeyReg3 != KeyReg2)  // Nhan tha
         {
        	 KeyReg3 = KeyReg2;
        	 if(KeyReg2==PRESSED_STATE)
        	 {
        		    //TODO
          		 if(flag_change_state_button1==0)
          		 {
              		 subKeyProcess1();
              		 TimerForKeyPress_1=250;
          		 }
          		 else if(flag_change_state_button1==1)
          		 {
          			subKeyProcess1();
          			TimerForKeyPress_1=250;
          		 }

        	 }
        	 else
        	 {
        		 flag_change_state_button1=0;
        		 TimerForKeyPress_1=250;
        	 }
         }
         else
         {
        	 TimerForKeyPress_1--;
        	 if(TimerForKeyPress_1==0)
        	 {
        		 KeyReg3=NORMAL_STATE;  // 1
        		 TimerForKeyPress_1=250;
        		 flag_change_state_button1=1;
        	 }
         }
   }
     KeyReg4=KeyReg5;   // NORMAL_STATE  //1
     KeyReg5=KeyReg6;   // NORMAL_STATE  //1
     KeyReg6=HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin); // state1= 1= normal
     if((KeyReg4==KeyReg5) && (KeyReg5==KeyReg6))  // NORMAL
     {
           if(KeyReg7 != KeyReg6)  // Nhan tha
           {
          	 KeyReg7 = KeyReg6;  // KeyReg3 = NORMAL
          	 if(KeyReg6==PRESSED_STATE)   // PRESSED_STATE = 0: LED_ON
          	 {
          		    //TODO
          		 if(flag_change_state_button2==0)
          		 {
              		 subKeyProcess2();
              		 TimerForKeyPress_2=250;
          		 }
          		 else if(flag_change_state_button2==1)
          		 {
          			subKeyProcess2();
          			TimerForKeyPress_2=250;
          		 }
          	 }
          	 else
          	 {
          		flag_change_state_button2=0;
          		TimerForKeyPress_2=250;

          	 }
           }
           else  // KeyREg3= KeyReg2
           {
          	 TimerForKeyPress_2--;
          	 if(TimerForKeyPress_2==0)
          	 {
          		 KeyReg7=NORMAL_STATE;  // 1
          		 TimerForKeyPress_2=250;
          		 flag_change_state_button2 =1;
          	 }
           }
     }
          KeyReg8=KeyReg9;   // NORMAL_STATE  //1
          KeyReg9=KeyReg10;   // NORMAL_STATE  //1
          KeyReg10=HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
          if((KeyReg8==KeyReg9) && (KeyReg9==KeyReg10))  // NORMAL
          {
                if(KeyReg11 != KeyReg10)  // Nhan tha
                {
               	 KeyReg11 = KeyReg10;  // KeyReg3 = NORMAL
               	 if(KeyReg10==PRESSED_STATE)   // PRESSED_STATE = 0: LED_ON
               	 {
               		    //TODO
              		 if(flag_change_state_button3==0)
              		 {
                  		 subKeyProcess3();
                  		 TimerForKeyPress_3=250;
              		 }
              		 else if(flag_change_state_button3==1)
              		 {
              			subKeyProcess3();
              			TimerForKeyPress_3=250;
              		 }
               	 }
               	 else
               	 {
               		TimerForKeyPress_3=250;
               		flag_change_state_button3=0;
               	 }
                }
                else   // KeyREg3= KeyReg2
                {
               	  TimerForKeyPress_3--;
               	 if(TimerForKeyPress_3 == 0)
               	 {
               		 KeyReg11=NORMAL_STATE;  // 1
               		 TimerForKeyPress_3=250;
               		flag_change_state_button3 =1;
               	 }
                }
          }
}







