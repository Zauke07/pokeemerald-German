#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

void CB2_InitMainMenu(void);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);
void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId);
void AddBirchSpeechObjects(u8 taskId);

#endif // GUARD_MAIN_MENU_H
