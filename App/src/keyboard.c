#include "keyboard.h"
#include "usbd_hid.h"
#include "main.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

void Keyboard_Send(uint8_t *hid_data){
	USBD_HID_SendReport(&hUsbDeviceFS,hid_data,8);
}

void Keyboard_Clear(){
	uint8_t null[8] = {0};
	USBD_HID_SendReport(&hUsbDeviceFS,null,8);
}

void Keyboard_OneTime(uint8_t *hid_data, uint32_t time){
	Keyboard_Send(hid_data);
	HAL_Delay(time);
	Keyboard_Clear();
}

uint8_t Keyboard_AsciiToHid(const char ascii){
	if(ascii >='a' && ascii <= 'z')
		return ascii-93;
	if(ascii >='A' && ascii <= 'Z')
		return ascii-61;
	if(ascii == '0')
		return Keyboard_0;
	if(ascii >='1' && ascii <= '9')
		return ascii-19;
	return 0;
}
